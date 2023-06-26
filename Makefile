
# Automatically generated Makefile
# Makefile-generator created by Hans de Nivelle, 2023

# Project: Maphoon

CPP = g++

Lexing = /home/nivelle/gitted

Libs =

Options = -Wall -pedantic -pedantic-errors -std=c++20 -O3 -flto

# Linking:

maphoon : errors.o expectation.o grammar.o itemsets.o maphoon.o ourownparser.o parsercodebuilder.o parsetable.o rule.o symbolcodebuilder.o symbol.o tablecodebuilder.o tokenizing.o cpp/codefragment.o cpp/identifier.o cpp/nspace.o cpp/type.o $(Lexing)/lexing2023/stateset.o $(Lexing)/lexing2023/filereader.o $(Lexing)/lexing2023/partition.o
	$(CPP) $(Options) -o maphoon errors.o expectation.o grammar.o itemsets.o maphoon.o ourownparser.o parsercodebuilder.o parsetable.o rule.o symbolcodebuilder.o symbol.o tablecodebuilder.o tokenizing.o cpp/codefragment.o cpp/identifier.o cpp/nspace.o cpp/type.o $(Lexing)/lexing2023/stateset.o $(Lexing)/lexing2023/filereader.o $(Lexing)/lexing2023/partition.o $(Libs)

# Compiling the source files:

errors.o : errors.cpp errors.h grammar.h itemsets.h rule.h symbol.h symbolset.h
	$(CPP) -c $(Options) errors.cpp -o errors.o -I $(Lexing)

expectation.o : expectation.cpp expectation.h symbol.h symbolset.h
	$(CPP) -c $(Options) expectation.cpp -o expectation.o -I $(Lexing)

grammar.o : grammar.cpp grammar.h rule.h symbol.h symbolset.h
	$(CPP) -c $(Options) grammar.cpp -o grammar.o -I $(Lexing)

itemsets.o : itemsets.cpp grammar.h itemsets.h rule.h symbol.h symbolset.h
	$(CPP) -c $(Options) itemsets.cpp -o itemsets.o -I $(Lexing)

maphoon.o : maphoon.cpp cpp/codefragment.h cpp/identifier.h cpp/nspace.h cpp/type.h errors.h expectation.h grammar.h indentation.h itemsets.h ourownparser.h parsercodebuilder.h parsetable.h rule.h symbol.h symbolcodebuilder.h symbolset.h tokenizing.h $(Lexing)/lexing2023/acceptor.h $(Lexing)/lexing2023/algorithms.h $(Lexing)/lexing2023/classifier.h $(Lexing)/lexing2023/comp.h $(Lexing)/lexing2023/deterministic.h $(Lexing)/lexing2023/filereader.h $(Lexing)/lexing2023/flatmap.h $(Lexing)/lexing2023/generators.h $(Lexing)/lexing2023/includes.h $(Lexing)/lexing2023/indentation.h $(Lexing)/lexing2023/minimization.h $(Lexing)/lexing2023/minmax.h $(Lexing)/lexing2023/partition.h $(Lexing)/lexing2023/reachfunc.h $(Lexing)/lexing2023/state.h $(Lexing)/lexing2023/stateset.h $(Lexing)/lexing2023/viewreader.h
	$(CPP) -c $(Options) maphoon.cpp -o maphoon.o -I $(Lexing)

ourownparser.o : ourownparser.cpp cpp/codefragment.h cpp/identifier.h cpp/nspace.h cpp/type.h errors.h expectation.h grammar.h indentation.h itemsets.h ourownparser.h parsercodebuilder.h parsetable.h rule.h symbol.h symbolcodebuilder.h symbolset.h tokenizing.h $(Lexing)/lexing2023/acceptor.h $(Lexing)/lexing2023/algorithms.h $(Lexing)/lexing2023/classifier.h $(Lexing)/lexing2023/comp.h $(Lexing)/lexing2023/deterministic.h $(Lexing)/lexing2023/filereader.h $(Lexing)/lexing2023/flatmap.h $(Lexing)/lexing2023/generators.h $(Lexing)/lexing2023/includes.h $(Lexing)/lexing2023/indentation.h $(Lexing)/lexing2023/minimization.h $(Lexing)/lexing2023/minmax.h $(Lexing)/lexing2023/partition.h $(Lexing)/lexing2023/reachfunc.h $(Lexing)/lexing2023/state.h $(Lexing)/lexing2023/stateset.h $(Lexing)/lexing2023/viewreader.h
	$(CPP) -c $(Options) ourownparser.cpp -o ourownparser.o -I $(Lexing)

