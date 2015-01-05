/* Author: Kevin Yean
Testing the KnackSack Problem for testing different types of algorithm to 
find the best possible option
*/

#include <iostream>
#include <cstdlib>
#include <vector>

#include "organize.cpp"

using namespace std;

int main(){
	//Backpack weight
	int backweight = 100;
	int totalValue = 0;
	vector<objects> stolenItems;
	//List of Items to be stored in the bagpack;
	cout<<endl<< "The weight allowed by our bag is " << backweight <<endl<<endl;

	//List of total items available
	vector<objects> ListOfItems;

	{
		objects cash = objects(500,"Cash",1 , 1) ; //Quantity, Name, Worth, Weight
		objects wallet = objects(1,"Wallet",90, 10);
		objects car = objects(1500,"Cash",2 , 1000) ; //Quantity, Name, Worth, Weight
		objects painting = objects(1,"Painting",100, 3);
		objects tv = objects(1,"TV",40 , 4) ; //Quantity, Name, Worth, Weight
		objects table = objects(2,"Table",15, 70);
		objects trophy = objects(5,"Trophyy",1, 1) ; //Quantity, Name, Worth, Weight

		ListOfItems.push_back(cash);
		ListOfItems.push_back(wallet);
		ListOfItems.push_back(car);
		ListOfItems.push_back(painting);
		ListOfItems.push_back(tv);
		ListOfItems.push_back(table);
		ListOfItems.push_back(trophy);
		//cash.printNumberOfObjects();
	}
	
	/*for(int i = 0 ; i < ListOfItems.size() ; i++)
	{
		ListOfItems[i].toString();
	}
	cout<<endl;*/

	organize orderList;
	ListOfItems = orderList.mergeSort(ListOfItems);
		for(int i = 0 ; i < ListOfItems.size() ; i++)
	{
		ListOfItems[i].toString();
	}

	cout<<endl;

	bool maxAmount = false;
	//Add objects a long as you have space in your bag
	while(backweight != 0 && !maxAmount)
	{
		objects temp = orderList.addObjectGreedy(ListOfItems,backweight,maxAmount);
		if(!maxAmount)
		{
			bool placed = false;
			for(int i = 0 ; i < stolenItems.size(); i++)
			{
				if(stolenItems[i].getName() == temp.getName())
				{
					totalValue += temp.getWorth();
					stolenItems[i].increaseNumberOfObjects();
					placed = true;
					break;
				}
			}
			if(placed == false)
			{
				temp.setNum(1);
				totalValue += temp.getWorth();
				stolenItems.push_back(temp);

			}
		}
	}

	for(int i = 0 ; i < ListOfItems.size() ; i++)
	{
		ListOfItems[i].toString();
	}

	cout<<endl<<"Objects stolen" << endl<<endl;

	for(int i = 0 ; i < stolenItems.size() ; i++)
	{
		stolenItems[i].toString();
	}
	cout<<"You've earned " <<totalValue << "$!" <<endl;
	cout<<endl;
	return 0;
}

