
#ifndef ISHASH_
#define ISHASH_

#include <concepts>

template< typename D, typename H, typename E >
concept ishash = 
requires( D d, H h, E e )
{
   { h(d) } -> std::convertible_to< std::size_t >;
   { e(d,d) } -> std::convertible_to< bool >;
};

#endif

