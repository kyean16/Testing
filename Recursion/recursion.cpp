#include "recursion.h"
#include <iostream>

using namespace std;

recursion::recursion()
{
}

int recursion::recursionBottomUp(int x)
{
	if(x == 0)
	{
		cout<< x << " ";
		return 0;
	}
	else
	{
		cout<< x << ", ";
		return recursionBottomUp(x-1) + 1;
	}
}


//Function that takes in a number of stacks and prints the steps needed to do the tower of hanoi problem
void recursion::towerOfHanoi(int stacks,string a,string b,string c)
{
	if(stacks>0)
	{
		towerOfHanoi(stacks-1,a,c,b);
		cout<< "Put stacks number: "<< stacks<< " " << a << " to " << c << endl;
		towerOfHanoi(stacks-1,b,a,c);
	}
}
		