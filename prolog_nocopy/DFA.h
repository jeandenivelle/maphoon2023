
// Automatically generated code:
// Generator written by Hans de Nivelle and Dina Muktubayeva.

namespace prolog
{
   template< typename S >
   std::pair< symboltype, size_t > readandclassify( int triv, S& inp )
   {
      auto latest = std::make_pair< symboltype, size_t > ( sym_ERROR, 0 );
      if( !inp. has(1))
         return latest;
      char c = inp. peek(0);
      size_t i = 0;

   Q00:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 32:
         ++ i; goto Q01;
      case 33:
      case 36:
      case 38:
      case 92:
      case 94:
         ++ i; goto Q02;
      case 34:
         ++ i; goto Q03;
      case 35:
         ++ i; goto Q04;
      case 37:
         ++ i; goto Q05;
      case 39:
         ++ i; goto Q06;
      case 40:
         ++ i; goto Q07;
      case 41:
         ++ i; goto Q08;
      case 44:
         ++ i; goto Q09;
      case 47:
         ++ i; goto Q10;
      case 48:
         ++ i; goto Q11;
      case 95:
         ++ i; goto Q13;
      case 91:
         ++ i; goto Q14;
      case 93:
         ++ i; goto Q15;
      case 96:
         ++ i; goto Q16;
      }
      if( c >= 58 )
      {
         if( c >= 97 )
         {
            if( c >= 127 ) return latest;
            if( c >= 123 ) { ++ i; goto Q02; }
            if constexpr( true ) { ++ i; goto Q17; }
         }
         else
         {
            if( c >= 65 ) { ++ i; goto Q13; }
            if constexpr( true ) { ++ i; goto Q02; }
         }
      }
      else
      {
         if( c >= 14 )
         {
            if( c >= 49 ) { ++ i; goto Q12; }
            if( c >= 42 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 9 ) { ++ i; goto Q01; }
            if constexpr( true ) return latest;
         }
      }
   Q01:
      latest. first = sym_WHITESPACE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 32 ) { ++ i; goto Q01; }
      if( c >= 14 ) return latest;
      if( c >= 9 ) { ++ i; goto Q01; }
      if constexpr( true ) return latest;
   Q02:
      latest. first = sym_IDENTIFIER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
         ++ i; goto Q02;
      case 34:
      case 37:
      case 44:
         return latest;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) return latest;
            if( c >= 123 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q02; }
            if( c >= 65 ) return latest;
            if constexpr( true ) { ++ i; goto Q02; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) return latest;
            if( c >= 42 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
      }
   Q03:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 34 ) { ++ i; goto Q18; }
      if( c == 92 ) { ++ i; goto Q19; }
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q03; }
   Q04:
      latest. first = sym_EOF; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
         ++ i; goto Q02;
      case 34:
      case 37:
      case 44:
         return latest;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) return latest;
            if( c >= 123 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q02; }
            if( c >= 65 ) return latest;
            if constexpr( true ) { ++ i; goto Q02; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) return latest;
            if( c >= 42 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
      }
   Q05:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) { ++ i; goto Q20; }
      if constexpr( true ) { ++ i; goto Q05; }
   Q06:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 39 ) { ++ i; goto Q18; }
      if( c == 92 ) { ++ i; goto Q21; }
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q06; }
   Q07:
      latest. first = sym_LPAR; latest. second = i;
      return latest;
   Q08:
      latest. first = sym_RPAR; latest. second = i;
      return latest;
   Q09:
      latest. first = sym_IDENTIFIER; latest. second = i;
      return latest;
   Q10:
      latest. first = sym_IDENTIFIER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
      case 43:
         ++ i; goto Q02;
      case 42:
         ++ i; goto Q22;
      case 34:
      case 37:
      case 44:
         return latest;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) return latest;
            if( c >= 123 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q02; }
            if( c >= 65 ) return latest;
            if constexpr( true ) { ++ i; goto Q02; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) return latest;
            if( c >= 45 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
      }
   Q11:
      latest. first = sym_INTEGER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 46 ) { ++ i; goto Q23; }
      if( c == 69 || c == 101 ) { ++ i; goto Q24; }
      if constexpr( true ) return latest;
   Q12:
      latest. first = sym_INTEGER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 46:
         ++ i; goto Q23;
      case 69:
      case 101:
         ++ i; goto Q24;
      case 47:
         return latest;
      }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q12; }
      if constexpr( true ) return latest;
   Q13:
      latest. first = sym_VARIABLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q13; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q13; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q13; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q13; }
         if constexpr( true ) return latest;
      }
   Q14:
      latest. first = sym_LSQBRACKET; latest. second = i;
      return latest;
   Q15:
      latest. first = sym_RSQBRACKET; latest. second = i;
      return latest;
   Q16:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 96 ) { ++ i; goto Q18; }
      if( c == 92 ) { ++ i; goto Q25; }
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q16; }
   Q17:
      latest. first = sym_IDENTIFIER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 95 ) { ++ i; goto Q17; }
      if( c == 96 ) return latest;
      if( c >= 65 )
      {
         if( c >= 123 ) return latest;
         if( c >= 97 ) { ++ i; goto Q17; }
         if( c >= 91 ) return latest;
         if constexpr( true ) { ++ i; goto Q17; }
      }
      else
      {
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q17; }
         if constexpr( true ) return latest;
      }
   Q18:
      latest. first = sym_QUOTEDIDENTIFIER; latest. second = i;
      return latest;
   Q19:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q03; }
   Q20:
      latest. first = sym_COMMENT; latest. second = i;
      return latest;
   Q21:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q06; }
   Q22:
      latest. first = sym_IDENTIFIER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
      case 43:
         ++ i; goto Q22;
      case 34:
      case 37:
      case 44:
         ++ i; goto Q26;
      case 42:
         ++ i; goto Q27;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) { ++ i; goto Q26; }
            if( c >= 123 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q22; }
            if( c >= 65 ) { ++ i; goto Q26; }
            if constexpr( true ) { ++ i; goto Q22; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) { ++ i; goto Q26; }
            if( c >= 45 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
      }
   Q23:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q28; }
      if constexpr( true ) return latest;
   Q24:
      latest. first = sym_DOUBLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 43 || c == 45 ) { ++ i; goto Q29; }
      if( c == 44 ) return latest;
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q30; }
      if constexpr( true ) return latest;
   Q25:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 10 ) return latest;
      if constexpr( true ) { ++ i; goto Q16; }
   Q26:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 42 ) { ++ i; goto Q31; }
      if constexpr( true ) { ++ i; goto Q26; }
   Q27:
      latest. first = sym_IDENTIFIER; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
      case 43:
         ++ i; goto Q22;
      case 34:
      case 37:
      case 44:
         ++ i; goto Q26;
      case 42:
         ++ i; goto Q27;
      case 47:
         ++ i; goto Q32;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) { ++ i; goto Q26; }
            if( c >= 123 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q22; }
            if( c >= 65 ) { ++ i; goto Q26; }
            if constexpr( true ) { ++ i; goto Q22; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) { ++ i; goto Q26; }
            if( c >= 45 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q22; }
            if constexpr( true ) { ++ i; goto Q26; }
         }
      }
   Q28:
      latest. first = sym_DOUBLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 69 || c == 101 ) { ++ i; goto Q24; }
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q28; }
      if constexpr( true ) return latest;
   Q29:
      latest. first = sym_DOUBLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q30; }
      if constexpr( true ) return latest;
   Q30:
      latest. first = sym_DOUBLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q33; }
      if constexpr( true ) return latest;
   Q31:
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c == 47 ) { ++ i; goto Q20; }
      if( c == 42 ) { ++ i; goto Q31; }
      if constexpr( true ) { ++ i; goto Q26; }
   Q32:
      latest. first = sym_COMMENT; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      switch( c )
      {
      case 33:
      case 38:
         ++ i; goto Q02;
      case 34:
      case 37:
      case 44:
         return latest;
      }
      if( c >= 58 )
      {
         if( c >= 95 )
         {
            if( c >= 127 ) return latest;
            if( c >= 123 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 91 ) { ++ i; goto Q02; }
            if( c >= 65 ) return latest;
            if constexpr( true ) { ++ i; goto Q02; }
         }
      }
      else
      {
         if( c >= 39 )
         {
            if( c >= 48 ) return latest;
            if( c >= 42 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
         else
         {
            if( c >= 35 ) { ++ i; goto Q02; }
            if constexpr( true ) return latest;
         }
      }
   Q33:
      latest. first = sym_DOUBLE; latest. second = i;
      if( !inp. has(i+1))
         return latest;
      c = inp. peek(i);
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q34; }
      if constexpr( true ) return latest;
   Q34:
      latest. first = sym_DOUBLE; latest. second = i;
      return latest;
   }
}

