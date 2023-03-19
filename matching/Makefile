
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++


solve : Makefile   solve.o token.o filereader.o symbol.o tokenizer.o parser.o ../../lexing2022/stateset.o ../../lexing2022/partition.o 
	$(CPP) $(Flags) -o solve   solve.o token.o filereader.o symbol.o tokenizer.o parser.o ../../lexing2022/stateset.o ../../lexing2022/partition.o 

solve.o : Makefile   solve.cpp   tokenizer.h filereader.h symbol.h instance.h triple.h ishash.h 
	$(CPP) -c $(Flags) solve.cpp -o  solve.o


token.o : Makefile   token.cpp   token.h 
	$(CPP) -c $(Flags) token.cpp -o  token.o


filereader.o : Makefile   filereader.cpp   filereader.h 
	$(CPP) -c $(Flags) filereader.cpp -o  filereader.o


symbol.o : Makefile   symbol.cpp   symbol.h instance.h triple.h ishash.h 
	$(CPP) -c $(Flags) symbol.cpp -o  symbol.o


tokenizer.o : Makefile   tokenizer.cpp   ../../lexing2022/includes.h ../../lexing2022/acceptor.h ../../lexing2022/flatmap.h ../../lexing2022/state.h ../../lexing2022/minmax.h ../../lexing2022/classifier.h ../../lexing2022/algorithms.h ../../lexing2022/stateset.h ../../lexing2022/minimization.h ../../lexing2022/partition.h ../../lexing2022/reachableclasses.h ../../lexing2022/generators.h ../../lexing2022/indentation.h ../../lexing2022/deterministic.h tokenizer.h filereader.h symbol.h instance.h triple.h ishash.h 
	$(CPP) -c $(Flags) tokenizer.cpp -o  tokenizer.o


parser.o : Makefile   parser.cpp   parser.h symbol.h instance.h triple.h ishash.h 
	$(CPP) -c $(Flags) parser.cpp -o  parser.o


../../lexing2022/stateset.o : Makefile   ../../lexing2022/stateset.cpp   ../../lexing2022/stateset.h ../../lexing2022/state.h 
	$(CPP) -c $(Flags) ../../lexing2022/stateset.cpp -o  ../../lexing2022/stateset.o


../../lexing2022/partition.o : Makefile   ../../lexing2022/partition.cpp   ../../lexing2022/partition.h ../../lexing2022/stateset.h ../../lexing2022/state.h 
	$(CPP) -c $(Flags) ../../lexing2022/partition.cpp -o  ../../lexing2022/partition.o


