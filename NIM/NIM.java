/* Author: Kevin Yean
Simple game of Nim to redo the old homework from AI class
*/

import java.util.Scanner;
import java.lang.NumberFormatException;
import java.util.Random;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class NIM
{
	public boolean startTurn; //Bool who starts
	public int totalNim; //Startingn number of Nims
	public int possibleNumMoves; //Possible number that can be taken per turn
	public Scanner scan = new Scanner(System.in);


	public static void main(String[] args) 
	{
    	NIM newNim = new NIM();   
  }
    //Constructor sets up the basic rules for easy modification, set up who starts, Call start function
  public NIM()
    {
      Stage test = new Stage();
      Button btn = new Button();
      btn.setText("Say Hello World");
      StackPane root = new StackPane();
      root.getChildren().add(btn);
      test.setScene(new Scene(root,300,250));
      test.show();
    	startTurn = true;
    	totalNim = 12;
    	possibleNumMoves = 4;
    	Start();
    }

    //The method that plays until the game is over
    public void Start()
    {
    	while(totalNim != 0) // Loop while totalNim is not zero
    	{
    		printNim();
    		if(startTurn) //True == player turns
    		{
    			Player();
    		}
    		else
    		{
    			DumbAi();
    		}
    	}
    	printWinner();//Since zero check who won.
    }

    //Function for the player.
    public void Player()
   	{
   		System.out.print("How many would sticks would like to take from 1 to " + possibleNumMoves + " : ");
   		try
   		{
   			String s = scan.next();
   			int input = Integer.parseInt(s);
   			if(input > 0 && input <= totalNim && input <= possibleNumMoves)
   			{
   				System.out.println("You removed " + input + " from the stack.");
   				totalNim = totalNim - input;
   			}
   			else
   			{
   				System.out.println("Your number does not fall within range please try again.");
   				Player();
   			}
   		}
   		catch (NumberFormatException e) //Catches if wrong input is written by the user.
   		{
   			System.out.println("Wrong input please try again");

   			Player();
   		}
   		startTurn = !startTurn; //Inverse bool;
   	}

   	//Randomly takes a number.
   	public void DumbAi()
   	{
   		int AIchoice;

   		if(totalNim <= possibleNumMoves)
   		{
   			AIchoice = totalNim;
   		}
   		else
   		{
   			Random random = new Random();
   			AIchoice = (random.nextInt(possibleNumMoves)+1);
   		}
   		totalNim = totalNim - AIchoice;
   		System.out.println("The AI took: " + AIchoice);
   		startTurn = !startTurn; //Inverse bool;
   	}

   	//Function that prints the remaining number of Nim by 4 4
   	public void printNim()
   	{
   		System.out.print("Remaining number of sticks = ");
   		int spacing = 0; //use for spacing
   		for (int i = 0 ; i < totalNim ; i++) //Continuously print while it does not reach totalNim;
   		{
   			spacing++;
   			System.out.print("|");
   			if(spacing == 4)
   			{
   				System.out.print(" ");
   				spacing = 0;
   			}
   		}
   		//
   		System.out.print(" (" + totalNim + ")\n");
   	}

   	//Function that prints the Winner.
   	public void printWinner()
   	{
   		if(startTurn) //Inversed it since it autommatically get switched at the end of the function
   		{
   			System.out.println("The AI Won.");
   		}
   		else
   		{
   			System.out.println("You Won.");
   		}
   	}
}