//Testing out BFS with the N Queen problem by Kevin Yean
//Board looks like this
/* 
0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 15
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Struct of nqueen
struct nqueen {
  int h;
  int g;
  vector <int> pos;
};

//Global Variables
int n;
vector <int> moves;
vector<nqueen> open; 
vector<nqueen>closed;

void setMoves()
{
	for(int i = 0 ; i < n*n ; i++)
	{
		if(i%n ==0)
		{
			moves.push_back(-1);
		}
		else if (i%n == 4)
		{
			moves.push_back(1);
		}
		else
		{
			moves.push_back(2);
		}
	}
}

//Check the board for wrong placement
int checkBoard(nqueen temp)
{
	int totalG = 0;
	int tempG = 0;
	//Column 
	for(int x = 0 ; x < n ; x++)
	{
		for(int i = 0 ; i<n; i++)
		{	
			//cout<<x+(n*i) <<endl;
			if(x+(n*i) == temp.pos[x+(n*i)])
			{
				tempG++;
			}
		}
		if (tempG >= 2)
		{
			totalG++;
		}
		tempG = 0;
	}
	int diagonal = n + (n - 3);
	//cout <<"Number of Diagonal is " << diagonal<<endl;

	// Diag =>
	int max = 2;
	bool increasing = true;
	int starting = (n*n-(n-1));
	for(int i = 0 ; i <diagonal ; i++)
	{
		if(i == diagonal/2)
		{
			//cout<<(diagonal/2);
			increasing = false;
		}
		int start = starting;
		for(int i = 0 ; i < max ; i++)
		{
			//cout<<start<< " ";
			if(start == temp.pos[start])
			{
				tempG++;
			}
			if(tempG >=2)
			{
				totalG++;
				tempG = 0;
				break;
			}
			start = start - (n+1);
		}
		//cout<<endl;

		if(increasing)
		{
			max++;
			starting++;
		}
		else
		{
			max--;
			starting = starting - (n);
		}
		tempG = 0;
	}
	// Diag <=
	max = 2;
	increasing = true;
	starting = (n*n-2);
	for(int i = 0 ; i <diagonal ; i++)
	{
		if(i == diagonal/2)
		{
			//cout<<(diagonal/2);
			increasing = false;
		}
		int start = starting;
		for(int i = 0 ; i < max ; i++)
		{
			//cout<<start<< " ";
			if(start == temp.pos[start])
			{
				tempG++;
			}
			if(tempG >=2)
			{
				totalG++;
				tempG = 0;
				break;
			}
			start = start - (n-1);
		}
		//cout<<endl;

		if(increasing)
		{
			max++;
			starting--;
		}
		else
		{
			max--;
			starting = starting - (n);
		}
		tempG = 0;
	}
	return totalG;
}

nqueen generateBoard()
{
	srand(time(NULL));
	nqueen startBoard; //Create initial board
	for(int i = 0 ; i < n*n; i++)
	{
		startBoard.pos.push_back(-1);
	}
	for(int i = 0 ; i < n*n ; i = i+n)
	{
		int temp = rand()%n+i;
		startBoard.pos[temp] = temp;
	}
	//cout<<endl;
	startBoard.h = 0;
	startBoard.g = 0;
	startBoard.g = checkBoard(startBoard);
	return startBoard;
}

//Print the board
void printBoard(nqueen tempBoard)
{
	cout<< "Board Layout: "<<endl;
	for(int i = 0 ; i < n*n ; i++)
	{
		if(i%n ==0 && i!= 0)
		{
			cout<<endl;
		}
		if(tempBoard.pos[i] == -1)
		{
			cout<<"0 ";
		}
		else
		{
			cout<<"1 ";
		}
	}
	cout<<endl<< "H:"<< tempBoard.h << " G:" << tempBoard.g<<endl;
}
bool checkClosed(nqueen board)
{
	for(int i = 0 ; i <closed.size() ; i++)
	{
		int check = 0;
		for(int x =0 ; x < n ; x++) //check 4 pos if it not matching skip to next one;
		{
			if(board.pos[x] != -1 && closed[i].pos[x] == board.pos[x])
			{
				check++;
			}
			
			else
			{
				check = 0;
				break;
			}
		}
		if(check == n) //Matching
		{
			return true;
		}
	}
	return false; //Not present

}

void right(nqueen board , int i)
{
	int loc = board.pos[i];
	board.pos[loc+1] = loc+1;
	board.pos[loc] = -1;
	board.h++;
	board.g = checkBoard(board);
	if(!checkClosed(board))
	{
		open.push_back(board);
		printBoard(board);
	}
}

void left(nqueen board , int i)
{
	int loc = board.pos[i];
	board.pos[loc-1] = loc-1;
	board.pos[loc] = -1;
	board.h++;
	board.g = checkBoard(board);
	if(!checkClosed(board))
	{
		open.push_back(board);
		printBoard(board);
	}
}

void createChildNodes(nqueen board)
{
	for(int i = 0 ; i<board.pos.size(); i ++)
	{
		if(board.pos[i] != -1)
		{
			int possibleMoves = moves[board.pos[i]];
			//cout<<possibleMoves<<endl;
			if(possibleMoves == -1)
			{
				right(board,i);
			}
			else if (possibleMoves == 2)
			{
				left(board,i);
				right(board,i);
			}
			else if(possibleMoves == 1)
			{
				left(board,i);
			}
		}
	}
}
//Merge
vector<nqueen> merge(vector<nqueen>left,vector<nqueen>right)
{
	vector<nqueen> merged;
	int l = 0;
	int r = 0;
	//compare left less
	while(l < left.size() && r < right.size())
	{
		if((left[l].g) + (left[l].h)  < right[r].g + right[r].h)
		{
			merged.push_back(left[l]);
			l++;
		}
		else if((left[l].g) + (left[l].h) > right[r].g + right[r].h) //right is less
		{
			merged.push_back(right[r]);
			r++;
		}
		//Equal push left
		else
		{
			merged.push_back(left[l]);
			l++;
		}
	}
	//If I empty add the rest of b;
	if(l == left.size())
	{
		while(r < right.size())
		{
			merged.push_back(right[r]);
			r++;	
		}
	}
	//If B empty add the rest of i;
	else if(r == right.size())
	{
		while(l < left.size())
		{
			merged.push_back(left[l]);
			l++;	
		}
	}
	return merged;
}

//Mergesort
vector<nqueen> mergeSort(vector<nqueen>list)
{
	int size = list.size();
	int middle = list.size()/2;
	vector<nqueen> left;
	vector<nqueen> right;
	if(size > 1) //Do as long as item are bigger than one;
	{
		//Left
		for(int i = 0 ; i < middle; i++)
		{
			left.push_back(list[i]);
		}
		left = mergeSort(left);

		//Right
		for(int i = middle ; i < list.size(); i++)
		{
			right.push_back(list[i]);
		}

		right = mergeSort(right);
	}
	else
	{
		return list;
	}
	return merge(left,right);
}

int main()
{
	while(n < 4)
	{
		cout << "Size of N Queen problem (Must be Higher than 4): ";
		cin >> n;
	}
	setMoves();
	nqueen initBoard = generateBoard();
	open.push_back(initBoard);
	int i = 0;
	printBoard(open[0]);
	while(open.size() != 0) //While open is not empty
	{
		if(open[0].g == 0)
		{
			cout<<"This is a solution!" <<endl;
			printBoard(open[0]);
			break;
		}
		createChildNodes(open[0]);
		closed.push_back(open[0]);
		open.erase(open.begin(),open.begin()+1);
		open = mergeSort(open);
		i++;
	}
	cout<<endl;
	cout<<open.size() << " ";
	cout<<closed.size() << " ";
	cout<<i;
	return 0;
}
