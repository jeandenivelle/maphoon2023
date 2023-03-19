
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++


multimodal : Makefile   multimodal.o tokenizer.o ../filereader.o symbol.o ../../lexing2022/stateset.o ../../lexing2022/partition.o form.o agent.o parser.o 
	$(CPP) $(Flags) -o multimodal   multimodal.o tokenizer.o ../filereader.o symbol.o ../../lexing2022/stateset.o ../../lexing2022/partition.o form.o agent.o parser.o 

multimodal.o : Makefile   multimodal.cpp   ../calculator/varstore.h form.h agent.h ../indentation.h ../../easycomp2022a/util/shared_ptr.h parser.h symbol.h tokenizer.h ../filereader.h 
	$(CPP) -c $(Flags) multimodal.cpp -o  multimodal.o


tokenizer.o : Makefile   tokenizer.cpp   DFA.h ../../lexing2022/includes.h ../../lexing2022/acceptor.h ../../lexing2022/flatmap.h ../../lexing2022/state.h ../../lexing2022/minmax.h ../../lexing2022/classifier.h ../../lexing2022/algorithms.h ../../lexing2022/stateset.h ../../lexing2022/minimization.h ../../lexing2022/partition.h ../../lexing2022/reachableclasses.h ../../lexing2022/generators.h ../../lexing2022/indentation.h ../../lexing2022/deterministic.h tokenizer.h ../filereader.h symbol.h form.h agent.h ../indentation.h ../../easycomp2022a/util/shared_ptr.h 
	$(CPP) -c $(Flags) tokenizer.cpp -o  tokenizer.o


../filereader.o : Makefile   ../filereader.cpp   ../filereader.h 
	$(CPP) -c $(Flags) ../filereader.cpp -o  ../filereader.o


symbol.o : Makefile   symbol.cpp   symbol.h form.h agent.h ../indentation.h ../../easycomp2022a/util/shared_ptr.h 
	$(CPP) -c $(Flags) symbol.cpp -o  symbol.o


../../lexing2022/stateset.o : Makefile   ../../lexing2022/stateset.cpp   ../../lexing2022/stateset.h ../../lexing2022/state.h 
	$(CPP) -c $(Flags) ../../lexing2022/stateset.cpp -o  ../../lexing2022/stateset.o


../../lexing2022/partition.o : Makefile   ../../lexing2022/partition.cpp   ../../lexing2022/partition.h ../../lexing2022/stateset.h ../../lexing2022/state.h 
	$(CPP) -c $(Flags) ../../lexing2022/partition.cpp -o  ../../lexing2022/partition.o


form.o : Makefile   form.cpp   form.h agent.h ../indentation.h ../../easycomp2022a/util/shared_ptr.h 
	$(CPP) -c $(Flags) form.cpp -o  form.o


agent.o : Makefile   agent.cpp   agent.h 
	$(CPP) -c $(Flags) agent.cpp -o  agent.o


parser.o : Makefile   parser.cpp   parser.h symbol.h form.h agent.h ../indentation.h ../../easycomp2022a/util/shared_ptr.h tokenizer.h ../filereader.h ../calculator/varstore.h 
	$(CPP) -c $(Flags) parser.cpp -o  parser.o


