
// Parser generated by Maphoon 2022.
// Written by Hans de Nivelle, March 2021-May 2022.
// See the licence that was included with the code.

#include "parser.h"

namespace prolog { 

#line 54 "grammar.m"
 

namespace
{

   bool canbeprefix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be prefix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );
      return syntdefs. hasprefixdef(s); 
   }

   bool canbeinfix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be infix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );    
      return syntdefs. hasinfixdef(s); 
   } 

   bool canbepostfix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be postfix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );    
      return syntdefs. haspostfixdef(s);
   } 

   bool canstartterm( const symbol& sym )
   {
      std::cout << "can start term " << sym << "\n";
      return sym.type == sym_IDENTIFIER ||
             sym.type == sym_GLUEDIDENTIFIER ||
             sym.type == sym_QUOTEDIDENTIFIER ||
             sym.type == sym_GLUEDQUOTEDIDENTIFIER || 
             sym.type == sym_LPAR ||
             sym.type == sym_LSQBRACKET ||
             sym.type == sym_VARIABLE ||
             sym.type == sym_INTEGER ||
             sym.type == sym_DOUBLE;
   }

   short int canreduce( const syntax& syntdefs,
                        const opdef& op, const symbol& sym )
   {
      std::cout << "deciding priorities between " << op << " and " << sym << "\n";
      if( sym. type != sym_IDENTIFIER )
         return 1;   // reduce.

      const std::string& str = sym. get< std::string > ( );

      // We do not really know what to do when there are
      // conflicting priorities. I suppose it should not happen. 

      if( syntdefs. haspostfixdef( str ))
      { 
         auto op2 = syntdefs. postfixdef( str );
         auto dir = op. decide( op2 );
         if( dir == -1 ) return 1;
         if( dir == 1 ) return 0;
         return -1;
      }

      if( syntdefs. hasinfixdef( str )) 
      { 
         auto op2 = syntdefs. infixdef( str );
         auto dir = op. decide( op2 );
         if( dir == -1 ) return 1;
         if( dir == 1 ) return 0;
         return -1;
      }

      return 1;
   }
}

}

#line 207 "idee.x"


size_t 
prolog::parser::statesymbol::hash::operator( ) ( const statesymbol& ss ) const
{
   // After some trying, and looking at the distribution in the map,
   // this gives decent results:

   auto s = ss. state;
   auto t = ss. type;
   size_t h = s + 41 * t + t * t; 
   h ^= ( h >> 7 );
   return h;
}

bool
prolog::parser::statesymbol::equal_to::operator( ) ( const statesymbol& ss1,
                                                            const statesymbol& ss2 ) const
{
   return ss1. state == ss2. state && ss1. type == ss2. type;
}


// Definitions of the reduction functions:

auto prolog::parser::body1( ) -> term
{
#line 148 "grammar.m"
 timetosaygoodbye = true; return std::move((topsymbol(1).get<term>())); }

auto prolog::parser::body2( ) -> term
{
#line 151 "grammar.m"
 return new variable((topsymbol(1).get<std::string>())); }

auto prolog::parser::body3( ) -> term
{
#line 153 "grammar.m"
 return new constant< double > ((topsymbol(1).get<double>())); }

auto prolog::parser::body4( ) -> term
{
#line 155 "grammar.m"
 return new constant< bigint > ((topsymbol(1).get<bigint>())); }

auto prolog::parser::body5( ) -> term
{
#line 157 "grammar.m"
 return new functional( function( (topsymbol(1).get<std::string>()), 0 )); }

auto prolog::parser::body6( ) -> term
{
#line 159 "grammar.m"
 return new functional( function( (topsymbol(1).get<std::string>()), 0 )); }

auto prolog::parser::body7( ) -> term
{
#line 162 "grammar.m"
 size_t ar = (topsymbol(2).get<std::vector<term>>()). size( );
        return new functional( function( (topsymbol(4).get<std::string>()), ar ), std::move( (topsymbol(2).get<std::vector<term>>()) ));
      }

auto prolog::parser::body8( ) -> term
{
#line 167 "grammar.m"
 size_t ar = (topsymbol(2).get<std::vector<term>>()). size( );
        return new functional( function( (topsymbol(4).get<std::string>()), ar ), std::move( (topsymbol(2).get<std::vector<term>>()) ));
      }

short prolog::parser::cond9( ) const
{
#line 173 "grammar.m"
 return canreduce( syntdefs, (topsymbol(2).get<opdef>()), getlookahead( )); }

auto prolog::parser::body9( ) -> term
{
#line 175 "grammar.m"
 return new functional( function( (topsymbol(2).get<opdef>()). str, 1 ), std::move((topsymbol(1).get<term>())) ); }

short prolog::parser::cond10( ) const
{
#line 179 "grammar.m"
 return canreduce( syntdefs, (topsymbol(2).get<opdef>()), getlookahead( )); }

