
BST::BST()
{
	root = NULL; //Roots points to nothing.
}

BST::node* BST::createLeaf(int value)
{
	node* n = new node;
	n->value = value;
	n->left = NULL;
	n->right = NULL;

	return n; //return a pointer that points to this.
}

void BST::addLeaf(int value)
{
	//Call addLeafPrivate will start at the root no worry about location.
	//Always search where to place it.
	AddLeafPrivate(value,root);
}

//Searching where to put it.
void BST::AddLeafPrivate(int value,node* Ptr)
{
	if(root == NULL)//Empty
	{
		root = createLeaf(value);
	}
	else if(value < Ptr->value) //Left
	{
		if(Ptr->left != NULL) //Left pointing traverse!
		{
			AddLeafPrivate(value,Ptr->left);
		}
		else
		{
			Ptr->left = createLeaf(value);
		}
	}
	else if(value > Ptr->value) //Right
	{
		if(Ptr->right != NULL) //Left pointing traverse!
		{
			AddLeafPrivate(value,Ptr->right);
		}
		else
		{
			Ptr->right = createLeaf(value);
		}
	}
	else //Equal
	{
		cout<< "The value " << value << " has already been added to the tree." <<endl;
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) //In order traversal
{
	//Recursively traverse the tree.
	if(root != NULL)
	{
		if(Ptr->left != NULL)
		{
			PrintInOrderPrivate(Ptr->left);
		}
		cout << Ptr -> value << " ";

		if(Ptr->right != NULL)
		{
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty." <<endl;
	}
}

BST::node* BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key,root);
}

BST::node* BST::ReturnNodePrivate(int key,node* Ptr)
{
	if(Ptr != NULL)
	{
		if(Ptr -> value == key)
		{
			return Ptr;
		}
		else
		{
			if(key < Ptr ->value)
			{
				return ReturnNodePrivate(key, Ptr->left);
			}
			else
			{
				return ReturnNodePrivate(key, Ptr ->right);
			}
		}
	}
	else
	{
		return NULL;
	}
}

int BST::ReturnRootKey()
{
	if(root!=NULL)
	{
		return root->value;
	}
	else
	{
		return -1000;
	}
}

//Return a string of whether or not the key is found in Depth First Search
string BST::DepthFirstSearch(int key)
{
	stack <node*> dfs; //Stack for the search
	dfs.push(root); //Push the root in the stack, this is where the search will begin.
	string nodesVisited; //Prints the nodes visited
	while(!dfs.empty()) //Continue the search as long as the stack is not empty
	{
		node* Ptr = dfs.top(); //Assign a new node the top of the stack
		nodesVisited += " " + to_string(Ptr->value); //Prints node visited
		dfs.pop(); //Pop
		if(Ptr -> value == key) //Check if the value is the right one if it is return
		{
			cout<< nodesVisited <<endl;
			return ("Found key: " + to_string(key));
		}
		else{ //If it is not empty push more things onto the stack
			if(Ptr->right!= NULL) //If the right is not empty push it
			{
				dfs.push(Ptr->right);
			}
			if(Ptr->left != NULL) //If left is not empty push it
			{
				dfs.push(Ptr->left);
			}
		}
	}
	cout<< nodesVisited <<endl;
	return ("Did not find key: " + to_string(key)); //Exit the while loop without finding the result.
}


string BST::DepthLimitedSearch(int key, int depth) //Call private method as it uses the root node.
{
	cout<< "Nodes visited: ";
	if(DepthLimitedSearchPrivate(key,depth,root,0))
	{
		return (" , Found key: " + to_string(key));
	}
	else
	{
		return ("\nDid not found key: " + to_string(key));
	}
	
}

bool BST::DepthLimitedSearchPrivate(int key, int depth , node* Ptr ,int currentdepth)
{
	stack <node*> dls;
	cout<<Ptr->value<<" ";
	bool foundKey = false;
	if(Ptr->value == key)
	{
		cout<< "\nAt depth: " + to_string(currentdepth);
		foundKey = true;
	}
	else if (depth != 0)
	{
		if(Ptr->right!= NULL)
		{
			dls.push(Ptr->right);
		}
		if(Ptr->left != NULL)
		{
			dls.push(Ptr->left);
		}
		while(!dls.empty() && foundKey == false)
		{
			foundKey = DepthLimitedSearchPrivate(key, depth-1,dls.top(), currentdepth+1); //Recusively call the method iwith a decreased depth.
			dls.pop();
		}
	}
	return foundKey;
}

int totalNodes = 0;
bool found = false;
string BST::IterativeDeepening(int key)
{
	int depth = 0;
	int totalNodesPrev = totalNodes;
	while(!IterativeDeepeningPrivate(key,depth,root)) //Increase the depth by one as long as it not found 
	{
		if(totalNodes == totalNodesPrev) //If node result is the same quit
		{
			break;
		}
		totalNodesPrev = totalNodes;
		totalNodes = 0;
		cout<<endl;
		depth ++;
	}
	if(found == true)
	{
		found = false;
		totalNodes = 0;
		return "\nFound Key: " + to_string(key);
	}
	return ("\nDid not find key: " + to_string(key));
}

