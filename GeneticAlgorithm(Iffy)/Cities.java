/** This class holds the data from the file or creates new cities.
 * 
 * @author kyean16
 *
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Cities 
{
	private FileReader fr;
	private BufferedReader br;
	private int [] [] parsed; // Creates 2-D array of cities
	public int numberCities;
	public ArrayList<Integer> spaces = new ArrayList<Integer>(); //Holds the spaces needed to make thing look nice when printed
	public ArrayList<City> city = new ArrayList <City>();
	private int totalDistance;
	private double percentFit;
	private double rangeMin;
	private double rangeMax;
	
	//Currently empty constructor
 	public Cities()
	{	
	}
 	//Constructor that copies the parameter
 	public Cities(Cities dummy)
 	{
 		for (int i = 0; i < dummy.city.size() ; i++)
 		{
 			City tempCity = dummy.city.get(i);
 			city.add(tempCity);
 		}
 		for (int i = 0; i < dummy.spaces.size() ; i++)
 		{
 			int b = dummy.spaces.get(i);
 			spaces.add(b);
 		}

 	}
	//Constructor that holds is given the tsp file name and parses the data from it
	public Cities(String temp) throws IOException
	{
		fr = new FileReader(temp);
		br = new BufferedReader(fr);
		System.out.println("here");
		String lines = (""); //Variable for loops
		int first = 0; //Keeps tracks of the first line
		int column = 0;
		//Loops until all the lines have been visited
		while((lines = br.readLine()) != null)
		{	
			boolean numberPresent = false; //Boolean used for more than one digit number
			//Finds the number of cities in the tsp file.
			//First line of the txt
			if(first == 0) //In Charge of the first number in the first column
			{
				int i = 0;
				String number = "0";
				while(i < lines.length())
				{
					//Indicates that there is not a space therefore it must be a number
					if (lines.charAt(i) != ' ')
					{
						char num = lines.charAt(i); //Finds char and assigns it to num
						number += Character.toString(num);//Assigns num to the string number
						if((i+1) == lines.length())
						{
							int tempNum = Integer.parseInt(number);
							parsed = new int [tempNum][tempNum];
							numberCities = tempNum;
							break;
						}
						numberPresent = true; //Toggles boolean meaning a number exists
					}
					//Indicates that there is a space therefore the number must have ended
					else if (lines.charAt(i) == ' ' && numberPresent == true)
					{
						int num = Integer.parseInt(number);
						parsed = new int [num][num];
						numberCities = num;
						break;
					}
					//If it is the last char of the line and it not a space it must a number
					else if((i+1) == lines.length() && lines.charAt(i) != ' ')
					{
						char num = lines.charAt(i); //Finds char and assigns it to num
						number += Character.toString(num);//Assigns num to the string number
						int tempNum = Integer.parseInt(number);
						parsed = new int [tempNum][tempNum];
						numberCities = tempNum ;
						break;
					}
					i++;
				}
				for (int x = 0; x < numberCities ; x++)							
				{
						spaces.add(1);
				}
			}
			else //Rest
			{
				int i = 0;
				String number = "0";
				int fnum = 0;//First number of the array to prevent it from random spaces
				int tempRows = 0; //Temps rows
				City ville = new City();
				//Goes throught all the characters in the lenght of the line
				for (int tempChar = 0; tempChar < lines.length() ; tempChar ++)
				{
					//If the current char is a space
					if(lines.charAt(tempChar) == (' ') )
					{
						//If the next number is equals to the String length it simply put the number into the array.
						if((tempChar+1) == lines.length())
						{
							i = Integer.parseInt(number);
							parsed [column][tempRows] = i; //Assigns i to parsed
							ville.addCityDistance(i);
						}
						//If the next char is not a space it adds the current value in number and puts it into the 2-D array
						else if(lines.charAt(tempChar+1) != (' ') && fnum !=0)
						{
							i = Integer.parseInt(number);
							//Find the number of spaces each number takes given the number of digit
							int tempNumber = i;
							int tempSpaces = 0;
							while (tempNumber > 0 )
						    {
						         tempNumber = tempNumber / 10;
						         tempSpaces ++;
						    }
							if (tempSpaces > spaces.get(tempRows))
							{
								spaces.set(tempRows,tempSpaces);
							}
							number = "0";//Resets number for next one.
							parsed [column][tempRows] = i; //Assigns i to parsed
							ville.addCityDistance(i);
							tempRows++;
						}
					}
					//If the current char is not a space
					else
					{
						fnum = 1; //First move must have been played if not a space.
						char num = lines.charAt(tempChar); //Takes the number put into a char
						number +=  Character.toString(num);//Put char into the string.
						if (tempChar == (lines.length()-1))//If number is the last one in the String it adds it to the 2-D Array
						{
							i = Integer.parseInt(number);
							parsed [column][tempRows] = i; //Assigns i to parsed
							ville.addCityDistance(i);
						}
					}
				}
				ville.findCityPlacement();
				city.add(ville);
				tempRows = 0; //Reset rows for the next column
				column++;//Moves to the next column
			}
			first ++;
		}
	}
	//To String method
	public String toString()
	{
		String lines = "";
		for(int cols = 0 ; cols < numberCities ; cols++)
		{
			for(int rows = 0 ; rows < numberCities ; rows++)
			{
				lines +=((parsed[cols][rows]));
				//Adding spacesS
				int tempSpaces = -1;
				int i = parsed[cols][rows];
				{
					if (i == 0)
					{
						tempSpaces ++;
					}
					while (i > 0 )
				    {
				         i = i / 10;
				         tempSpaces ++;
				    }
					for (int space = 0; space <= (spaces.get(rows) - tempSpaces); space ++)
					{			
						lines += " ";
					}
				}
			}
			lines += "\n";
		}
		lines += "City Travel Order: " + orderCities() +
				"|Distance traveled: " + totalDistance() +
				" |Fitness Percentage: " + getFitness();
		return lines;
	}
	//Prints strings
	public String randomString()
	{
		return( "City Travel Order: " + orderCities() +
				"Distance traveled: " + totalDistance());
	}
	//Adds the total distance from each city from the first one
	public int totalDistance()
	{
		int total = 0; //Total.
		for (int i = 0 ; i < city.size(); i++) //Looks at all the cities
		{
			//If i+1 is not equals to the size of the array look at the number city and assign placement with city placement which will be use to find what city value to find
			if ((i+1)!= city.size())
			{
				int placement;
				placement = city.get(i+1).getCityPlacement();
				total += city.get(i).getCityDitance(placement);
			}
			else if (i+1 == city.size())
			{
				int placement;
				placement = city.get(0).getCityPlacement();
				total += city.get(i).getCityDitance(placement);
			}
		}
		totalDistance = total;
		return total;
	}
	//FInd the order of city traveled
	public String orderCities()
	{
		String lines = "";
		for(int i = 0 ; i < city.size(); i++)
		{
			lines+= city.get(i).getCityPlacement() + " ";
		}
		return lines;
	}
	public void setFitness(double temp)
	{
		percentFit = temp;
	}
	public double getFitness()
	{
		return percentFit;
	}
	public int getNumberCities()
	{
		return numberCities;
	}
	public void setNumberCities(int temp)
	{
		numberCities = temp;
	}
	public void setRange(double min, double max)
	{
		rangeMin = min;
		rangeMax = max + min;
	}
	public double getRangeMin()
	{
		return rangeMin;
	}
	public double getRangeMax()
	{
		return rangeMax;
	}
	
}