auto prolog::parser::body10( ) -> term
{
#line 181 "grammar.m"
 return new functional( function( (topsymbol(2).get<opdef>()). str, 2 ), std::move((topsymbol(3).get<term>())), std::move((topsymbol(1).get<term>())) ); }

auto prolog::parser::body11( ) -> term
{
#line 185 "grammar.m"
 return new functional( function( (topsymbol(1).get<opdef>()). str, 1 ), std::move((topsymbol(2).get<term>())) ); }

auto prolog::parser::body12( ) -> term
{
#line 187 "grammar.m"
 return std::move((topsymbol(2).get<term>())); }

auto prolog::parser::body13( ) -> term
{
#line 190 "grammar.m"
 auto res = std::move( (topsymbol(2).get<term>()) );
     size_t i = (topsymbol(3).get<std::vector<term>>()). size( );
     while( i -- )
        res = new functional( list. cons, std::move( (topsymbol(3).get<std::vector<term>>())[i] ), std::move( res ));
     return std::move( res );    
   }

auto prolog::parser::body14( ) -> std::vector<term>
{
#line 199 "grammar.m"
 return std::vector<term> ( );         /* empty rhs. */  }

auto prolog::parser::body15( ) -> std::vector<term>
{
#line 200 "grammar.m"
 return std::move((topsymbol(1).get<std::vector<term>>())); }

short prolog::parser::cond16( ) const
{
#line 206 "grammar.m"
 return !canbeinfix( syntdefs, lookahead. value( )) &&
            !canbepostfix( syntdefs, lookahead. value( )); 
   }

auto prolog::parser::body16( ) -> std::vector<term>
{
#line 210 "grammar.m"
 auto res = std::vector< term > ( ); res. push_back( std::move((topsymbol(1).get<term>()))); return res; }

short prolog::parser::cond17( ) const
{
#line 215 "grammar.m"
 return !canbeinfix( syntdefs, lookahead. value( )) &&
            !canbepostfix( syntdefs, lookahead. value( )); 
   }

auto prolog::parser::body17( ) -> std::vector<term>
{
#line 219 "grammar.m"
 (topsymbol(3).get<std::vector<term>>()). push_back( std::move( (topsymbol(1).get<term>()) )); return std::move( (topsymbol(3).get<std::vector<term>>()) ); }

auto prolog::parser::body18( ) -> term
{
#line 223 "grammar.m"
 return new functional( list. nil ); }

auto prolog::parser::body19( ) -> term
{
#line 225 "grammar.m"
 return std::move((topsymbol(1).get<term>())); }

short prolog::parser::cond20( ) const
{
#line 230 "grammar.m"
 return syntdefs. hasprefixdef( (topsymbol(1).get<std::string>()) ) && canstartterm( lookahead. value( )); }

auto prolog::parser::body20( ) -> opdef
{
#line 232 "grammar.m"
 return syntdefs. prefixdef((topsymbol(1).get<std::string>())); }

short prolog::parser::cond21( ) const
{
#line 237 "grammar.m"
 return syntdefs. hasinfixdef((topsymbol(1).get<std::string>())) && canstartterm( lookahead. value( )); }

auto prolog::parser::body21( ) -> opdef
{
#line 239 "grammar.m"
 return syntdefs. infixdef((topsymbol(1).get<std::string>())); }

short prolog::parser::cond22( ) const
{
#line 244 "grammar.m"
 return syntdefs. haspostfixdef((topsymbol(1).get<std::string>())); }

auto prolog::parser::body22( ) -> opdef
{
#line 246 "grammar.m"
 return syntdefs. postfixdef((topsymbol(1).get<std::string>())); }



#line 1 "reduce"

void prolog::parser::reduce( prolog::symboltype lefttype,
               prolog::symbol::attrtype&& attr, size_t rightsize )
{
   if( debug >= 2 )
   {
      std::cout << "popping " << rightsize << " state(s) and symbol(s) "; 
      std::cout << "from the stack and reducing into " << lefttype << "\n";
   }

#if false
   // This works only if symbol has an info type: 

   std::optional< prolog::symbol::infotype > info;
      // For the first stack entry that has an info, we move it into here. 
      // For later stack entries that have an info, we merge them
      // with the first info. The idea is that info has set semantics. 

   for( auto p = symbolstack. end( ) - rightsize; 
        p != symbolstack. end( ); ++ p ) 
   {
      // If we encounter first defined, we move into info. 
      // 

      if( p -> info. has_value( )) 
      {
         if( info. has_value( ))
            info.value( ). merge( std::move( p -> info.value() ));
         else
            info = std::move( p -> info );
      }
   }
#endif 

   while( rightsize )
   {
      statestack. pop_back( );
      symbolstack. pop_back( );
      -- rightsize; 
   }
  
   // It remains to do the goto: 

   statestack. push_back( shifts. at( { statestack. back( ), lefttype } ));

#if false
   symbolstack. emplace_back( lefttype, info, std::move( attr ));
#else
   symbolstack. emplace_back( lefttype, std::move( attr ));
#endif 
}

