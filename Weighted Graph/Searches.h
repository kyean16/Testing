#include <vector>
#include "Node.h"

using namespace std;

class Searches{
	private:
	public:
		Searches();
		string PrintAdj(vector<City> map);
};

Searches::Searches()
{

}
string Searches::PrintAdj(vector<City> map)
{
	string ret = "";
	for(int i = 0 ; i <map.size();i++)
	{
		City::node* Ptr = map[i].root;
		for(int x = 0 ; x <map.size();x++)
		{
			if(x == i)
			{
				ret += "0 ";
			}
			else if (Ptr->location == x)
			{
				ret += to_string(Ptr->weight) + " ";
				if(Ptr->adj != NULL)
				{
					Ptr=Ptr->adj;
				}
			}
			else
			{
				ret += "∞ ";
			}
		}
		ret += "\n";
	}
	return ret;
}