#include <iostream>
#include "search.h"

using namespace std;

searches::searches()
{
	//Sorted
	foo.push_back(1);
	foo.push_back(3);
	foo.push_back(2);
	foo.push_back(5);
	foo.push_back(4);
	
}

void searches::selectionSort(vector <int> toDo)
{
	for(int i = 0 ; i < toDo.size(); i++)
	{
		int index = i;
		int value = toDo[i];
		for(int x = index ; x < toDo.size();x++)
		{
			if(value > toDo[x])
			{
				value = toDo[x];
				int indexNew = x;
				toDo[indexNew] = toDo[index];
				toDo[index] = value;
			}
		}
		for(int z =0 ; z <toDo.size();z++)
		{
			cout<<toDo[z]<< " ";
		}
		cout<<endl;
	}
}

void searches::bubbleSort(vector <int> toDo)
{

}