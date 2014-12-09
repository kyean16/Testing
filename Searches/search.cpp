#include <iostream>
#include <vector>
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

	fuu.push_back(7);
	fuu.push_back(6);
    fuu.push_back(7);
	fuu.push_back(7);
	fuu.push_back(6);
    fuu.push_back(7);
	fuu.push_back(6);
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
//Divede and Conquer, split the program into different set of problems of the same type
//Solve independtly, combine those solutions.
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

//Mergesort
vector<int> searches::mergeSort(vector<int>list)
{
	for(int i = 0 ; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}
	cout<<endl;
	int size = list.size();
	int middle = list.size()/2;
	vector<int> left;
	vector<int> right;
	if(size > 1) //Do as long as item are bigger than one;
	{
		//Left
		for(int i = 0 ; i < middle; i++)
		{
			left.push_back(list[i]);
		}
		left = mergeSort(left);

		//Right
		for(int i = middle ; i < list.size(); i++)
		{
			right.push_back(list[i]);
		}

		right = mergeSort(right);
	}
	else
	{
		return list;
	}
	return merge(left,right);
}

//Merge
vector<int> searches::merge(vector<int>left,vector<int>right)
{
	vector<int> merged;
	int l = 0;
	int r = 0;
	//compare left less
	while(l < left.size() && r < right.size())
	{
		if(left[l] < right[r])
		{
			merged.push_back(left[l]);
			l++;
		}
		else if(left[l] > right[r]) //right is less
		{
			merged.push_back(right[r]);
			r++;
		}
		//Equal push left
		else
		{
			merged.push_back(left[l]);
			l++;
		}
	}
	//If I empty add the rest of b;
	if(l == left.size())
	{
		while(r < right.size())
		{
			merged.push_back(right[r]);
			r++;	
		}
	}
	//If B empty add the rest of i;
	else if(r == right.size())
	{
		while(l < left.size())
		{
			merged.push_back(left[l]);
			l++;	
		}
	}
	for(int i = 0 ; i < merged.size() ; i++)
	{
		cout<<merged[i] << " ";
	}
	cout<< endl;
	return merged;
}

//Catching Errors