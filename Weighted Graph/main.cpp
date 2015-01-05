
#include <cstdlib>
#include <iostream>
#include "Searches.h"
#include <vector>

using namespace std;


int main()
{
	//Create cities
	City paris = City("Paris"); //0
	City london = City("London"); //1
	City venice = City("Venice");//2
	City munich = City("Munich");//3
	City barcelona = City("Barcelona");//4

	paris.CityAdd(1,140,5);//London
	paris.CityAdd(3,500,6); //Munich
	paris.CityAdd(4,5,8); //Barcelona

	london.CityAdd(0,140,10); //Paris
	london.CityAdd(2,200,0); //Venice
	london.CityAdd(3,10,6); //Munich

	venice.CityAdd(1,200,5);//London
	venice.CityAdd(3,40,6);//Munich

	munich.CityAdd(0,500,10); //Paris
	munich.CityAdd(1,10,5); //London
	munich.CityAdd(2,40,0); //Venice
	munich.CityAdd(4,60,8); //Barcelona

	barcelona.CityAdd(3,60,6); //Venice
	barcelona.CityAdd(0,5,10);//Paris

	//Vector of the cities
	vector <City> map;
	map.push_back(paris);
	map.push_back(london);
	map.push_back(venice);
	map.push_back(munich);
	map.push_back(barcelona);

	Searches search;
	cout<<search.PrintAdj(map);
	return 0;

}