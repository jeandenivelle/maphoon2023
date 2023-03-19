
//  Copyright <2021> <Hans de Nivelle>
//
//  This software is released with the 3-clause BSD license, which 
//  is given below: 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions are met:

//  Redistributions of source code must retain the above copyright notice, 
//  this list of conditions and the following disclaimer:

//  Redistributions in binary form must reproduce the above copyright notice, 
//  this list of conditions and the following disclaimer in the documentation 
//  and/or other materials provided with the distribution.
//  Neither the name of the copyright holder nor the names of its contributors 
//  may be used to endorse or promote products derived from this software 
//  without specific prior written permission.

//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
//  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



// automatically generated code:
// generator written by Hans de Nivelle and Dina Muktubayeva

template< typename S >
std::pair< std::string, size_t > readandclassify( int triv, S& inp )
{
   auto latest = std::make_pair< std::string, size_t > ( "#error", 0 );
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
   case 12:
   case 32:
      ++ i; goto Q01;
   case 13:
      ++ i; goto Q02;
   case 33:
      ++ i; goto Q03;
   case 34:
      ++ i; goto Q04;
   case 35:
      ++ i; goto Q05;
   case 37:
      ++ i; goto Q06;
   case 38:
      ++ i; goto Q07;
   case 39:
      ++ i; goto Q08;
   case 40:
      ++ i; goto Q09;
   case 41:
      ++ i; goto Q10;
   case 42:
      ++ i; goto Q11;
   case 43:
      ++ i; goto Q12;
   case 44:
      ++ i; goto Q13;
   case 45:
      ++ i; goto Q14;
   case 46:
      ++ i; goto Q15;
   case 47:
      ++ i; goto Q16;
   case 48:
      ++ i; goto Q17;
   case 58:
      ++ i; goto Q19;
   case 59:
      ++ i; goto Q20;
   case 60:
      ++ i; goto Q21;
   case 61:
      ++ i; goto Q22;
   case 62:
      ++ i; goto Q23;
   case 63:
      ++ i; goto Q24;
   case 111:
   case 113:
   case 117:
      ++ i; goto Q25;
   case 91:
      ++ i; goto Q26;
   case 93:
      ++ i; goto Q27;
   case 97:
      ++ i; goto Q28;
   case 98:
      ++ i; goto Q29;
   case 99:
      ++ i; goto Q30;
   case 100:
      ++ i; goto Q31;
   case 101:
      ++ i; goto Q32;
   case 102:
      ++ i; goto Q33;
   case 105:
      ++ i; goto Q34;
   case 110:
      ++ i; goto Q35;
   case 112:
      ++ i; goto Q36;
   case 114:
      ++ i; goto Q37;
   case 115:
      ++ i; goto Q38;
   case 116:
      ++ i; goto Q39;
   case 118:
      ++ i; goto Q40;
   case 119:
      ++ i; goto Q41;
   case 124:
      ++ i; goto Q42;
   case 11:
   case 36:
   case 64:
   case 92:
   case 123:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 125 ) return latest;
      if( c >= 103 ) { ++ i; goto Q25; }
      if( c >= 94 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 49 ) { ++ i; goto Q18; }
      if( c >= 14 ) return latest;
      if( c >= 9 ) { ++ i; goto Q01; }
      if constexpr( true ) return latest;
   }
Q01:
   latest. first = "#whitespace"; latest. second = i;
   return latest;
Q02:
   latest. first = "#whitespace"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 10 ) { ++ i; goto Q01; }
   if constexpr( true ) return latest;
Q03:
   latest. first = "#not"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 61 ) { ++ i; goto Q43; }
   if constexpr( true ) return latest;
Q04:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 34 ) { ++ i; goto Q44; }
   if( c == 92 ) { ++ i; goto Q45; }
   if constexpr( true ) { ++ i; goto Q04; }
Q05:
   latest. first = "#eof"; latest. second = i;
   return latest;
Q06:
   latest. first = "#mod"; latest. second = i;
   return latest;
Q07:
   latest. first = "#ampersand"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 38 ) { ++ i; goto Q46; }
   if constexpr( true ) return latest;
Q08:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 92 ) { ++ i; goto Q48; }
   if( c == 39 ) return latest;
   if constexpr( true ) { ++ i; goto Q47; }
Q09:
   latest. first = "#lpar"; latest. second = i;
   return latest;
Q10:
   latest. first = "#rpar"; latest. second = i;
   return latest;
Q11:
   latest. first = "#mul"; latest. second = i;
   return latest;
Q12:
   latest. first = "#add"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 43 ) { ++ i; goto Q49; }
   if constexpr( true ) return latest;
Q13:
   latest. first = "#comma"; latest. second = i;
   return latest;
