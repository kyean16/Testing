#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main()
{

	int Tree[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,80,87};
	BST myTree ;

	//cout << "Printing the tree in order:\n ";
	//myTree.PrintInOrder();
	//cout << "Printing the tree in order:\n ";
    for(int i = 0 ; i < 16 ; i++)
    {
    	myTree.addLeaf(Tree[i]);
    }
   // myTree.PrintInOrder();
    cout<<endl;
    //cout<<myTree.DepthFirstSearch(21) << endl;
    cout<< myTree.BreathSearchFirst(32) << endl<<endl;


	return 0;
}