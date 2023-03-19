
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++ -O3 -flto 


simulator : Makefile   rhs.o turingmachine.o simulator.o configuration.o parsing/symbol.o parsing/tokenizer.o parsing/parser.o ../filereader.o ../../lexing2023/stateset.o ../../lexing2023/partition.o 
	$(CPP) $(Flags) -o simulator   rhs.o turingmachine.o simulator.o configuration.o parsing/symbol.o parsing/tokenizer.o parsing/parser.o ../filereader.o ../../lexing2023/stateset.o ../../lexing2023/partition.o 

rhs.o : Makefile   rhs.cpp   rhs.h state.h 
	$(CPP) -c $(Flags) rhs.cpp -o  rhs.o


turingmachine.o : Makefile   turingmachine.cpp   turingmachine.h lhs.h state.h rhs.h 
	$(CPP) -c $(Flags) turingmachine.cpp -o  turingmachine.o


simulator.o : Makefile   simulator.cpp   parsing/parser.h parsing/symbol.h turingmachine.h lhs.h state.h rhs.h parsing/location.h parsing/tokenizer.h ../filereader.h ../../lexing2023/includes.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h configuration.h reachable.h 
	$(CPP) -c $(Flags) simulator.cpp -o  simulator.o


configuration.o : Makefile   configuration.cpp   configuration.h rhs.h state.h turingmachine.h lhs.h reachable.h 
	$(CPP) -c $(Flags) configuration.cpp -o  configuration.o


parsing/symbol.o : Makefile   parsing/symbol.cpp   parsing/symbol.h turingmachine.h lhs.h state.h rhs.h parsing/location.h 
	$(CPP) -c $(Flags) parsing/symbol.cpp -o  parsing/symbol.o


parsing/tokenizer.o : Makefile   parsing/tokenizer.cpp   parsing/DFA.h parsing/tokenizer.h parsing/symbol.h turingmachine.h lhs.h state.h rhs.h parsing/location.h ../filereader.h ../../lexing2023/includes.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) parsing/tokenizer.cpp -o  parsing/tokenizer.o


parsing/parser.o : Makefile   parsing/parser.cpp   parsing/parser.h parsing/symbol.h turingmachine.h lhs.h state.h rhs.h parsing/location.h parsing/tokenizer.h ../filereader.h ../../lexing2023/includes.h ../../lexing2023/acceptor.h ../../lexing2023/flatmap.h ../../lexing2023/state.h ../../lexing2023/minmax.h ../../lexing2023/classifier.h ../../lexing2023/algorithms.h ../../lexing2023/stateset.h ../../lexing2023/minimization.h ../../lexing2023/partition.h ../../lexing2023/reachfunc.h ../../lexing2023/comp.h ../../lexing2023/generators.h ../../lexing2023/indentation.h ../../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) parsing/parser.cpp -o  parsing/parser.o


../filereader.o : Makefile   ../filereader.cpp   ../filereader.h 
	$(CPP) -c $(Flags) ../filereader.cpp -o  ../filereader.o


../../lexing2023/stateset.o : Makefile   ../../lexing2023/stateset.cpp   ../../lexing2023/stateset.h ../../lexing2023/state.h 
	$(CPP) -c $(Flags) ../../lexing2023/stateset.cpp -o  ../../lexing2023/stateset.o


../../lexing2023/partition.o : Makefile   ../../lexing2023/partition.cpp   ../../lexing2023/partition.h ../../lexing2023/stateset.h ../../lexing2023/state.h 
	$(CPP) -c $(Flags) ../../lexing2023/partition.cpp -o  ../../lexing2023/partition.o


