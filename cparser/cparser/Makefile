Flags=-Wall -std=c++17
LN=g++ $(Flags)
CC=$(LN) -c
MAPH-ALL=./maphoon2022b/maphoon grammar.m . ./maphoon2022b/

cc: symbol.o parser.o lexer.o cc.o filereader.o
	$(LN) cc.o lexer.o symbol.o parser.o filereader.o -o cc

cc.o: main.cpp
	$(CC) -o cc.o main.cpp

lexer.o: lexer.h lexer.cpp
	$(CC) -o lexer.o lexer.cpp

parser.h: grammar.m
	$(MAPH-ALL)

parser.cpp: grammar.m
	$(MAPH-ALL)

symbol.h: grammar.m
	$(MAPH-ALL)

symbol.cpp: grammar.m
	$(MAPH-ALL)

symbol.o: symbol.h symbol.cpp
	$(CC) -o symbol.o symbol.cpp

parser.o: parser.h parser.cpp
	$(CC) -o parser.o parser.cpp

filereader.o: filereader.h filereader.cpp
	$(CC) -o filereader.o filereader.cpp
