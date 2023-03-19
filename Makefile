
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wpedantic -pedantic-errors -std=c++20
CPP = g++ -O3 -flto


maphoon : Makefile   maphoon.o ../lexing2023/filereader.o tokenizing.o ourownparser.o symbol.o errors.o rule.o grammar.o expectation.o itemsets.o parsetable.o symbolcodebuilder.o parsercodebuilder.o tablecodebuilder.o cpp/type.o cpp/nspace.o cpp/identifier.o cpp/codefragment.o ../lexing2023/stateset.o ../lexing2023/partition.o 
	$(CPP) $(Flags) -o maphoon   maphoon.o ../lexing2023/filereader.o tokenizing.o ourownparser.o symbol.o errors.o rule.o grammar.o expectation.o itemsets.o parsetable.o symbolcodebuilder.o parsercodebuilder.o tablecodebuilder.o cpp/type.o cpp/nspace.o cpp/identifier.o cpp/codefragment.o ../lexing2023/stateset.o ../lexing2023/partition.o 

maphoon.o : Makefile   maphoon.cpp   parsercodebuilder.h symbolcodebuilder.h cpp/codefragment.h cpp/nspace.h cpp/type.h errors.h itemsets.h symbolset.h symbol.h rule.h grammar.h indentation.h parsetable.h expectation.h cpp/identifier.h ourownparser.h tokenizing.h ../lexing2023/includes.h ../lexing2023/filereader.h ../lexing2023/viewreader.h ../lexing2023/acceptor.h ../lexing2023/flatmap.h ../lexing2023/state.h ../lexing2023/minmax.h ../lexing2023/classifier.h ../lexing2023/algorithms.h ../lexing2023/stateset.h ../lexing2023/minimization.h ../lexing2023/partition.h ../lexing2023/reachfunc.h ../lexing2023/comp.h ../lexing2023/generators.h ../lexing2023/indentation.h ../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) maphoon.cpp -o  maphoon.o


../lexing2023/filereader.o : Makefile   ../lexing2023/filereader.cpp   ../lexing2023/filereader.h 
	$(CPP) -c $(Flags) ../lexing2023/filereader.cpp -o  ../lexing2023/filereader.o


tokenizing.o : Makefile   tokenizing.cpp   tokenizing.h indentation.h ../lexing2023/includes.h ../lexing2023/filereader.h ../lexing2023/viewreader.h ../lexing2023/acceptor.h ../lexing2023/flatmap.h ../lexing2023/state.h ../lexing2023/minmax.h ../lexing2023/classifier.h ../lexing2023/algorithms.h ../lexing2023/stateset.h ../lexing2023/minimization.h ../lexing2023/partition.h ../lexing2023/reachfunc.h ../lexing2023/comp.h ../lexing2023/generators.h ../lexing2023/indentation.h ../lexing2023/deterministic.h 
	$(CPP) -c $(Flags) tokenizing.cpp -o  tokenizing.o


ourownparser.o : Makefile   ourownparser.cpp   errors.h itemsets.h symbolset.h symbol.h rule.h grammar.h ourownparser.h tokenizing.h indentation.h ../lexing2023/includes.h ../lexing2023/filereader.h ../lexing2023/viewreader.h ../lexing2023/acceptor.h ../lexing2023/flatmap.h ../lexing2023/state.h ../lexing2023/minmax.h ../lexing2023/classifier.h ../lexing2023/algorithms.h ../lexing2023/stateset.h ../lexing2023/minimization.h ../lexing2023/partition.h ../lexing2023/reachfunc.h ../lexing2023/comp.h ../lexing2023/generators.h ../lexing2023/indentation.h ../lexing2023/deterministic.h symbolcodebuilder.h cpp/codefragment.h cpp/nspace.h cpp/type.h parsercodebuilder.h parsetable.h expectation.h cpp/identifier.h 
	$(CPP) -c $(Flags) ourownparser.cpp -o  ourownparser.o


symbol.o : Makefile   symbol.cpp   symbol.h 
	$(CPP) -c $(Flags) symbol.cpp -o  symbol.o


errors.o : Makefile   errors.cpp   errors.h itemsets.h symbolset.h symbol.h rule.h grammar.h 
	$(CPP) -c $(Flags) errors.cpp -o  errors.o


rule.o : Makefile   rule.cpp   rule.h symbol.h 
	$(CPP) -c $(Flags) rule.cpp -o  rule.o


grammar.o : Makefile   grammar.cpp   grammar.h rule.h symbol.h symbolset.h 
	$(CPP) -c $(Flags) grammar.cpp -o  grammar.o


expectation.o : Makefile   expectation.cpp   expectation.h symbolset.h symbol.h 
	$(CPP) -c $(Flags) expectation.cpp -o  expectation.o


itemsets.o : Makefile   itemsets.cpp   itemsets.h symbolset.h symbol.h rule.h grammar.h 
	$(CPP) -c $(Flags) itemsets.cpp -o  itemsets.o


parsetable.o : Makefile   parsetable.cpp   parsetable.h itemsets.h symbolset.h symbol.h rule.h grammar.h 
	$(CPP) -c $(Flags) parsetable.cpp -o  parsetable.o


symbolcodebuilder.o : Makefile   symbolcodebuilder.cpp   indentation.h symbolcodebuilder.h cpp/codefragment.h cpp/nspace.h cpp/type.h errors.h itemsets.h symbolset.h symbol.h rule.h grammar.h 
	$(CPP) -c $(Flags) symbolcodebuilder.cpp -o  symbolcodebuilder.o


parsercodebuilder.o : Makefile   parsercodebuilder.cpp   tablecodebuilder.h symbol.h symbolset.h parsetable.h itemsets.h rule.h grammar.h cpp/nspace.h expectation.h errors.h parsercodebuilder.h symbolcodebuilder.h cpp/codefragment.h cpp/type.h indentation.h cpp/identifier.h 
	$(CPP) -c $(Flags) parsercodebuilder.cpp -o  parsercodebuilder.o


tablecodebuilder.o : Makefile   tablecodebuilder.cpp   tablecodebuilder.h symbol.h symbolset.h parsetable.h itemsets.h rule.h grammar.h cpp/nspace.h expectation.h 
	$(CPP) -c $(Flags) tablecodebuilder.cpp -o  tablecodebuilder.o


cpp/type.o : Makefile   cpp/type.cpp   cpp/type.h 
	$(CPP) -c $(Flags) cpp/type.cpp -o  cpp/type.o


cpp/nspace.o : Makefile   cpp/nspace.cpp   cpp/identifier.h cpp/nspace.h 
	$(CPP) -c $(Flags) cpp/nspace.cpp -o  cpp/nspace.o


cpp/identifier.o : Makefile   cpp/identifier.cpp   cpp/identifier.h 
	$(CPP) -c $(Flags) cpp/identifier.cpp -o  cpp/identifier.o


cpp/codefragment.o : Makefile   cpp/codefragment.cpp   cpp/codefragment.h 
	$(CPP) -c $(Flags) cpp/codefragment.cpp -o  cpp/codefragment.o


../lexing2023/stateset.o : Makefile   ../lexing2023/stateset.cpp   ../lexing2023/stateset.h ../lexing2023/state.h 
	$(CPP) -c $(Flags) ../lexing2023/stateset.cpp -o  ../lexing2023/stateset.o


../lexing2023/partition.o : Makefile   ../lexing2023/partition.cpp   ../lexing2023/partition.h ../lexing2023/stateset.h ../lexing2023/state.h 
	$(CPP) -c $(Flags) ../lexing2023/partition.cpp -o  ../lexing2023/partition.o


