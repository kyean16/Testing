#include <list>

using namespace std;

class City{
	private:
	public:
		struct node{
			int location;
			int weight;
			int heuristic;
			node* adj;
		};
		//Global
		string Name;
		node* root;
		City(string name);
		void CityAdd(int arrayLoc, int distance,int h);
};

City::City(string name)
{
	Name = name;
	root = NULL;
}
void City::CityAdd(int arrayLoc, int distance,int h)
{
	if(root == NULL)
	{
		node* n = new node;
		n->location = arrayLoc;
		n->weight = distance;
		n->heuristic = h;
		n->adj = NULL;
		root = n;
	}
	else
	{
		node* Ptr = root;
		while(Ptr->adj != NULL)
		{
			//cout<< Ptr->weight <<endl;
			Ptr = Ptr->adj;
		}
		node* n = new node;
		n->location = arrayLoc;
		n->weight = distance;
		n->heuristic = h;
		n->adj = NULL;
		Ptr->adj = n;
	}
}