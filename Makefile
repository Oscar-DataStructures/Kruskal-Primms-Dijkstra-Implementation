
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_graph coast countingstars

//==============================================================================

test_graph.o: test_graph.cpp graph.h graph.cpp
	g++ $(CPPOPTIONSS) -c test_graph.cpp

test_graph: test_graph.o
	g++ -o test_graph test_graph.o

coast.o: coast.cpp graph.h graph.cpp
	g++ $(CPPOPTIONSS) -c coast.cpp

coast: coast.o
	g++ -o coast coast.o

countingstars.o: countingstars.cpp 
	g++ $(CPPOPTIONSS) -c countingstars.cpp

countingstars: countingstars.o
	g++ -o countingstars countingstars.o



//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
