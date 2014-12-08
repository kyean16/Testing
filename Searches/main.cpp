#include <iostream>
#include "search.cpp"

using namespace std;

int main()
{
	searches test;
	test.selectionSort(test.foo);
	cout<<endl;
	test.bubbleSort(test.foo);
	cout<<endl;
	return 0;
}