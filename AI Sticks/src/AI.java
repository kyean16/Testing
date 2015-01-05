import java.util.ArrayList;

/** This class is responsible for:
 * 		- Setting up a 2-D Array from the information from Main
 * 		- Update the 2-D array if a save file exists
 * 		- Give the best possible choice for the AI to take given the 2-D array
 * 
 * @author Kevin Yean
 * @author Dakota Watson
 *
 */

public class AI
{
	private int initNumSticks; //Integer for the initial number of sticks when the game starts.
	private int moveSticks; //Integer for the number of sticks allowed to be take from the pile.
	private int[][] ArraySticks; //2-D array.
	private ArrayList<Integer> movesDone = new ArrayList<Integer>(); //ArrayList of 2-D array meant to remember moves done by the AI, odd cells = moves and
																	// even cells = numSticks
	
	//Constructor that sets the information that the AI will use
	public AI(int tempNum, int tempMoveSticks, int[][] array)
	{
		initNumSticks = tempNum; //Assigns tempNum to initNumSticks.
		moveSticks = tempMoveSticks; //Assigns tempMoveSticks to moveSticks.
		ArraySticks = new int [moveSticks][initNumSticks];; //Assigns the dimensions of the 2-D array using initMoveSticks and moveSticks
		
		//Sets up the learning done by the AI in the 2-D Array.
		for(int i = 0 ; i < moveSticks ; i++)
		{
			for (int x = 0 ; x < initNumSticks ; x++)
			{
				if(i == x) //If number of i and x are equals put 1 instead of zero to indicate that if it the best move to do with the remaining number of sticks.
				{
					ArraySticks [i][x] = 1;
				}
				else
				{
					ArraySticks [i][x] = array [i][x];
				}
			}
		}
	}
	
	//AITurn is responsible for picking the how many number of sticks to take given the remaining number of sticks from the 2-D array information.
	public int AITurn(int sticks)
	{
		int num = ArraySticks [0][sticks]; //Sets the initial number of the number to beat.
		int move = 0; //Holds the current number of sticks to remove to the first row.
		for(int i = 1; i < moveSticks ; i++) //Checks each possible moves and see which one is the best
		{
			if(num <= ArraySticks[i][sticks]) //Changes which move to do to if the int in the 2-D cell is bigger or equal than num
			{
				num = ArraySticks [i][sticks];
				move = i;
			}
		}
		AIMoves(move,sticks);
		return (move + 1); // The +1 is because arrays start at zero.
	}
	
	// AIMoves is responsible for keeping track of which moves was done and with the specific number of sticks remaining at the time.
	public void AIMoves(int move, int sticks)
	{
		movesDone.add(move);
		movesDone.add(sticks);
	}	
	//AILearning is responsible for updating the 2-D array given the result of the match.
	public void AILearning(boolean result)
	{	
		if(result == true)//AI Won, each array cell gets +1;
		{
			while(movesDone.size() != 0)
			{
				ArraySticks [movesDone.get(0)] [movesDone.get(1)] ++;
				movesDone.remove(0);
				movesDone.remove(0);
			}
		}
		else //AI lost, each array cell gets -1;
		{
			while(movesDone.size() != 0)
			{
				ArraySticks [movesDone.get(0)] [movesDone.get(1)] --;
				movesDone.remove(0);
				movesDone.remove(0);
			}
		}
	}
	
	//Prints the current look of the 2-D Array
	public String toString()
	{
		String line = "";
		for(int i = 0 ; i < moveSticks ; i++)
		{
			for (int x = 0 ; x < initNumSticks ; x++)
			{
				line += (ArraySticks[i][x] + " ");
			}
			line += "\n";
		}
		return line;
	}
	
	//getArraySticks return the 2-D Array.
	public int[][] getArraySticks()
	{
		return ArraySticks;
	}
}
