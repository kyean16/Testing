//Header of the class object that will hold value for the Knapsack problem



#include <iostream>
#include <cstdlib>

using namespace std;

class objects{
	private: //Hold basic information of the object
		int numberOfObjects;
		string nameOfObject;
		int worth;
		int size;
	public:
		objects(int numObjects, string name, int value, int weight);
		void toString();
		int getWorth();
		int getSize();
		int getNum();
		string getName();
		void setNum(int n);
		void decreaseNumberOfObjects();
		void increaseNumberOfObjects();
};