Q14:
   latest. first = "#sub"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 45 ) { ++ i; goto Q50; }
   if( c == 62 ) { ++ i; goto Q52; }
   if( c >= 58 ) return latest;
   if( c >= 49 ) { ++ i; goto Q51; }
   if constexpr( true ) return latest;
Q15:
   latest. first = "#dot"; latest. second = i;
   return latest;
Q16:
   latest. first = "#truediv"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q53; }
   if( c == 47 ) { ++ i; goto Q54; }
   if constexpr( true ) return latest;
Q17:
   latest. first = "#integerconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 46 ) { ++ i; goto Q55; }
   if( c == 69 || c == 101 ) { ++ i; goto Q56; }
   if constexpr( true ) return latest;
Q18:
   latest. first = "#integerconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 46:
      ++ i; goto Q55;
   case 69:
   case 101:
      ++ i; goto Q56;
   case 47:
      return latest;
   }
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q18; }
   if constexpr( true ) return latest;
Q19:
   latest. first = "#colon"; latest. second = i;
   return latest;
Q20:
   latest. first = "#semicolon"; latest. second = i;
   return latest;
Q21:
   latest. first = "#lt"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 61 ) { ++ i; goto Q57; }
   if constexpr( true ) return latest;
Q22:
   latest. first = "#assign"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 61 ) { ++ i; goto Q58; }
   if constexpr( true ) return latest;
Q23:
   latest. first = "#gt"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 61 ) { ++ i; goto Q59; }
   if constexpr( true ) return latest;
Q24:
   latest. first = "#question"; latest. second = i;
   return latest;
Q25:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q26:
   latest. first = "#lsqpar"; latest. second = i;
   return latest;
Q27:
   latest. first = "#rsqpar"; latest. second = i;
   return latest;
Q28:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q60; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q29:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 101:
      ++ i; goto Q61;
   case 111:
      ++ i; goto Q62;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q30:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 104:
      ++ i; goto Q63;
   case 111:
      ++ i; goto Q64;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q31:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 111 ) { ++ i; goto Q65; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q32:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
   case 109:
      ++ i; goto Q25;
   case 108:
      ++ i; goto Q66;
   case 110:
      ++ i; goto Q67;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q33:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 97:
      ++ i; goto Q68;
   case 117:
      ++ i; goto Q69;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 98 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q34:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 102:
      ++ i; goto Q70;
   case 110:
      ++ i; goto Q71;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q35:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 101:
      ++ i; goto Q72;
   case 117:
      ++ i; goto Q73;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q36:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 111:
      ++ i; goto Q74;
   case 114:
      ++ i; goto Q75;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q37:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q76; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q38:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q77; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q39:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 104:
      ++ i; goto Q78;
   case 114:
      ++ i; goto Q79;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q40:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 111 ) { ++ i; goto Q80; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q41:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 104 ) { ++ i; goto Q81; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q42:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 124 ) { ++ i; goto Q82; }
   if constexpr( true ) return latest;
Q43:
   latest. first = "#ne"; latest. second = i;
   return latest;
Q44:
   latest. first = "#stringconst"; latest. second = i;
   return latest;
Q45:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 92 ) { ++ i; goto Q04; }
   if constexpr( true ) return latest;
Q46:
   latest. first = "#and"; latest. second = i;
   return latest;
Q47:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 39 ) { ++ i; goto Q83; }
   if constexpr( true ) return latest;
Q48:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 34:
   case 39:
   case 48:
   case 110:
   case 116:
      ++ i; goto Q47;
   }
   if constexpr( true ) return latest;
Q49:
   latest. first = "#plusplus"; latest. second = i;
   return latest;
Q50:
   latest. first = "#minusminus"; latest. second = i;
   return latest;
Q51:
   latest. first = "#integerconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q51; }
   if constexpr( true ) return latest;
Q52:
   latest. first = "#arrow"; latest. second = i;
   return latest;
Q53:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q84; }
   if constexpr( true ) { ++ i; goto Q53; }
Q54:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 10 ) { ++ i; goto Q85; }
   if constexpr( true ) { ++ i; goto Q54; }
Q55:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q86; }
   if constexpr( true ) return latest;
Q56:
   latest. first = "#doubleconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 43 || c == 45 ) { ++ i; goto Q87; }
   if( c == 44 ) return latest;
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q88; }
   if constexpr( true ) return latest;
Q57:
   latest. first = "#le"; latest. second = i;
   return latest;
Q58:
   latest. first = "#eq"; latest. second = i;
   return latest;
Q59:
   latest. first = "#ge"; latest. second = i;
   return latest;
