//Header for the merge Sort
#include "organize.h"
#include "objects.cpp"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

organize::organize(){
	//cout<<"here";
}

vector<objects> organize::mergeSort(vector<objects> list){
	int size = list.size();
	int middle = list.size()/2;
	vector<objects> left;
	vector<objects> right;
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
	return merged(left,right);
}

vector<objects> organize::merged(vector<objects> left, vector<objects> right){
	vector<objects> merged;
	int l = 0;
	int r = 0;
	//compare left less
	while(l < left.size() && r < right.size())
	{
		if(left[l].getWorth() < right[r].getWorth())
		{
			merged.push_back(left[l]);
			l++;
		}
		else if(left[l].getWorth() > right[r].getWorth()) //right is less
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
	return merged;
}

//Pick the item given the weight left over
objects organize::addObjectGreedy(vector<objects>& list,int& weight, bool& maxAmount){
	bool foundItem = false;
	int i = list.size()-1; //Start from most expensive;
	while(!foundItem) //Keep doing as long as item is not found.
	{
		if(list[i].getSize() <= weight && list[i].getNum() > 0)
		{
			foundItem = true;
			weight = weight - list[i].getSize();
			list[i].decreaseNumberOfObjects();
			return list[i];
		}
		i--;
	}
	maxAmount = true;
	return list[0];
}
