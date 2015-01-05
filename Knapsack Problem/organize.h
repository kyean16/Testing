//Header for the merge Sort
#ifndef ORGANIZE_H
#define ORGANIZE_H

#include <vector>
#include "objects.cpp"
//#include "objects.cpp"
//#include "sort.cpp"



using namespace std;


class organize{
	private:
	public:
		organize();
		vector<objects> mergeSort(vector<objects> list);
		vector<objects> merged(vector<objects> left, vector<objects> right);
		objects addObjectGreedy(vector<objects>& list,int& weight, bool& maxAmount);
};

#endif