parsercodebuilder.o : parsercodebuilder.cpp cpp/codefragment.h cpp/identifier.h cpp/nspace.h cpp/type.h errors.h expectation.h grammar.h indentation.h itemsets.h parsercodebuilder.h parsetable.h rule.h symbol.h symbolcodebuilder.h symbolset.h tablecodebuilder.h
	$(CPP) -c $(Options) parsercodebuilder.cpp -o parsercodebuilder.o -I $(Lexing)

parsetable.o : parsetable.cpp grammar.h itemsets.h parsetable.h rule.h symbol.h symbolset.h
	$(CPP) -c $(Options) parsetable.cpp -o parsetable.o -I $(Lexing)

rule.o : rule.cpp rule.h symbol.h
	$(CPP) -c $(Options) rule.cpp -o rule.o -I $(Lexing)

symbolcodebuilder.o : symbolcodebuilder.cpp cpp/codefragment.h cpp/nspace.h cpp/type.h errors.h grammar.h indentation.h itemsets.h rule.h symbol.h symbolcodebuilder.h symbolset.h
	$(CPP) -c $(Options) symbolcodebuilder.cpp -o symbolcodebuilder.o -I $(Lexing)

symbol.o : symbol.cpp symbol.h
	$(CPP) -c $(Options) symbol.cpp -o symbol.o -I $(Lexing)

tablecodebuilder.o : tablecodebuilder.cpp cpp/nspace.h expectation.h grammar.h itemsets.h parsetable.h rule.h symbol.h symbolset.h tablecodebuilder.h
	$(CPP) -c $(Options) tablecodebuilder.cpp -o tablecodebuilder.o -I $(Lexing)

tokenizing.o : tokenizing.cpp indentation.h tokenizing.h $(Lexing)/lexing2023/acceptor.h $(Lexing)/lexing2023/algorithms.h $(Lexing)/lexing2023/classifier.h $(Lexing)/lexing2023/comp.h $(Lexing)/lexing2023/deterministic.h $(Lexing)/lexing2023/filereader.h $(Lexing)/lexing2023/flatmap.h $(Lexing)/lexing2023/generators.h $(Lexing)/lexing2023/includes.h $(Lexing)/lexing2023/indentation.h $(Lexing)/lexing2023/minimization.h $(Lexing)/lexing2023/minmax.h $(Lexing)/lexing2023/partition.h $(Lexing)/lexing2023/reachfunc.h $(Lexing)/lexing2023/state.h $(Lexing)/lexing2023/stateset.h $(Lexing)/lexing2023/viewreader.h
	$(CPP) -c $(Options) tokenizing.cpp -o tokenizing.o -I $(Lexing)

cpp/codefragment.o : cpp/codefragment.cpp cpp/codefragment.h
	$(CPP) -c $(Options) cpp/codefragment.cpp -o cpp/codefragment.o -I $(Lexing)

cpp/identifier.o : cpp/identifier.cpp cpp/identifier.h
	$(CPP) -c $(Options) cpp/identifier.cpp -o cpp/identifier.o -I $(Lexing)

cpp/nspace.o : cpp/nspace.cpp cpp/identifier.h cpp/nspace.h
	$(CPP) -c $(Options) cpp/nspace.cpp -o cpp/nspace.o -I $(Lexing)

cpp/type.o : cpp/type.cpp cpp/type.h
	$(CPP) -c $(Options) cpp/type.cpp -o cpp/type.o -I $(Lexing)

$(Lexing)/lexing2023/stateset.o : $(Lexing)/lexing2023/stateset.cpp $(Lexing)/lexing2023/state.h $(Lexing)/lexing2023/stateset.h
	$(CPP) -c $(Options) $(Lexing)/lexing2023/stateset.cpp -o $(Lexing)/lexing2023/stateset.o -I $(Lexing)

$(Lexing)/lexing2023/filereader.o : $(Lexing)/lexing2023/filereader.cpp $(Lexing)/lexing2023/filereader.h
	$(CPP) -c $(Options) $(Lexing)/lexing2023/filereader.cpp -o $(Lexing)/lexing2023/filereader.o -I $(Lexing)

$(Lexing)/lexing2023/partition.o : $(Lexing)/lexing2023/partition.cpp $(Lexing)/lexing2023/partition.h $(Lexing)/lexing2023/state.h $(Lexing)/lexing2023/stateset.h
	$(CPP) -c $(Options) $(Lexing)/lexing2023/partition.cpp -o $(Lexing)/lexing2023/partition.o -I $(Lexing)

