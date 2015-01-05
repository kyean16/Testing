import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

/** 
 * The Main class is responsible with:
 * 		- Setting the game basic rules:
 * 			 -number of sticks
 * 			 -the number of sticks allowed to be take each turn.
 * 			- Who goas first
 * 		- Who won
 * 		- Restart the game if the player wants to
 * 		- Save the result of the game
 * 			- Save it to file
 * 
 * 
 * @author Kevin Yean
 * @author Dakota Watson
 */

public class Main
{
	private int initNumSticks; //Integer for the initial number of sticks when the game starts.
	private int moveSticks; //Integer for the number of sticks allowed to be take from the pile.
	private boolean turn; //Boolean value to hold who goes first. True = AI; False = Human
	private String nameFile; //String to hold the name of the file.
	private int[][] ArraySticks; //2-D Array.
	
	//Constructor
	public Main()
	{
		setUp();
		setNameFile();
		nameChecker();
		runGame();
	}
	
	//setUp is responsible for setting the basic rules of the game from #sticks in the game, #sticks allowed to be taked each turn and who goes first.
	public void setUp()
	{
		initNumSticks = 12; //Assigns default value to initNumSticks.
		moveSticks = 4; //Assigns default value to moveSticks.
		turn = true; //AI goes first.
		//System.out.println(initNumSticks + " " + moveSticks);
	}
	
	//setFileName is responsible for setting the name of the file.
	public void setNameFile()
	{
		//Generates the name of the file given the initNumSticks and MoveSticks and who goes first.
		nameFile = ("stick" + initNumSticks + "and" + moveSticks + turn);
		//System.out.println(nameFile);
	}
	
	//NameChecker checks if nameFile is valid file name.
	public void nameChecker()
	{
		//If FileName exists use information from the 2-D array.
		try 
		{
			FileInputStream saveFile = new FileInputStream(nameFile);
			ObjectInputStream restore = new ObjectInputStream(saveFile);
			ArraySticks = (int[][]) restore.readObject();
			restore.close();
		} 
		catch (FileNotFoundException e) //If FileName does not exist create blank 2-D array.
		{
			ArraySticks = new int [moveSticks][initNumSticks]; //Assigns the dimensions of the 2-D array using initMoveSticks and moveSticks
			for(int i = 0 ; i < moveSticks ; i++)
			{
				for (int x = 0 ; x < initNumSticks ; x++)
				{
					ArraySticks [i][x] = 0;
				}
			}
		}
		catch (IOException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (ClassNotFoundException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//printSticks prints the remaining number of sticks using recursion
	public String printStick(int temp)
		{
			if ( temp == 0)
			{
				return ("No more Sticks left");
			}
			else if (temp == 1)
			{
				return ("The Remaining Number of Sticks is |");
			}
			else
			{
				return (printStick(temp-1) + "|");
			}
		}
	
	//runGame is responsible for running the game.
	public void runGame()
	{
		//Set up
		int numSticks = initNumSticks; //Number of Sticks
		AI artificial = new AI(initNumSticks, moveSticks,ArraySticks); //Creates a variable artificial.
		Player player = new Player(initNumSticks,moveSticks); //Creates a variable player.
		boolean winner = false; //True = AI won, False = won.
		
		//Initial Message
		System.out.println("The Stick Game.");
		System.out.println("Number of moves allowed: " + moveSticks + "\n");
		
		//Loop for the game until sticks reaches zero.
		while (numSticks != 0)
		{
			if (turn == true) //AI goes first
			{
				//AI
				int sticksTaken = artificial.AITurn(numSticks-1); // Sticks to be taken from the pile
				System.out.println(""  + printStick(numSticks) +" (" + numSticks+ ")");
				System.out.println("The AI takes " + sticksTaken + " sticks. \n");
				numSticks -= sticksTaken; //Removes number of Sticks
				if(numSticks == 0) //If the remaining number of sticks is zero the AI won.
				{
					System.out.println("The AI has won.");
					winner = true;
				}
				
				//Player
				else if (numSticks!= 0)
				{	
					System.out.println(""  + printStick(numSticks) +" (" + numSticks+ ")");
					System.out.print("The player takes: " );
					numSticks -= player.playerTurn(numSticks);
					System.out.println();
					if (numSticks == 0) //if the remaining number of sticks is zero the player won.
					{
						System.out.println("The player has won.");
						winner = false;
					}
				}
			}
			else //Player goes first
			{
				//Player
				//AI
			}
		}
		artificial.AILearning(winner); //Updates the 2-D array in Artificial.
		ArraySticks = artificial.getArraySticks(); //Updates ArraySticks with the game just played
		
		SaveAndLoad save = new SaveAndLoad(nameFile);
		save.saveArray(ArraySticks);
		
		System.out.print("Do you want to play again (yes or no)? ");
		if(player.playAgain()) //Restart game if the player wants too.
		{
			System.out.println();
			runGame();
		}
	}
}
