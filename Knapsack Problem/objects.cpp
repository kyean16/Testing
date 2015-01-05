//Body of the class object that will hold value for the Knapsack problem
#ifndef OBJECTS_H
#define OBJECTS_H

#include "objects.h"
#include <iostream>
#include <cstdlib>

using namespace std;

objects::objects(int numOfObjects,string name, int value, int weight){
	nameOfObject = name;
	numberOfObjects = numOfObjects;
	worth = value;
	size = weight;
}

//Prints the number of objects for that specific one
void objects::toString(){
	cout<< "Value: " <<worth<< ", Name: " << nameOfObject<< ", Weight: "
	<<size <<", Amount: " << numberOfObjects <<endl;
}

int objects::getWorth(){
	return worth;
}
int objects::getSize(){
	return size;
}
string objects::getName(){
	return nameOfObject;
}
int objects::getNum(){
	return numberOfObjects;
}

void objects::setNum(int n){
	numberOfObjects = n;
}
//Decrease by 1
void objects::decreaseNumberOfObjects(){
	numberOfObjects = numberOfObjects -1;
}
//Increase by 1
void objects::increaseNumberOfObjects(){
	numberOfObjects = numberOfObjects +1;
}

#endif