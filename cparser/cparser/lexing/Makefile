
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17 -O5 -flto
CPP = g++


tester : Makefile   tester.o ../filereader.o stateset.o partition.o 
	$(CPP) $(Flags) -o tester   tester.o ../filereader.o stateset.o partition.o 

tester.o : Makefile   tester.cpp   det.h code.h trivial.h flatmap.h state.h deterministic.h generators.h ../indentation.h minimization.h partition.h stateset.h reachableclasses.h algorithms.h acceptor.h minmax.h classifier.h crazy.h ../stringreader.h ../filereader.h 
	$(CPP) -c $(Flags) tester.cpp -o  tester.o


../filereader.o : Makefile   ../filereader.cpp   ../filereader.h 
	$(CPP) -c $(Flags) ../filereader.cpp -o  ../filereader.o


stateset.o : Makefile   stateset.cpp   stateset.h state.h 
	$(CPP) -c $(Flags) stateset.cpp -o  stateset.o


partition.o : Makefile   partition.cpp   partition.h stateset.h state.h 
	$(CPP) -c $(Flags) partition.cpp -o  partition.o


