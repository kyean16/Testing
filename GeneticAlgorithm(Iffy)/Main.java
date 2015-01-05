/** This is the main class of the program that uses genetic algorithm to find the best possible path of
 * the travel salesman problem.
 * 
 * @author Kevin Yean
 * @author Dakota Watson
 *
 */

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main 
{
	public static void main(String[] args) throws IOException 
	{	
		init(); //Initializes
	}
	//Runs the program
	public static void init() throws IOException
	{
		//Takes the input from the user
		Scanner in = new Scanner(System.in);
				
		//Prints the starting message
		System.out.print(
				"Using Genetic Algorithm, this program will try to find the best possible path of TSP problem.\n" +
				"Please enter the name of the file: ");
		//Loop for the input of the user
		while(in.hasNextLine())
		{
			//Create a string variable to hold the input from the user
			String initCity = (in.nextLine());
			//Given the boolean return from this method it will do the following if and else
			if(fileExists(initCity))
			{
				Cities tsp = new Cities(initCity);
				//System.out.println(tsp.toString());
				GeneticAlgorithm genetic = new GeneticAlgorithm(tsp,tsp.getNumberCities());
				
			}
			else
			{
				System.out.println("The file name does exists or cannot be read.");
				System.exit(0);
			}
		}
		in.close();
	}
	//Checks if the files exists.
	public static boolean fileExists(String temp)
	{
		File file = new File(temp);
		return file.exists(); //Methods returns boolean given the file existance
	}
}