bool BST::IterativeDeepeningPrivate(int key, int depth, node*Ptr) //Recusively call the method is an increase of depth every time
{
	stack <node*> dls;
	cout<<Ptr->value<<" ";
	bool foundKey = false;
	totalNodes++;
	if(Ptr->value == key)
	{
		foundKey = true;
		found = true;
	}
	else if (depth != 0)
	{
		if(Ptr->right!= NULL)
		{
			dls.push(Ptr->right);
		}
		if(Ptr->left != NULL)
		{
			dls.push(Ptr->left);
		}
		while(!dls.empty() && foundKey == false) //Call it to go back
		{
			foundKey = IterativeDeepeningPrivate(key, depth-1,dls.top());
			dls.pop();
		}
	}
	return foundKey;
}
string BST::BreathSearchFirst(int key)
{
	if(BreathSearchFirstPrivate(key,root))
	{
		return "\nFound key: " + to_string(key);
	}
	else
	{
		return "\nDid not find key: " + to_string(key);
	}
}

bool BST::BreathSearchFirstPrivate(int key, node* Ptr) 
{
	queue <node*> bfs; //Queue
	cout<<"Nodes visited: ";
	bfs.push(Ptr);
	while(!bfs.empty())
	{
		Ptr = bfs.front();
		if(Ptr->value == key)
		{
			cout<<Ptr->value << " ";
			return true;
		}
		else
		{
			if(Ptr->left != NULL)
			{
				bfs.push(Ptr->left);
			}
			if(Ptr->right != NULL)
			{
				bfs.push(Ptr->right);
			}
			cout<<Ptr->value << " ";
			bfs.pop();
		}
	}
	return false;
}

void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(key);
	if(Ptr != NULL)
	{
		cout<<"Parent Node = " << Ptr->value <<endl;

		//Information from the children.
		Ptr->left == NULL ? //Boolean true or false, true 1, false 2
		cout << "Left Child = NULL" << endl:
		cout << "Left Child = " << Ptr->left->value <<endl;

		Ptr->right == NULL ? //Boolean true or false, true 1, false 2
		cout << "Right Child = NULL" << endl:
		cout << "Rigt Child = " << Ptr->right->value <<endl;
	}
	else
	{
		cout<< "The node " << key << "is not in the tree"<<endl;
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
	if(root == NULL)
	{
		cout << "The tree is empty \n";
		return -1000;
	}
	else
	{
		if(Ptr->left != NULL)
		{
			return FindSmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->value;
		}
	}
}

void BST::RemoveNode(int key) //call private
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if(root != NULL)
	{
		//Does the root note contain the match
		if(root->value ==key)
		{
			RemoveNodeMatch();
		}
		else
		{
			if(key < parent->value && parent ->left != NULL)
			{
				parent -> left -> value == key?
				RemoveMatch(parent, parent->left,true):
				RemoveNodePrivate(key,parent->left);
			}
			else if(key > parent->value && parent ->right != NULL)
			{
				parent -> right -> value == key?
				RemoveMatch(parent, parent->right,false):
				RemoveNodePrivate(key,parent->right);
			}
			else
			{
				cout <<"The key was not found";
			}
		}
	}
	else
	{
		cout << "There is nothing in the tree" <<endl;
	}
}


void BST::RemoveNodeMatch()
{
	if(root!=NULL)
	{
		node* delPtr = root;
		int rootValue = root->value;
		int smallestInRightSubtree; //Find smallest key and put it back as the root key and delete it

		// Case 0 - 0 Children
		if(root -> left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		//Case 1-1 Child
		else if(root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The  root node with value: " << rootValue << "the new value is"<< root->value<<endl;
		}
		else if(root->right == NULL && root->left != NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The  root node with value: " << rootValue << "the new value is"<< root->value<<endl;

		}
		//Case 2-2 Children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree,root);
			root->value = smallestInRightSubtree;
			cout << "The root key was overwritten."<<endl;
		}
	}
	else
	{
		cout << "Can not remove root. The tree is empty."<<endl;
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if(root != NULL)
	{
		node* delPtr;
		int matchValue = match->value;
		int smallestInRightSubtree; //Case node has two children

		//Case 0
		if(match->left == NULL && match->right == NULL)
		{
			delPtr = match;
			left == true? 
			parent -> left = NULL:
			parent->right = NULL;
			delete delPtr;
			cout << "The node was removed.";
		}
		//Case 1
		else if (match->left == NULL && match->right != NULL)
		{
			left = true?
			parent->left = match->right:
			parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
		}
		//Case 2
		else if (match->right == NULL && match->left != NULL)
		{
		left == true?
		parent->left = match->left:
		parent->right = match -> left;
		delPtr = match;
		delete delPtr;
		}
		//Case 3
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree,match);
			match->value =smallestInRightSubtree;
		}
	}
	else
	{
		cout<< "Can not remove match. The tree is empty" << endl;
	}
}



