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


// ======================= Test Default Constructor Method =====================
void test_defaultConstructor()
{
	djs<int> a;
	a.makeSet(0);
	a.makeSet(1);
	a.makeSet(2);
	a.makeSet(3);

	cout << a.display_setMap() << endl;

	a.unionSets(0, 1);

	cout << a.display_setMap() << endl;

}


// ========================= Test Copy Constructor Method ======================
void test_copyConstructor()
{


}


// ============================= Test Make Set Method ==========================
void test_makeSet()
{


}


// =========================== Test Union Sets  Method =========================
void test_unionSets()
{


}


// ============================ Test Find Set  Method ==========================
void test_findSet()
{


}


// ==================================== Main ===================================
// =============================================================================
int main()
{
	test_defaultConstructor();
	std::cout << "Default Constructor Test:	|Passed|" << std::endl;
	// test_copyConstructor();
	// std::cout << "Copy Constructor Test:		|Passed|" << std::endl;
	// test_makeSet();
	// std::cout << "Make Set Test:			|Passed|" << std::endl;
	// test_unionSets();
	// std::cout << "Union Set Test:			|Passed|" << std::endl;
	// test_findSet();
	// std::cout << "Find Set Test: 			|Passed|" << std::endl;

	return 0;
}