Q60:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q89; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q61:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 103 ) { ++ i; goto Q90; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q62:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 111 ) { ++ i; goto Q91; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q63:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 97 ) { ++ i; goto Q92; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 98 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q64:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q93; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q65:
   latest. first = "#do"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 117 ) { ++ i; goto Q94; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q66:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 115 ) { ++ i; goto Q95; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q67:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 100 ) { ++ i; goto Q96; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q68:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q97; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q69:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q98; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q70:
   latest. first = "#if"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q71:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q99; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q72:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 119 ) { ++ i; goto Q100; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q73:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q101; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q74:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q102; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q75:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q103; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q76:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q104; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q77:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q105; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q78:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q106; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q79:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
      ++ i; goto Q25;
   case 97:
      ++ i; goto Q107;
   case 117:
      ++ i; goto Q108;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 98 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q80:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q109; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q81:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q110; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q82:
   latest. first = "#or"; latest. second = i;
   return latest;
Q83:
   latest. first = "#charconst"; latest. second = i;
   return latest;
Q84:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q84; }
   if( c == 47 ) { ++ i; goto Q85; }
   if constexpr( true ) { ++ i; goto Q53; }
Q85:
   latest. first = "#comment"; latest. second = i;
   return latest;
Q86:
   latest. first = "#doubleconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 69 || c == 101 ) { ++ i; goto Q56; }
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q86; }
   if constexpr( true ) return latest;
Q87:
   latest. first = "#doubleconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q88; }
   if constexpr( true ) return latest;
Q88:
   latest. first = "#doubleconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q111; }
   if constexpr( true ) return latest;
Q89:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 97 ) { ++ i; goto Q112; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 98 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q90:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q113; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q91:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q114; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q92:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q115; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q93:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 115 ) { ++ i; goto Q116; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q94:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
   case 97:
      ++ i; goto Q25;
   case 98:
      ++ i; goto Q117;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 99 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q95:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q118; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q96:
   latest. first = "#end"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q97:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 115 ) { ++ i; goto Q119; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q98:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 99 ) { ++ i; goto Q120; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q99:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q121; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q100:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q122; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q101:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q123; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q102:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q124; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q103:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q125; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q104:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 117 ) { ++ i; goto Q126; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q105:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 117 ) { ++ i; goto Q127; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q106:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q128; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q107:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 99 ) { ++ i; goto Q129; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q108:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q130; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q109:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 100 ) { ++ i; goto Q131; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q110:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q132; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q111:
   latest. first = "#doubleconst"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q133; }
   if constexpr( true ) return latest;
Q112:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 95:
   case 122:
      ++ i; goto Q25;
   case 121:
      ++ i; goto Q134;
   case 96:
      return latest;
   }
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q113:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q135; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q114:
   latest. first = "#bool"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q115:
   latest. first = "#char"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q116:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q136; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q117:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 108 ) { ++ i; goto Q137; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q118:
   latest. first = "#else"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q119:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q138; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q120:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q139; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q121:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 103 ) { ++ i; goto Q140; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q122:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q141; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q123:
   latest. first = "#null"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q124:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q142; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q125:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q143; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q126:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q144; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q127:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 99 ) { ++ i; goto Q145; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q128:
   latest. first = "#then"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q129:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q146; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q130:
   latest. first = "#true"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q131:
   latest. first = "#void"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q132:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q147; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q133:
   latest. first = "#doubleconst"; latest. second = i;
   return latest;
Q134:
   latest. first = "#array"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q135:
   latest. first = "#begin"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q136:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 97 ) { ++ i; goto Q148; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 98 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q137:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q149; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q138:
   latest. first = "#false"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q139:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 105 ) { ++ i; goto Q150; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q140:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q151; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q141:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q152; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q142:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q153; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q143:
   latest. first = "#print"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q144:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q154; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q145:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q155; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q146:
   latest. first = "#trace"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q147:
   latest. first = "#while"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q148:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q156; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q149:
   latest. first = "#double"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q150:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 111 ) { ++ i; goto Q157; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q151:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q158; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q152:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q159; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q153:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 114 ) { ++ i; goto Q160; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q154:
   latest. first = "#return"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q155:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 100 ) { ++ i; goto Q161; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q156:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 116 ) { ++ i; goto Q162; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q157:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 110 ) { ++ i; goto Q163; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q158:
   latest. first = "#integer"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q159:
   latest. first = "#newline"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q160:
   latest. first = "#pointer"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q161:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 101 ) { ++ i; goto Q164; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q162:
   latest. first = "#constant"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q163:
   latest. first = "#function"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q164:
   latest. first = "#identifier"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 102 ) { ++ i; goto Q165; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
Q165:
   latest. first = "#structdef"; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 95 ) { ++ i; goto Q25; }
   if( c == 96 ) return latest;
   if( c >= 65 )
   {
      if( c >= 123 ) return latest;
      if( c >= 97 ) { ++ i; goto Q25; }
      if( c >= 91 ) return latest;
      if constexpr( true ) { ++ i; goto Q25; }
   }
   else
   {
      if( c >= 58 ) return latest;
      if( c >= 48 ) { ++ i; goto Q25; }
      if constexpr( true ) return latest;
   }
}