#line 1 "parse"

prolog::symbol 
prolog::parser::parse( prolog::symboltype startsym )
{
   if( debug )
      std::cout << "Starting parser:\n";

   if( checkmovable ) 
   {
      if( ! std::is_nothrow_move_constructible<prolog::symbol> :: value )
      {
         std::cout << "class symbol is not nothrow move constructible\n";
         std::cout << "   (this causes loss of efficiency)\n"; 
         if( checkmovable > 1 )
            throw std::runtime_error( "because of this I stop" );
      }
      else
      {
         std::cout << "class symbol is nothrow move constructible\n";
         std::cout << "   (that is good)\n";
      }
   }

   if( debug >= 1 && 
          startsymbols. find( startsym ) == startsymbols. end( ))
   {
      std::cout << "startsymbol " << startsym << " is not a start symbol\n";
   }

   if( debug >= 1 && haslookahead( ))
      std::cout << "starting with lookahead = " << getlookahead( ) << "\n";

   const auto& startinfo = startsymbols. at( startsym );
   statestack. push_back( startinfo. first );
  
mainloop: 
   if( debug >= 1 ) 
      print( std::cout ); 

   if( timetosaygoodbye )
   {
      if( debug >= 2 ) 
         std::cout << "time to say goodbye!\n";

      prolog::symbol res = std::move( symbolstack. back( ));
      symbolstack. pop_back( );
      statestack. pop_back( );
      return res; 
   }
 
   size_t shift = reductioninfo. size( );  // Means undefined. 
   std::vector< size_t > redcandidates;

   const auto& redinfo = reductioninfo[ statestack. back( ) ]; 

   // If the state is non-trivial, we need a lookahead:

   if( redinfo. first != 'T' ) 
      ensurelookahead( ); 

   if( debug >= 3 && haslookahead( ))
      std::cout << "lookahead " << getlookahead( ) << "\n";

   switch( redinfo. first ) 
   {
   case 'N': 
   {
      auto p = shifts. find( 
               statesymbol( statestack.back( ), getlookahead( ). type ));
      if( p != shifts. end( ))
         shift = p -> second;
      break;
   }
   case 'D':
   {
      auto p = shifts. find(
               statesymbol( statestack.back( ), getlookahead( ). type ));
      if( p != shifts. end( ))
         shift = p -> second;
      else
         redcandidates. push_back( redinfo. second ); 
      break;
   }
   case 'H':
   {
      auto p = shifts. find(
               statesymbol( statestack. back( ), getlookahead( ). type ));
      if( p != shifts. end( ))
         shift = p -> second; 
     
      auto q = reductions. find( 
               statesymbol( statestack. back( ), getlookahead( ). type ));
      if( q != reductions. end( ))
         redcandidates = q -> second; 
      break;
   }
   case 'T':
      redcandidates. push_back( redinfo. second );
      break;   
   default:
      std::cout << redinfo.first << "\n";
      throw std::logic_error( "reduction info not recognized" );
   }
  
   if( debug >= 3 )
   { 
      if( shift != reductioninfo. size( ))
         std::cout << "shift candidate " << shift << "\n";

      if( redcandidates. size( )) 
      {
         std::cout << "reduction candidates: "; 
         for( size_t i = 0; i != redcandidates. size( ); ++ i )
            std::cout << redcandidates[i] << " ";
         std::cout << "\n";
      }
      else
         std::cout << "there are no reduction candidates\n";
   }

   // We need to find a reduction that agrees to be reduced.
   // After a reduction, we goto mainloop; 

   for( const auto& r : redcandidates ) 
   {
      if( debug >= 3 ) 
         std::cout << "trying to reduce rule " << r << "\n";

      switch(r)
      {
      case 0:
         reduce( prolog::sym_Start, std::monostate( ), 2 );
         goto mainloop;
         break;
      case 1:
         reduce( prolog::sym_OneTerm, body1( ), 1 );
         goto mainloop;
         break;
      case 2:
         reduce( prolog::sym_Term, body2( ), 1 );
         goto mainloop;
         break;
      case 3:
         reduce( prolog::sym_Term, body3( ), 1 );
         goto mainloop;
         break;
      case 4:
         reduce( prolog::sym_Term, body4( ), 1 );
         goto mainloop;
         break;
      case 5:
         reduce( prolog::sym_Term, body5( ), 1 );
         goto mainloop;
         break;
      case 6:
         reduce( prolog::sym_Term, body6( ), 1 );
         goto mainloop;
         break;
      case 7:
         reduce( prolog::sym_Term, body7( ), 4 );
         goto mainloop;
         break;
      case 8:
         reduce( prolog::sym_Term, body8( ), 4 );
         goto mainloop;
         break;
      case 9:
         if( short s = cond9(); s > 0 )
         {
            reduce( prolog::sym_Term, body9( ), 2 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 10:
         if( short s = cond10(); s > 0 )
         {
            reduce( prolog::sym_Term, body10( ), 3 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 11:
         reduce( prolog::sym_Term, body11( ), 2 );
         goto mainloop;
         break;
      case 12:
         reduce( prolog::sym_Term, body12( ), 3 );
         goto mainloop;
         break;
      case 13:
         reduce( prolog::sym_Term, body13( ), 4 );
         goto mainloop;
         break;
      case 14:
         reduce( prolog::sym_MaybeTerms, body14( ), 0 );
         goto mainloop;
         break;
      case 15:
         reduce( prolog::sym_MaybeTerms, body15( ), 1 );
         goto mainloop;
         break;
      case 16:
         if( short s = cond16(); s > 0 )
         {
            reduce( prolog::sym_SomeTerms, body16( ), 1 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 17:
         if( short s = cond17(); s > 0 )
         {
            reduce( prolog::sym_SomeTerms, body17( ), 3 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 18:
         reduce( prolog::sym_ListEnd, body18( ), 0 );
         goto mainloop;
         break;
      case 19:
         reduce( prolog::sym_ListEnd, body19( ), 2 );
         goto mainloop;
         break;
      case 20:
         if( short s = cond20(); s > 0 )
         {
            reduce( prolog::sym_Prefix, body20( ), 1 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 21:
         if( short s = cond21(); s > 0 )
         {
            reduce( prolog::sym_Infix, body21( ), 1 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
      case 22:
         if( short s = cond22(); s > 0 )
         {
            reduce( prolog::sym_Postfix, body22( ), 1 );
            goto mainloop;
         }
         else
            if( s < 0 ) shift = reductioninfo. size( );
         break;
 
      default:
         throw std::logic_error( "reducing unknown rule" );  
      }
   }

   if( shift < reductioninfo. size( ))
   {
      if( debug >= 2 ) 
         std::cout << "shifting S" << shift << "\n";

      if( checkattrtypes )
      {
         if( !lookahead. value( ). has_correct_attribute( ))
         {
            std::cout << "\n";
            std::cout << "tokenizer created symbol with incorrect attribute:\n";
            std::cout << "   " << lookahead. value( ) << "\n\n";

            if( checkattrtypes >= 2 )
               throw std::logic_error( "stopping because of this" ); 
         } 
      }

      statestack. push_back( shift );
      symbolstack. push_back( std::move( lookahead. value( )));
      resetlookahead( ); 

      if( timesincelasterror < 99999999 )
         ++ timesincelasterror; 

      goto mainloop;
   }

   // We accept if the stack consists of exactly the start symbol, 
   // and we have no lookahead or the lookahead is a terminator.

   if( symbolstack. size( ) == 1 &&
       symbolstack. front( ). type == startsym &&
          ( !haslookahead( ) ||
            startinfo. second. count( getlookahead( ). type )))
   {
      if( debug >= 2 ) 
         std::cout << "we accept the input\n";

      prolog::symbol res = std::move( symbolstack. front( ));
      return res;
   }

#line 1 "startpoint"

   syntaxerror( ); 
   if( timesincelasterror < maxrecovery ) 
   {
      if( debug >= 2 )
         std::cout << "trying to recover\n";

      if( debug >= 2 )
         std::cout << "time since last error = " << timesincelasterror << "\n";

      std::vector< std::pair< size_t, size_t >> shiftrecover; 
         // We collect the levels whose state can shift the  _recover_ 
         // symbol, 
         // combined with the states that will be reached after the shifts.

      for( size_t level = 0; level != statestack. size( ); ++ level )
      {
         size_t s = statestack[ level ];

         if( reductioninfo[s]. first == 'N' ||
             reductioninfo[s]. first == 'D' ||
             reductioninfo[s]. first == 'H' )
         {
            auto p = shifts. find( statesymbol( s, prolog::sym__recover_ ));
            if( p != shifts. end( ))
               shiftrecover. push_back( std::pair( level, p -> second ));
         }
      } 

      if( debug >= 1 )
      { 
         std::cout << "possible shifts after the _recover_ symbol: {";
         for( auto p = shiftrecover. begin( ); p != shiftrecover. end( ); ++ p )
         {
            if( p != shiftrecover. begin( ))
               std::cout << ", ";
            else
               std::cout << " ";
            std::cout << ( p -> first ) << "/S" << ( p -> second );
         }
         std::cout << " }\n";
      }

      if( shiftrecover. size( ) == 0 )
      {
         if( debug >= 1 )
         {
            std::cout << "no recovering shifts found\n";
            if( haslookahead( ))
               std::cout << getlookahead( ) << "\n";
            else
               std::cout << "(there is no lookahead)\n"; 
         }

         return recover_symbol( ); 
      }

      if( debug >= 2 ) 
         std::cout << "lookahead = " << getlookahead( ) << "\n";

      // As long as we have patience left, and the lookahead is not
      // in the terminator set, we try to recover: 
 
      while( timesincelasterror < maxrecovery && 
             startinfo. second. count( getlookahead( ). type ) == 0 )
      {
         // We look in shiftrecover for the highest level on
         // which we could shift current lookahead after shifting the 
         // _recover_ symbol. 

         size_t rec = shiftrecover. size( ); 
         while( rec != 0 ) 
         { 
            -- rec; 
            size_t s = shiftrecover[ rec ]. second; 
            
            if( reductioninfo[s]. first == 'N' ||
                reductioninfo[s]. first == 'D' ||
                reductioninfo[s]. first == 'H' )
            {
               auto after = shifts. find( 
                      statesymbol( s, getlookahead( ). type ));

               if( after != shifts. end( ))
               {
                  if( debug >= 2 )
                  {
                     std::cout << rec << " is candidate\n";
                     std::cout << "recovery will be into state ";
                     std::cout << after -> second << "\n";
                  }

                  while( statestack. size() > shiftrecover[ rec ]. first + 1 )
                  {
                     statestack. pop_back( );
                     symbolstack. pop_back( );  
                  } 
                  
                  statestack. push_back(s);
                  symbolstack. push_back( recover_symbol( ));

                  statestack. push_back( after -> second );
                  symbolstack. push_back( std::move( lookahead. value( ) ));

                  lookahead. reset( );

                  if( debug >= 2 ) 
                  {
                     std::cout <<  "recovery complete" << "\n";
                  }
                  timesincelasterror = 0;
                  goto mainloop; 
               } 
            }
         }

         // We throw away the current lookahead,
         // and increase the time since the last error. 
 
         if( debug >= 1 ) 
         {
            std::cout << "not yet recovered, time since last error = ";
            std::cout << timesincelasterror << "\n";
         }
         lookahead. reset( ); 
         ensurelookahead( );  

         if( timesincelasterror < 99999999 )
            ++ timesincelasterror; 
      }
   }

   // That's it. Game over. We lost.

   if( debug )
   {
      if( timesincelasterror < maxrecovery ) 
         std::cout << "reached a terminator\n";
      else
         std::cout << "recovery ran out of patience\n";
   }

#if false
   return prolog::symbol( prolog::sym__recover_,
                  std::optional< prolog::symbol::infotype > ( ) );
#else
   return prolog::symbol( prolog::sym__recover_ );
#endif

}


prolog::symbol prolog::parser::recover_symbol( ) 
{
#if false
   return prolog::symbol( prolog::sym__recover_,
                  std::optional< prolog::symbol::infotype > ( ));
#else
   return prolog::symbol( prolog::sym__recover_ );
#endif
}


size_t 
prolog::parser::match( const expectation& exp ) const
{
   size_t stackpos = symbolstack. size( );
   size_t triggerpos = exp. trigger. size( );
      // Both use predecrement consistently.

   while( triggerpos )
   {
      -- triggerpos;

      size_t skipped = 0;

   loop:
      // It is possible to write this with a while loop, but
      // the result looks terrible.

      if( stackpos == 0 || skipped > exp. trigger[ triggerpos ]. maxskip )
         return symbolstack. size( ) + 1;

      -- stackpos;
      if( !exp. trigger[ triggerpos ]. set. contains( 
                    symbolstack[ stackpos ]. type ))
      {
         ++ skipped;
         goto loop;
      }
   }

   return stackpos;
}


#if ! false 

void
prolog::parser::syntaxerror( )
{
   if( timesincelasterror + 1 <= maxtrialperiod )
   {
      timesincelasterror = 0;
      return;
   }

   size_t bestpos = symbolstack. size( ) + 1;
   auto besterror = errormessages. end( );

   for( auto p = errormessages. begin( ); p != errormessages. end( ); ++ p )
   {
      size_t pos = match(*p);
      if( pos < bestpos )
      {
         bestpos = pos;
         besterror = p;
      }
   }

   if( bestpos <= symbolstack. size( ))
   {
      std::cout << "expected " << ( besterror -> expected );
      if( haslookahead( ))
      {
         std::cout << " instead of " << getlookahead( ). type;
      }
   }
   else
   {
      if( haslookahead( ))
         std::cout << "unexpected " << getlookahead( ). type;
      else
         std::cout << "syntax error";
   }

#if false
   // If symbols have location information, we try to extract a location.
   // We first check lookahead, then backwards on the parse stack, for
   // the first symbol that has location information.

   std::optional< prolog::symbol::infotype > info;
   if( haslookahead( ))
      info = getlookahead( ). info;

   auto p = symbolstack. end( );
   while( p != symbolstack. begin( ) && !info. has_value( ))
   {
      -- p;
      if( p -> info. has_value( ))
         info = p -> info;
   }

   if( info. has_value( ))
      std::cout << " at position " << info. value( );
#endif

   std::cout << "\n";
   timesincelasterror = 0; 
}

#endif


void
prolog::parser::reset( )
{
   if( debug >= 1 )
      std::cout << "Resetting parser\n";

   statestack. clear( );
   symbolstack. clear( );

   if( debug >= 1 && haslookahead( ))
      std::cout << "lookahead still contains " << getlookahead( ) << "\n";

   timetosaygoodbye = false;
}


void 
prolog::parser::print( std::ostream& out ) const
{
   out << "Statestack: ";
   for( auto s : statestack )
      out << "S" << s << " ";
   out << "\n";

   out << "Symbolstack: ";
   for( const auto& s : symbolstack )
      out << s << "   ";
   out << "\n";
   if( timesincelasterror < 1000 )
      out << "last error was " << timesincelasterror << " symbols ago\n";

}

const std::unordered_map< prolog::symboltype, std::pair< size_t, std::unordered_set< prolog::symboltype >>> prolog::parser::startsymbols =
{
   { prolog::sym_Start, { 0, { prolog::sym_EOF }} }
};

const std::vector< std::pair< char, size_t >> prolog::parser::reductioninfo =
{
   { 'N', 0 }, { 'T', 6 }, { 'N', 0 }, { 'D', 1 }, { 'N', 0 }, { 'D', 14 }, { 'N', 0 }, { 'N', 0 },
   { 'T', 2 }, { 'N', 0 }, { 'H', 0 }, { 'T', 4 }, { 'T', 3 }, { 'N', 0 }, { 'H', 0 }, { 'N', 0 },
   { 'T', 11 }, { 'H', 0 }, { 'D', 18 }, { 'D', 16 }, { 'D', 15 }, { 'D', 14 }, { 'T', 0 }, { 'D', 14 },
   { 'T', 12 }, { 'H', 0 }, { 'N', 0 }, { 'N', 0 }, { 'N', 0 }, { 'N', 0 }, { 'N', 0 }, { 'D', 19 },
   { 'T', 13 }, { 'D', 17 }, { 'T', 8 }, { 'T', 7 }, { 'N', 0 }
};

const prolog::parser::statesymbol::map< size_t > prolog::parser::shifts =
{
   { { 33, prolog::sym_Infix }, 15 }, { { 33, prolog::sym_Postfix }, 16 }, { { 31, prolog::sym_IDENTIFIER }, 14 }, { { 31, prolog::sym_Infix }, 15 }, { { 30, prolog::sym_RPAR }, 35 },
   { { 28, prolog::sym_DOUBLE }, 12 }, { { 28, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 28, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 15, prolog::sym_VARIABLE }, 8 }, { { 13, prolog::sym_RPAR }, 24 },
   { { 0, prolog::sym_DOUBLE }, 12 }, { { 26, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 9, prolog::sym_LPAR }, 23 }, { { 21, prolog::sym_INTEGER }, 11 }, { { 5, prolog::sym_INTEGER }, 11 },
   { { 13, prolog::sym_Infix }, 15 }, { { 5, prolog::sym_MaybeTerms }, 18 }, { { 5, prolog::sym_Term }, 19 }, { { 5, prolog::sym_DOUBLE }, 12 }, { { 15, prolog::sym_Term }, 25 },
   { { 13, prolog::sym_Postfix }, 16 }, { { 19, prolog::sym_Infix }, 15 }, { { 5, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 31, prolog::sym_Postfix }, 16 }, { { 6, prolog::sym_LPAR }, 21 },
   { { 3, prolog::sym_IDENTIFIER }, 14 }, { { 7, prolog::sym_TERMINATOR }, 22 }, { { 33, prolog::sym_IDENTIFIER }, 14 }, { { 28, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 4, prolog::sym_DOUBLE }, 12 },
   { { 20, prolog::sym_COMMA }, 28 }, { { 28, prolog::sym_LSQBRACKET }, 5 }, { { 5, prolog::sym_SomeTerms }, 20 }, { { 4, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 2, prolog::sym_IDENTIFIER }, 10 },
   { { 23, prolog::sym_MaybeTerms }, 30 }, { { 26, prolog::sym_IDENTIFIER }, 10 }, { { 4, prolog::sym_LSQBRACKET }, 5 }, { { 4, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 0, prolog::sym_QUOTEDIDENTIFIER }, 1 },
   { { 2, prolog::sym_LSQBRACKET }, 5 }, { { 28, prolog::sym_VARIABLE }, 8 }, { { 0, prolog::sym_Term }, 3 }, { { 15, prolog::sym_IDENTIFIER }, 10 }, { { 0, prolog::sym_LPAR }, 2 },
   { { 4, prolog::sym_Prefix }, 4 }, { { 0, prolog::sym_INTEGER }, 11 }, { { 5, prolog::sym_LSQBRACKET }, 5 }, { { 0, prolog::sym_Prefix }, 4 }, { { 23, prolog::sym_QUOTEDIDENTIFIER }, 1 },
   { { 0, prolog::sym_Start }, 36 }, { { 26, prolog::sym_Term }, 31 }, { { 0, prolog::sym_OneTerm }, 7 }, { { 21, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 0, prolog::sym_GLUEDIDENTIFIER }, 9 },
   { { 28, prolog::sym_Term }, 33 }, { { 0, prolog::sym_VARIABLE }, 8 }, { { 0, prolog::sym_IDENTIFIER }, 10 }, { { 2, prolog::sym_VARIABLE }, 8 }, { { 5, prolog::sym_LPAR }, 2 },
   { { 4, prolog::sym_VARIABLE }, 8 }, { { 21, prolog::sym_MaybeTerms }, 29 }, { { 5, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 2, prolog::sym_Prefix }, 4 }, { { 21, prolog::sym_QUOTEDIDENTIFIER }, 1 },
   { { 5, prolog::sym_Prefix }, 4 }, { { 15, prolog::sym_Prefix }, 4 }, { { 5, prolog::sym_IDENTIFIER }, 10 }, { { 2, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 3, prolog::sym_Infix }, 15 },
   { { 5, prolog::sym_VARIABLE }, 8 }, { { 21, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 2, prolog::sym_Term }, 13 }, { { 2, prolog::sym_LPAR }, 2 }, { { 0, prolog::sym_LSQBRACKET }, 5 },
   { { 15, prolog::sym_INTEGER }, 11 }, { { 2, prolog::sym_INTEGER }, 11 }, { { 28, prolog::sym_IDENTIFIER }, 10 }, { { 2, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 0, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 },
   { { 2, prolog::sym_DOUBLE }, 12 }, { { 21, prolog::sym_Prefix }, 4 }, { { 4, prolog::sym_IDENTIFIER }, 10 }, { { 15, prolog::sym_GLUEDIDENTIFIER }, 9 }, { { 15, prolog::sym_LSQBRACKET }, 5 },
   { { 15, prolog::sym_DOUBLE }, 12 }, { { 15, prolog::sym_LPAR }, 2 }, { { 15, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 21, prolog::sym_SomeTerms }, 20 }, { { 21, prolog::sym_DOUBLE }, 12 },
   { { 4, prolog::sym_LPAR }, 2 }, { { 4, prolog::sym_Term }, 17 }, { { 25, prolog::sym_Postfix }, 16 }, { { 17, prolog::sym_IDENTIFIER }, 14 }, { { 17, prolog::sym_Infix }, 15 },
   { { 18, prolog::sym_ListEnd }, 27 }, { { 18, prolog::sym_BAR }, 26 }, { { 19, prolog::sym_IDENTIFIER }, 14 }, { { 15, prolog::sym_QUOTEDIDENTIFIER }, 1 }, { { 21, prolog::sym_LSQBRACKET }, 5 },
   { { 21, prolog::sym_Term }, 19 }, { { 21, prolog::sym_IDENTIFIER }, 10 }, { { 21, prolog::sym_VARIABLE }, 8 }, { { 13, prolog::sym_IDENTIFIER }, 14 }, { { 26, prolog::sym_GLUEDIDENTIFIER }, 9 },
   { { 21, prolog::sym_LPAR }, 2 }, { { 23, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 23, prolog::sym_LPAR }, 2 }, { { 26, prolog::sym_Prefix }, 4 }, { { 23, prolog::sym_LSQBRACKET }, 5 },
   { { 23, prolog::sym_Term }, 19 }, { { 23, prolog::sym_IDENTIFIER }, 10 }, { { 29, prolog::sym_RPAR }, 34 }, { { 26, prolog::sym_DOUBLE }, 12 }, { { 23, prolog::sym_GLUEDIDENTIFIER }, 9 },
   { { 2, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 25, prolog::sym_IDENTIFIER }, 14 }, { { 23, prolog::sym_SomeTerms }, 20 }, { { 3, prolog::sym_Postfix }, 16 }, { { 25, prolog::sym_Infix }, 15 },
   { { 4, prolog::sym_INTEGER }, 11 }, { { 23, prolog::sym_VARIABLE }, 8 }, { { 23, prolog::sym_INTEGER }, 11 }, { { 19, prolog::sym_Postfix }, 16 }, { { 26, prolog::sym_VARIABLE }, 8 },
   { { 23, prolog::sym_DOUBLE }, 12 }, { { 26, prolog::sym_LSQBRACKET }, 5 }, { { 23, prolog::sym_Prefix }, 4 }, { { 26, prolog::sym_LPAR }, 2 }, { { 26, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 },
   { { 26, prolog::sym_INTEGER }, 11 }, { { 17, prolog::sym_Postfix }, 16 }, { { 27, prolog::sym_RSQBRACKET }, 32 }, { { 28, prolog::sym_INTEGER }, 11 }, { { 4, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 },
   { { 28, prolog::sym_Prefix }, 4 }, { { 5, prolog::sym_GLUEDQUOTEDIDENTIFIER }, 6 }, { { 28, prolog::sym_LPAR }, 2 }
};

const prolog::parser::statesymbol::map< std::vector< size_t >> prolog::parser::reductions =
{
   { { 25, prolog::sym_RSQBRACKET }, { 10 } }, { { 25, prolog::sym_RPAR }, { 10 } }, { { 25, prolog::sym_IDENTIFIER }, { 10 } }, { { 25, prolog::sym_ListEnd }, { 10 } },
   { { 17, prolog::sym_COMMA }, { 9 } }, { { 17, prolog::sym_RPAR }, { 9 } }, { { 25, prolog::sym_COMMA }, { 10 } }, { { 17, prolog::sym_Postfix }, { 9 } },
   { { 17, prolog::sym_TERMINATOR }, { 9 } }, { { 14, prolog::sym_QUOTEDIDENTIFIER }, { 21 } }, { { 14, prolog::sym_INTEGER }, { 21 } }, { { 17, prolog::sym_Infix }, { 9 } },
   { { 14, prolog::sym_DOUBLE }, { 21 } }, { { 14, prolog::sym_TERMINATOR }, { 22 } }, { { 14, prolog::sym_Infix }, { 22 } }, { { 17, prolog::sym_RSQBRACKET }, { 9 } },
   { { 17, prolog::sym_BAR }, { 9 } }, { { 10, prolog::sym_GLUEDIDENTIFIER }, { 20 } }, { { 17, prolog::sym_IDENTIFIER }, { 9 } }, { { 14, prolog::sym_GLUEDIDENTIFIER }, { 21 } },
   { { 14, prolog::sym_RPAR }, { 22 } }, { { 10, prolog::sym_RPAR }, { 5 } }, { { 14, prolog::sym_VARIABLE }, { 21 } }, { { 14, prolog::sym_IDENTIFIER }, { 21, 22 } },
   { { 10, prolog::sym_LPAR }, { 20 } }, { { 14, prolog::sym_COMMA }, { 22 } }, { { 10, prolog::sym_Prefix }, { 20 } }, { { 10, prolog::sym_COMMA }, { 5 } },
   { { 14, prolog::sym_LPAR }, { 21 } }, { { 10, prolog::sym_BAR }, { 5 } }, { { 25, prolog::sym_TERMINATOR }, { 10 } }, { { 10, prolog::sym_INTEGER }, { 20 } },
   { { 10, prolog::sym_LSQBRACKET }, { 20 } }, { { 10, prolog::sym_Postfix }, { 5 } }, { { 25, prolog::sym_BAR }, { 10 } }, { { 14, prolog::sym_RSQBRACKET }, { 22 } },
   { { 10, prolog::sym_ListEnd }, { 5 } }, { { 14, prolog::sym_GLUEDQUOTEDIDENTIFIER }, { 21 } }, { { 10, prolog::sym_Infix }, { 5 } }, { { 25, prolog::sym_Postfix }, { 10 } },
   { { 10, prolog::sym_GLUEDQUOTEDIDENTIFIER }, { 20 } }, { { 10, prolog::sym_Term }, { 20 } }, { { 10, prolog::sym_TERMINATOR }, { 5 } }, { { 25, prolog::sym_Infix }, { 10 } },
   { { 10, prolog::sym_RSQBRACKET }, { 5 } }, { { 10, prolog::sym_DOUBLE }, { 20 } }, { { 10, prolog::sym_QUOTEDIDENTIFIER }, { 20 } }, { { 17, prolog::sym_ListEnd }, { 9 } },
   { { 14, prolog::sym_Term }, { 21 } }, { { 14, prolog::sym_ListEnd }, { 22 } }, { { 14, prolog::sym_BAR }, { 22 } }, { { 10, prolog::sym_IDENTIFIER }, { 20, 5 } },
   { { 10, prolog::sym_VARIABLE }, { 20 } }, { { 14, prolog::sym_Prefix }, { 21 } }, { { 14, prolog::sym_Postfix }, { 22 } }, { { 14, prolog::sym_LSQBRACKET }, { 21 } }
};


const std::vector< prolog::parser::expectation > prolog::parser::errormessages =
{

};

