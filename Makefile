
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_graph

//==============================================================================

test_graph.o: test_graph.cpp graph.h graph.cpp
	g++ $(CPPOPTIONSS) -c test_graph.cpp

test_graph: test_graph.o
	g++ -o test_graph test_graph.o



//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
