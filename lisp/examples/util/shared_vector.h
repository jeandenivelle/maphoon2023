
#pragma once

#include <stdexcept>
#include <iostream>
#include <cstring>
#include <list>
#include <vector>

namespace util
{

template <typename D>
class shared_vector
{
   template <size_t s>
   struct shared
   {
      size_t refcounter;
      D data[s];
   };

   size_t _size;
   size_t _capacity;

   shared<1> * onheap;

   // Destroy the elements in the range [ d1, d2 ).

   inline static void destroy_range( D* d1, D* d2 )
   {
      // std::cout << "destroying " << ( d2 - d1 ) << " elements\n";

      static_assert( std::is_nothrow_destructible<D>::value,
                     "Type for shared_vector must not throw at destruction");

      if constexpr ( !std::is_trivially_destructible<D>::value )
      {
         while( d2 > d1 )
         {
            --d2;
            d2 -> ~D();
         }
      }
   }

   // Copy our data into new_heap. If this results in 
   // an exception, we clean up the elements, and
   // deallocate new_heap. We do this here, because otherwise one would
   // have to catch the exception somewhere else, and rethrow
   // it. 

   inline void copy_into( shared<1> *new_heap ) const 
   {
      // std::cout << "copying into " << new_heap << "\n";

      size_t i = 0;
      try
      {
         while( i < _size )
         {
            new (new_heap->data + i) D( onheap->data[i] );
            ++i;
         }
      }
      catch (...)
      {
         destroy_range( new_heap->data, new_heap->data + i );
         operator delete( new_heap );
         throw;
      }
      // std::cout << "copied into\n";
   }

   
   inline void move_into( shared<1> *new_heap )
   {
      // If D allows noexcept moving, we prefer that:

      if constexpr( std::is_nothrow_move_constructible<D>::value )
      {
         for( size_t i = 0; i < _size; ++ i )
            new (new_heap->data + i) D( std::move(onheap->data[i] ));
      }
      else
         copy_into( new_heap );

      destroy_range( onheap->data, onheap->data + _size );
   }

public:
   static constexpr size_t allocsize( size_t ss )
   {
      return std::max(sizeof(size_t), alignof(D)) + ss * sizeof(D);
   }

   shared_vector() noexcept
       : _size(0),
         _capacity(0),
         onheap(nullptr)
   {
   }

   // We do not need to deallocate new elements, because default 
   // constructor is called,
   // and thus destructor will be called when exiting try block.

   shared_vector( size_t s, D d )
       : shared_vector()
   {
      reserve(s);

      while( _size < s )
      {
         new ( onheap->data + _size ) D(d);
         ++ _size;
      }
   }

   // this almost completely replicates shared_vector(size_t, D).
   // The reason why we have two functions is that it uses the default 
   // constructor for every element, instead of constructing 
   // a single default element and making many copies of it.

   explicit shared_vector( size_t s )
       : shared_vector()
   {
      reserve(s);

      while( _size < s ) 
      {
         new (onheap->data + _size ) D();
         ++ _size; 
      }
   }

   void reserve( size_t new_capacity )
   {
      if( new_capacity > _capacity )
      {
         // std::cout << "reserving " << new_capacity << "\n";
         shared<1> *new_heap =
             static_cast<shared<1> *>(operator new(allocsize(new_capacity)));

         if( onheap )
         {
            // std::cout << "onheap " << isshared( ) << "\n";
            if( !isshared())
            {
               move_into( new_heap );
               operator delete( onheap );
            }   
            else
            {
               copy_into( new_heap );
               -- onheap -> refcounter;
            }
         }

         _capacity = new_capacity;
         onheap = new_heap;
         onheap->refcounter = 1;
      }
   }

   shared_vector(const shared_vector &other)
       : _size(other._size),
         _capacity(other._capacity),
         onheap(other.onheap)
   {
      if (other.onheap)
         ++ ( other.onheap->refcounter ) ;
   }

   shared_vector(std::initializer_list<D> init)
       : shared_vector( init.begin(), init.end())
   { }

   template <typename ForwardIterator>
   shared_vector( ForwardIterator i0, ForwardIterator i1 ) : shared_vector{}
   {
      if( i1 - i0 > _capacity ) 
         reserve( i1 - i0 );
      else
         make_not_shared( );

      while( i0 != i1 )
      {
         new (onheap->data + _size) D( *i0 );
         ++_size;
         ++ i0;
      }
   }

   void push_back( const D& d )
   {
      // The call to reserve is guaranteed to reallocate,
      // so certainly we are not shared after that. 

      if (_size == _capacity)
         reserve( _capacity ? _capacity * 2 : 1 );
      else
         make_not_shared();

      new (onheap->data + _size) D(d);
      ++_size;
   }

   void push_back( D&& d )
   {
      if( _size == _capacity )
         reserve( _capacity ? _capacity * 2 : 1 );
      else
         make_not_shared();

      new (onheap->data + _size) D(std::move(d));
      ++_size;
   }

   void pop_back()
   {
      make_not_shared();

      --_size;
      (onheap->data + _size)-> ~D();
   }

   void clear()
   {
      if( onheap )
      {
         make_not_shared();
         destroy_range( onheap -> data, onheap -> data + _size );      
      }

      _size = 0;
   }

   // Print with internals:

   void printstatistics( std::ostream &out ) const
   {
      out << "capacity = " << _capacity << "\n";
      out << "data =     " << onheap << "\n";
      out << "refs =     " << getrefcounter( ) << "\n";
   }


   void make_not_shared()
   {
      if( onheap && onheap->refcounter > 1 )
      {
         shared<1> *new_onheap =
             static_cast<shared<1> *>(operator new(allocsize(_capacity)));

         copy_into( new_onheap );

         -- onheap -> refcounter; 

         // We are not changing _size and _capacity.

         onheap = new_onheap;
         onheap-> refcounter = 1;
      }
   }


   bool isshared() const
   {
      return onheap->refcounter > 1;
   }

   const D &front() const { return onheap->data[0]; }
   const D &back() const { return onheap->data[ _size - 1 ]; }

   size_t size() const { return _size; }

   using const_iterator = const D*;
   const_iterator begin() const { return onheap->data; }
   const_iterator end() const { return onheap->data + _size; }

   const D& operator[]( size_t i ) const { return onheap->data[i]; }
   const D& at( size_t i ) const
   {
      if( i >= _size )
         throw std::out_of_range( "shared_vector::at" );
      return onheap->data[i];
   }

   // We don't check that *this[i] != d, because is no generic
   // way of doing that for every type D. 

   D& set( size_t i, const D& d )
   {
      make_not_shared( ); 
      return ( onheap -> data[i] = d );
   }

   shared_vector& operator= ( const shared_vector& other )
   {
      *this = shared_vector( other );
      return *this;
   }

   shared_vector& operator= ( shared_vector&& other )
   {
      std::swap( _size, other._size );
      std::swap( _capacity, other._capacity );
      std::swap( onheap, other.onheap );
      return *this;
   }

   ~shared_vector()
   {
      if( onheap && ( --onheap->refcounter ) == 0 )
      {
         destroy_range( onheap->data, onheap->data + _size );
         operator delete( onheap );
      }
   }

   // For curiosity only:

   size_t getrefcounter( ) const
   {
      if( onheap )
         return onheap -> refcounter;
      else
         return 0;
   }

   // True if we are shared with other:

   bool sharedwith( const shared_vector& other ) const 
   {
      return onheap && onheap == other. onheap;
   }
};

}


