#include <iostream>
#include "search.h"

using namespace std;

searches::searches()
{
	//Sorted
	foo.push_back(10);
	foo.push_back(2);
	foo.push_back(3);
	foo.push_back(4);
	foo.push_back(5);
	foo.push_back(6);
	foo.push_back(7);
	foo.push_back(8);
	foo.push_back(9);
	foo.push_back(1);
}

void searches::selectionSort(vector <int> toDo)
{
	for(int i = 0 ; i < toDo.size(); i++)
	{
		int index = i;
		int indexNew = i;
		int value = toDo[i];
		for(int x = index ; x < toDo.size();x++)
		{
			if(value > toDo[x])
			{
				value = toDo[x];
				indexNew = x;
			}
		}
		toDo[indexNew] = toDo[index];
		toDo[index] = value;
		for(int z =0 ; z <toDo.size();z++)
		{
			cout<<toDo[z]<< " ";
		}
		cout<<endl;
	}
}

void searches::bubbleSort(vector <int> toDo)
{
	for(int i = 0 ; i < toDo.size(); i++)
	{
		for(int x = 0 ; x < toDo.size()-1;x++)
		{
			if(toDo[x] > toDo[x+1])
			{
				int temp = toDo[x];
				toDo[x] = toDo[x+1];
				toDo[x+1] = temp;
			}
		}
		for(int z =0 ; z <toDo.size();z++)
		{
			cout<<toDo[z]<< " ";
		}
		cout<<endl;
	}
}

void searches::binarySearch(int key, int size)
{
	for(int i = 0 ; i <size ; i++)
	{
		fee.push_back(i+1);
	}
	int start = 0;
	int end = size-1;
	int currentSize= end - start;
	int middle = (end-start)/2;
	cout<<"From " << start+1 << " to " << end+1 << endl;
	while(currentSize > 2 && key != fee[middle])
	{
		if(key < fee[middle]) //Check if less
		{
			start = start;
			end = middle;
			currentSize = end-start;
			middle = (end-start)/2+start;
			cout<<"From " << start+1 << " to " << end+1 << endl;
		}
		else if(key > fee[middle]) //Check if more
		{
			start = middle;
			end = end;
			currentSize = end-start;
			middle = (end-start)/2+start;
			cout<<"From " << start+1 << " to " << end+1 << endl;
		}
	}
	if(currentSize <= 2)
	{
		if(key == fee[start] || key == fee[end])
		{
			cout<<"Found " << key <<endl;
		}	
	}
	if(key == fee[middle])
	{
		cout<<"Found " << key <<endl;
	}
}