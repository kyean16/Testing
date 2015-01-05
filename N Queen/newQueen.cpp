//Testing out BFS with the N Queen problem by Kevin Yean
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Board looks like this
/* 
0 1 2 3
4 5 6 7
8 9 10 11
12 13 14 15
*/

int n = 4;

struct nqueen {
  bool board[16];
  int h;
  int g;
  vector <int> pos;
};

const int moves[16]={ -1, 2, 2, 1, 
                      -1, 2, 2, 1, 
                      -1, 2, 2, 1, 
                      -1, 2, 2, 1 };

vector<nqueen> open; 
vector<nqueen>closed;

//Create a random 4x4 board;
int checkBoard(nqueen temp)
{
	int totalG = 0;
	int tempG = 0;
	//Column 0+x 4n+x 8n+x 12n+x
	for(int x = 0 ; x < n ; x++)
	{
		for(int i = 0 ; i<n; i++)
		{	
			if(temp.board[(i*n+x)])
			{
				tempG++;
			}
			if(tempG == 2)
			{
				totalG++;
				tempG = 0;
				break;
			}
		}
		tempG = 0;
	}

	//Diagonal going this =>
	for(int x = 0 ; x < 5 ; x++)
	{
		int num;
		int max;
		if(x==0)
		{
			num =8;
			max = 14;
		}
		else if (x == 1)
		{
			num = 4;
			max = 15;
		}
		else if (x == 2)
		{
			num =0;
			max = 16;
		}
		else if (x == 3)
		{
			num = 1;
			max = 12;
		}
		else 
		{
			num = 2;
			max = 8;
		}
		for(int i = num ; i < max ; i = i+5)
		{
			if(temp.board[i] == true)
			{
				tempG++;
			}
			if(tempG == 2)
			{
				totalG++;
				tempG = 0;
				break;
			}	
		}
		tempG = 0;
	}
	//Diagonal
	for(int x = 0 ; x < 5 ; x++)
	{
		int num;
		int max;
		if(x==0)
		{
			num =1;
			max = 5;
		}
		else if (x == 1)
		{
			num = 2;
			max = 9;
		}
		else if (x == 2)
		{
			num =3;
			max = 13;
		}
		else if (x == 3)
		{
			num = 7;
			max = 14;
		}
		else 
		{
			num = 11;
			max = 15;
		}
		for(int i = num ; i < max ; i = i+3)
		{
			if(temp.board[i] == true)
			{
				tempG++;
			}
			if(tempG == 2)
			{
				totalG++;
				tempG = 0;
				break;
			}	
		}
		tempG = 0;
	}
	return totalG;
}

nqueen generateBoard()
{
	srand(time(NULL));
	nqueen startBoard; //Create initial board
	for(int i = 0 ; i < 16 ; i++)
	{
		startBoard.board[i] = false;
	}
	for(int i = 0 ; i < 16 ; i = i+4)
	{
		int temp = rand()%4+i;
		startBoard.pos.push_back(temp);
		startBoard.board[temp] = true;
	}
	startBoard.h = 0;
	startBoard.g = checkBoard(startBoard);
	return startBoard;
}

//Print the board
void printBoard(nqueen tempBoard)
{
	cout<< "Board Layout: "<<endl;
	for(int i = 0 ; i < 16 ; i++)
	{
		if(i%4 ==0 && i!= 0)
		{
			cout<<endl;
		}
		if(tempBoard.board[i])
		{
			cout<<"1 ";
		}
		else
		{
			cout<<"0 ";
		}
	}
	cout<<endl<< "H:"<< tempBoard.h << " G:" << tempBoard.g<<endl;
}
bool checkClosed(nqueen board)
{
	for(int i = 0 ; i <closed.size() ; i++)
	{
		int check = 0;
		for(int x =0 ; x < 4 ; x++) //check 4 pos if it not matching skip to next one;
		{
			if(closed[i].pos[x] == board.pos[x])
			{
				check++;
			}
			
			else
			{
				check = 0;
				break;
			}
		}
		if(check == 4) //Matchin
		{
			return true;
		}
	}
	return false; //Not present

}

void right(nqueen board , int i)
{
	int pos = board.pos[i];
	board.board[pos+1] = true;
	board.board[pos] = false;
	board.h++;
	board.g = checkBoard(board);
	board.pos[i] = pos+1;//Update the position;
	if(!checkClosed(board))
	{
		open.push_back(board);
		//printBoard(board);
	}
}

void left(nqueen board , int i)
{
	int pos = board.pos[i];
	board.board[pos-1] = true;
	board.board[pos] = false;
	board.h++;
	board.g = checkBoard(board);
	board.pos[i] = pos-1;//Update the position;
	if(!checkClosed(board))
	{
		open.push_back(board);
		//printBoard(board);
	}
}

void createChildNodes(nqueen board)
{
	for(int i = 0 ; i<board.pos.size(); i ++)
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

nqueen customBoard(int i,int b, int c, int d)
{
	nqueen board;
	board.board[i] = true;
	board.board[b] = true;
	board.board[c] = true;
	board.board[d] = true;

	board.pos.push_back(i);
	board.pos.push_back(b);
	board.pos.push_back(c);
	board.pos.push_back(d);

	board.h = 0;
	board.g = checkBoard(board);
	return board;
}

int main()
{
	nqueen initBoard = generateBoard();
	open.push_back(initBoard);
	int i = 0;
	while(open.size() != 0 && i < 10000) //While open is not empty
	{
		printBoard(open[0]);
		if(open[0].g == 0)
		{
			break;
		}
		createChildNodes(open[0]);
		closed.push_back(open[0]);
		open.erase(open.begin(),open.begin()+1);
		open = mergeSort(open);
		i++;
	}
	cout<<i;
	return 0;
}
