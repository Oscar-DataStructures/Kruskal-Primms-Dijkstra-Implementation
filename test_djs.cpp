/*
Oscar Martinez, Xinduo Fan
CS 271
Dr. Lall
Project 9
*/


#include <iostream>
#include <string>
#include <cassert>
#include "djs.h"


// ==================== Test Default Constructor/Make Method ===================
void test_defaultConstructor_make()
{
	djs<int> a;
	a.makeSet(0);
	a.makeSet(1);

	assert(a.display_setMap() == "0 : 0\n1 : 1\n");

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{
	djs<int> a;
	a.makeSet(0);
	a.makeSet(1);

	djs<int> b(a);

	assert(b.display_setMap() == "0 : 0\n1 : 1\n");

}


// =========================== Test Union Sets  Method =========================
void test_unionSets_findSet()
{
	djs<int> a;
	a.makeSet(0);
	a.makeSet(1);
	a.makeSet(2);
	a.makeSet(3);
	a.makeSet(4);
	a.makeSet(5);

	assert(a.findSet(1) == 1);
	a.unionSets(0, 1);
	assert(a.findSet(1) == 0);

	assert(a.findSet(3) == 3);
	a.unionSets(2, 3);
	assert(a.findSet(3) == 2);

	assert(a.findSet(4) == 4);
	a.unionSets(0, 4);
	assert(a.findSet(4) == 0);

	assert(a.findSet(5) == 5);
	a.unionSets(2, 5);
	assert(a.findSet(5) == 2);

	assert(a.findSet(2) == 2);
	a.unionSets(0, 2);
	assert(a.findSet(2) == 0);
}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor_make();
	std::cout << "Default Constructor/Make Test:		|Passed|" << std::endl;
	test_copyConstructor();
	std::cout << "Copy Constructor Test:			|Passed|" << std::endl;
	test_unionSets_findSet();
	std::cout << "Union/Find Set Test:			|Passed|" << std::endl;


	return 0;
}
