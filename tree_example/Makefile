
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++


main : Makefile   main.o tree.o symbol.o tokenizing.o topdownparser.o parser.o ../../easycomp2022a/bigint.o ../filereader.o 
	$(CPP) $(Flags) -o main   main.o tree.o symbol.o tokenizing.o topdownparser.o parser.o ../../easycomp2022a/bigint.o ../filereader.o 

main.o : Makefile   main.cpp   parser.h symbol.h tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h tokenizing.h ../filereader.h topdownparser.h syntaxerror.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


tree.o : Makefile   tree.cpp   tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h 
	$(CPP) -c $(Flags) tree.cpp -o  tree.o


symbol.o : Makefile   symbol.cpp   symbol.h tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h 
	$(CPP) -c $(Flags) symbol.cpp -o  symbol.o


tokenizing.o : Makefile   tokenizing.cpp   ../../lexing2021/algorithms.h ../../lexing2021/acceptor.h ../../lexing2021/flatmap.h ../../lexing2021/state.h ../../lexing2021/minmax.h ../../lexing2021/classifier.h ../../lexing2021/stateset.h tokenizing.h ../filereader.h symbol.h tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h 
	$(CPP) -c $(Flags) tokenizing.cpp -o  tokenizing.o


topdownparser.o : Makefile   topdownparser.cpp   topdownparser.h symbol.h tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h tokenizing.h ../filereader.h syntaxerror.h 
	$(CPP) -c $(Flags) topdownparser.cpp -o  topdownparser.o


parser.o : Makefile   parser.cpp   parser.h symbol.h tree.h ../../easycomp2021b/util/shared_vector.h ../../easycomp2021b/bigint.h ../../easycomp2021b/util/dyn_vector.h ../indentation.h tokenizing.h ../filereader.h 
	$(CPP) -c $(Flags) parser.cpp -o  parser.o


../../easycomp2022a/bigint.o : Makefile   ../../easycomp2022a/bigint.cpp   ../../easycomp2022a/bigint.h ../../easycomp2022a/util/dyn_vector.h 
	$(CPP) -c $(Flags) ../../easycomp2022a/bigint.cpp -o  ../../easycomp2022a/bigint.o


../filereader.o : Makefile   ../filereader.cpp   ../filereader.h 
	$(CPP) -c $(Flags) ../filereader.cpp -o  ../filereader.o


