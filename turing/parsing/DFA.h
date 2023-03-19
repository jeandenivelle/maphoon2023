
// This code was generated automatically.
// Generator written by Hans de Nivelle and Dina Muktubayeva.

namespace parsing
{
   namespace
   {
      template< typename S >
      std::pair< symboltype, size_t > readandclassify( int triv, S& inp )
      {
         auto latest = std::make_pair< symboltype, size_t > ( sym_EMPTY, 0 );
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
         case 9:
         case 32:
            ++ i; goto Q01;
         case 10:
            ++ i; goto Q02;
         case 95:
            ++ i; goto Q03;
         case 37:
            ++ i; goto Q04;
         case 43:
            ++ i; goto Q05;
         case 44:
            ++ i; goto Q06;
         case 45:
            ++ i; goto Q07;
         case 46:
            ++ i; goto Q08;
         case 47:
            ++ i; goto Q09;
         case 96:
            return latest;
         }
         if( c >= 48 )
         {
            if( c >= 91 )
            {
               if( c >= 123 ) return latest;
               if( c >= 97 ) { ++ i; goto Q03; }
               if constexpr( true ) return latest;
            }
            else
            {
               if( c >= 65 ) { ++ i; goto Q03; }
               if( c >= 58 ) return latest;
               if constexpr( true ) { ++ i; goto Q10; }
            }
         }
         else
         {
            if( c >= 14 )
            {
               if( c >= 38 ) return latest;
               if( c >= 35 ) { ++ i; goto Q03; }
               if constexpr( true ) return latest;
            }
            else
            {
               if( c >= 11 ) { ++ i; goto Q01; }
               if constexpr( true ) return latest;
            }
         }
      Q01:
         latest. first = sym_WHITESPACE; latest. second = i;
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 9 || c == 32 ) { ++ i; goto Q01; }
         if( c == 10 ) return latest;
         if( c >= 14 ) return latest;
         if( c >= 11 ) { ++ i; goto Q01; }
         if constexpr( true ) return latest;
      Q02:
         latest. first = sym_NL; latest. second = i;
         return latest;
      Q03:
         latest. first = sym_CHAR; latest. second = i;
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 95 ) { ++ i; goto Q11; }
         if( c == 96 ) return latest;
         if( c >= 58 )
         {
            if( c >= 91 )
            {
               if( c >= 123 ) return latest;
               if( c >= 97 ) { ++ i; goto Q11; }
               if constexpr( true ) return latest;
            }
            else
            {
               if( c >= 65 ) { ++ i; goto Q11; }
               if constexpr( true ) return latest;
            }
         }
         else
         {
            if( c >= 48 ) { ++ i; goto Q11; }
            if( c >= 37 ) return latest;
            if( c >= 35 ) { ++ i; goto Q11; }
            if constexpr( true ) return latest;
         }
      Q04:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         switch( c )
         {
         case 97:
            ++ i; goto Q12;
         case 98:
            ++ i; goto Q13;
         case 101:
            ++ i; goto Q14;
         case 105:
            ++ i; goto Q15;
         case 115:
            ++ i; goto Q16;
         case 116:
            ++ i; goto Q17;
         }
         if constexpr( true ) return latest;
      Q05:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      Q06:
         latest. first = sym_COMMA; latest. second = i;
         return latest;
      Q07:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 45 ) { ++ i; goto Q18; }
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      Q08:
         latest. first = sym_DOT; latest. second = i;
         return latest;
      Q09:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 42 ) { ++ i; goto Q19; }
         if( c == 47 ) { ++ i; goto Q20; }
         if constexpr( true ) return latest;
      Q10:
         latest. first = sym_INTEGER; latest. second = i;
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c >= 58 ) return latest;
         if( c >= 48 ) { ++ i; goto Q10; }
         if constexpr( true ) return latest;
      Q11:
         latest. first = sym_STRING; latest. second = i;
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 95 ) { ++ i; goto Q11; }
         if( c == 96 ) return latest;
         if( c >= 58 )
         {
            if( c >= 91 )
            {
               if( c >= 123 ) return latest;
               if( c >= 97 ) { ++ i; goto Q11; }
               if constexpr( true ) return latest;
            }
            else
            {
               if( c >= 65 ) { ++ i; goto Q11; }
               if constexpr( true ) return latest;
            }
         }
         else
         {
            if( c >= 48 ) { ++ i; goto Q11; }
            if( c >= 37 ) return latest;
            if( c >= 35 ) { ++ i; goto Q11; }
            if constexpr( true ) return latest;
         }
      Q12:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 99 ) { ++ i; goto Q21; }
         if( c == 108 ) { ++ i; goto Q22; }
         if constexpr( true ) return latest;
      Q13:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 108 ) { ++ i; goto Q23; }
         if constexpr( true ) return latest;
      Q14:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q24; }
         if constexpr( true ) return latest;
      Q15:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q25; }
         if constexpr( true ) return latest;
      Q16:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q26; }
         if constexpr( true ) return latest;
      Q17:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 114 ) { ++ i; goto Q27; }
         if constexpr( true ) return latest;
      Q18:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 62 ) { ++ i; goto Q28; }
         if constexpr( true ) return latest;
      Q19:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 42 ) { ++ i; goto Q29; }
         if constexpr( true ) { ++ i; goto Q19; }
      Q20:
         latest. first = sym_COMMENT; latest. second = i;
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 10 ) return latest;
         if constexpr( true ) { ++ i; goto Q20; }
      Q21:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 99 ) { ++ i; goto Q30; }
         if constexpr( true ) return latest;
      Q22:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 112 ) { ++ i; goto Q31; }
         if constexpr( true ) return latest;
      Q23:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 97 ) { ++ i; goto Q32; }
         if constexpr( true ) return latest;
      Q24:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 100 ) { ++ i; goto Q33; }
         if constexpr( true ) return latest;
      Q25:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 112 ) { ++ i; goto Q34; }
         if constexpr( true ) return latest;
      Q26:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 97 ) { ++ i; goto Q35; }
         if constexpr( true ) return latest;
      Q27:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 97 ) { ++ i; goto Q36; }
         if constexpr( true ) return latest;
      Q28:
         latest. first = sym_ARROW; latest. second = i;
         return latest;
      Q29:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 42 ) { ++ i; goto Q29; }
         if( c == 47 ) { ++ i; goto Q37; }
         if constexpr( true ) { ++ i; goto Q19; }
      Q30:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 101 ) { ++ i; goto Q38; }
         if constexpr( true ) return latest;
      Q31:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 104 ) { ++ i; goto Q39; }
         if constexpr( true ) return latest;
      Q32:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q40; }
         if constexpr( true ) return latest;
      Q33:
         latest. first = sym_EOF; latest. second = i;
         return latest;
      Q34:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 117 ) { ++ i; goto Q41; }
         if constexpr( true ) return latest;
      Q35:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 114 ) { ++ i; goto Q42; }
         if constexpr( true ) return latest;
      Q36:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q43; }
         if constexpr( true ) return latest;
      Q37:
         latest. first = sym_COMMENT; latest. second = i;
         return latest;
      Q38:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 112 ) { ++ i; goto Q44; }
         if constexpr( true ) return latest;
      Q39:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 97 ) { ++ i; goto Q45; }
         if constexpr( true ) return latest;
      Q40:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 107 ) { ++ i; goto Q46; }
         if constexpr( true ) return latest;
      Q41:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q47; }
         if constexpr( true ) return latest;
      Q42:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q48; }
         if constexpr( true ) return latest;
      Q43:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 115 ) { ++ i; goto Q49; }
         if constexpr( true ) return latest;
      Q44:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q50; }
         if constexpr( true ) return latest;
      Q45:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 98 ) { ++ i; goto Q51; }
         if constexpr( true ) return latest;
      Q46:
         latest. first = sym_BLANK; latest. second = i;
         return latest;
      Q47:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 115 ) { ++ i; goto Q52; }
         if constexpr( true ) return latest;
      Q48:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 105 ) { ++ i; goto Q53; }
         if constexpr( true ) return latest;
      Q49:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 105 ) { ++ i; goto Q54; }
         if constexpr( true ) return latest;
      Q50:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 105 ) { ++ i; goto Q55; }
         if constexpr( true ) return latest;
      Q51:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 101 ) { ++ i; goto Q56; }
         if constexpr( true ) return latest;
      Q52:
         latest. first = sym_INPUTS; latest. second = i;
         return latest;
      Q53:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q57; }
         if constexpr( true ) return latest;
      Q54:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q58; }
         if constexpr( true ) return latest;
      Q55:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q59; }
         if constexpr( true ) return latest;
      Q56:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 116 ) { ++ i; goto Q60; }
         if constexpr( true ) return latest;
      Q57:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 103 ) { ++ i; goto Q61; }
         if constexpr( true ) return latest;
      Q58:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 105 ) { ++ i; goto Q62; }
         if constexpr( true ) return latest;
      Q59:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 103 ) { ++ i; goto Q63; }
         if constexpr( true ) return latest;
      Q60:
         latest. first = sym_ALPHABET; latest. second = i;
         return latest;
      Q61:
         latest. first = sym_STARTING; latest. second = i;
         return latest;
      Q62:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 111 ) { ++ i; goto Q64; }
         if constexpr( true ) return latest;
      Q63:
         latest. first = sym_ACCEPTING; latest. second = i;
         return latest;
      Q64:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 110 ) { ++ i; goto Q65; }
         if constexpr( true ) return latest;
      Q65:
         if( !inp. has(i+1))
            return latest;
         c = inp. peek(i);
         if( c == 115 ) { ++ i; goto Q66; }
         if constexpr( true ) return latest;
      Q66:
         latest. first = sym_TRANSITIONS; latest. second = i;
         return latest;
      }
   }
}

