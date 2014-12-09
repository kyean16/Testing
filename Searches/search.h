#include <vector>
#include <iostream>

using namespace std;

class searches
{
	private:
	public:
		vector <int> foo;
		vector <int> fee;
		vector <int> fuu;
		vector <int> fuus;
		searches();
		void selectionSort(vector <int> toDo);
		void bubbleSort(vector <int> toDo);
		void binarySearch(int key, int size);
		vector<int>  merge(vector<int>left,vector<int>right);
		vector<int> mergeSort(vector<int>list);
    
};