import java.io.InputStreamReader;
import java.io.Reader;
import java.util.Scanner;

/** Player is responsible for the players moves.
 * 
 * @author Kevin Yean
 * @author Dakota Watson
 *
 */

public class Player 
{
	private Reader reader; // Reader is responsible for reading the input of the plauer.
	private int initNumSticks; //Integer for the number of sticks when the game starts.
	private int moveSticks; //Integer for the number of sticks allowed to be take from the pile.
	private int remainingSticks; //Integer to hold the number of remaining sticks in the pile
	
	//Constructor is responsible for setting up the number of sticks as well as the number of moves.
	public Player(int tempNumSticks, int tempMoveSticks)
	{
		initNumSticks = tempNumSticks;//Assigns tempNumSticks to numSticks.
		moveSticks = tempMoveSticks; //Assigns tempMoveSticks to moveSticks.
		reader =  new InputStreamReader( System.in );//Assigns System.in.
	}
	
	//PlayerTurn is responsible for allowing the correct number of sticks to be taken from the pile of remaining sticks.
	public int playerTurn(int sticks)
	{
		remainingSticks = sticks; //Updates the remaining number of sticks
		Scanner in = new Scanner(reader);
		boolean good = false;
		int i = 0;
		
		while (good == false)
		{
			in.hasNextLine();
			String line = in.nextLine();
            line = line.trim().toLowerCase();
            try
            {
            	i = Integer.parseInt(line); //Parses information from String to int. 
            	good = rangeNumber(i);
            	if(good == false)
            	{
            		System.out.print ("Invalid Number, try again: ");
            	}
            }
            catch (NumberFormatException ex ) //Catch is the value is not a number.
            {
            	System.out.print("This is not a number,try again: ");
            }
            	
		}
		return i;
	}
	
	//rangeNumber is responsible for making sure the name input by the user is not too big or too small.
	public boolean rangeNumber(int temp)
	{
		if(temp > moveSticks || temp > remainingSticks || temp <=0)
		{
			return false; //If temp is bigger than moves allowed, smaller than zero or larger than the remaining number of sticks
		}
		return true;
	}
	
	//playAgain is responsible for getting the response back from the player of whether or not the player wants to play again.
	public boolean playAgain()
	{
		//True = play again, False = stop playing
		Scanner in = new Scanner(reader); //Input from the player.
		String line = " ";
		
		while(in.hasNextLine())
		{
			line = in.nextLine();
            line = line.trim().toLowerCase();

    		if (line.equals("yes"))
    		{
    			return true;
    		}
    		else if (line.equals("no"))
    		{
    			return false;
    		}
    		else
    		{
    			System.out.println("I do not understand, try again: ");
    		}
		}
		return false;
	}
}
