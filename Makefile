
CPPOPTIONS = -c -g -Wall -std=c++0x

all: test_graph test_djs test_pqueue

//==============================================================================

test_graph.o: test_graph.cpp graph.h graph.cpp
	g++ $(CPPOPTIONSS) -c test_graph.cpp

test_graph: test_graph.o
	g++ -o test_graph test_graph.o

test_djs.o: test_djs.cpp djs.h djs.cpp
	g++ $(CPPOPTIONSS) -c test_djs.cpp

test_djs: test_djs.o
	g++ -o test_djs test_djs.o

test_pqueue.o: test_pqueue.cpp pqueue.h pqueue.cpp
	g++ $(CPPOPTIONSS) -c test_pqueue.cpp

test_pqueue: test_pqueue.o
	g++ -o test_pqueue test_pqueue.o



//==============================================================================
//==============================================================================
tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a all
