//Interface of BST

using namespace std;

class BST
{

private:

	struct node
	{
		int value;
		node* left;
		node* right;
	};

	//Root pointer
	node* root;

	void AddLeafPrivate(int key,node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int key, node* Ptr);
	int FindSmallestPrivate(node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveNodeMatch();
	void RemoveMatch(node* parent,node* match, bool left);//Indicate relation with parents
	bool DepthLimitedSearchPrivate(int key, int depth , node* Ptr, int currentdepth);
	bool IterativeDeepeningPrivate(int key, int depth, node*Ptr);
	bool BreathSearchFirstPrivate(int key, node* Ptr);

public:
	//Functions
	BST();
	node* createLeaf(int key);
	void addLeaf(int key);
	void PrintInOrder();
	node* ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key); //Start recursive
	string DepthFirstSearch(int key);
	string DepthLimitedSearch(int key, int depth);
	string IterativeDeepening(int key);
	string BreathSearchFirst(int key);
};