
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++ -flto -O3


calculator : Makefile   calculator.o symbol.o tokenizer.o parser.o ../../lexing2023/filereader.o ../../lexing2023/stateset.o ../../lexing2023/partition.o 
	$(CPP) $(Flags) -o calculator   calculator.o symbol.o tokenizer.o parser.o ../../lexing2023/filereader.o ../../lexing2023/stateset.o ../../lexing2023/partition.o 

calculator.o : Makefile   calculator.cpp   parser.h symbol.h varstore.h tokenizer.h ../../lexing2023/includes.h ../../lexing2023/filereader.h ../../lexing2023/viewreader.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) calculator.cpp -o  calculator.o


symbol.o : Makefile   symbol.cpp   symbol.h 
	$(CPP) -c $(Flags) symbol.cpp -o  symbol.o


tokenizer.o : Makefile   tokenizer.cpp   DFA.h tokenizer.h symbol.h ../../lexing2023/includes.h ../../lexing2023/filereader.h ../../lexing2023/viewreader.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) tokenizer.cpp -o  tokenizer.o


parser.o : Makefile   parser.cpp   parser.h symbol.h varstore.h tokenizer.h ../../lexing2023/includes.h ../../lexing2023/filereader.h ../../lexing2023/viewreader.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) parser.cpp -o  parser.o


../../lexing2023/filereader.o : Makefile   ../../lexing2023/filereader.cpp   ../../lexing2023/filereader.h 
	$(CPP) -c $(Flags) ../../lexing2023/filereader.cpp -o  ../../lexing2023/filereader.o


../../lexing2023/stateset.o : Makefile   ../../lexing2023/stateset.cpp   ../../lexing2023/stateset.h ../../lexing2023/state.h 
	$(CPP) -c $(Flags) ../../lexing2023/stateset.cpp -o  ../../lexing2023/stateset.o


../../lexing2023/partition.o : Makefile   ../../lexing2023/partition.cpp   ../../lexing2023/partition.h ../../lexing2023/stateset.h ../../lexing2023/state.h 
	$(CPP) -c $(Flags) ../../lexing2023/partition.cpp -o  ../../lexing2023/partition.o


