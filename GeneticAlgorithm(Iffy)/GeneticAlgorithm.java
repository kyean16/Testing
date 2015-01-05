import java.util.ArrayList;
import java.util.Collection;
import java.util.Random;


public class GeneticAlgorithm
{
	public ArrayList<Cities> oGcities = new ArrayList <Cities>();
	public ArrayList<Cities> newCities = new ArrayList <Cities>();
	public double totalFitness;
	public int numbercities;
	//Number of population in each generation
	public static final int size = 100;
	//Number of generations you want
	public static final int gen = 100;
	
	//Constructor does all the work
	public GeneticAlgorithm(Cities temp, int num)
	{
		//Sets the number of cities
		numbercities = num;
		int generation = 0;
		//While generation has not reached the maximum number of generations
		while(generation < gen )
		{
			int i = 0;
			//Calls function to randomize the array
			while(i < size)
			{
				randomizeArray(temp);
				i++;
			}
			//Prints which generation it is currently in
			System.out.println("Generation: " + generation);
			fitness();
			System.out.println("The fitness of the smallest individual is: " + oGcities.get(0).totalDistance()+
								"\nThe average fitness is : " + (totalFitness/oGcities.size()));
			System.out.println(oGcities.get(0).toString());
			//Selections
			while(oGcities.size() > newCities.size())
			{
				Cities selectOne = selection();
				Cities selectTwo = selection();
				crossOver(selectOne,selectTwo);
			}
			totalFitness = 0;
			oGcities = newCities;
			mutation();
			//clears
			newCities.clear();
			generation ++;
		}
	}
	//Function to randomly create things
	public String randomizeArray (Cities temp)
	{
		int num = temp.getNumberCities();
		Cities ville = new Cities(temp);
		oGcities.add(ville);
		Random rgen = new Random();
		
		for (int i = 0 ; i < ville.city.size(); i++)
		{
			int randomPosition = rgen.nextInt(ville.city.size());
			City local1 = ville.city.get(randomPosition);
			City local = ville.city.get(i);
			//
			ville.city.remove(i);
			ville.city.add(i,local1);
			//
			ville.city.remove(randomPosition);
			ville.city.add(randomPosition,local);
		}
		totalFitness += ville.totalDistance();
		return ville.randomString();
	}
	//Finds fitness of each individuals
	public void fitness()
	{
		//Order with the distance
		int b = 0;
		while (b != oGcities.size())
		{
			int min = oGcities.get(b).totalDistance();
			
			for(int z = b ; z < oGcities.size() ; z++)
			{
				if(oGcities.get(z).totalDistance() < min)
				{
					min = oGcities.get(z).totalDistance();
					Cities temp = oGcities.get(z);
					Cities temp1 = oGcities.get(b);
					oGcities.remove(b);
					oGcities.add(b,temp);
					//
					oGcities.remove(z);
					oGcities.add(z,temp1);
				}
			}
			b++;
		}
		//Assigns fitness
		for(int i = 0; i<oGcities.size();i++)
		{
			double temp = (oGcities.get(i).totalDistance()/totalFitness) * 100;
			oGcities.get(i).setFitness(temp);
		}
		//Swaps fitness
		int oGSize = oGcities.size() - 1;
		for(int i = 0 ; i<oGcities.size()/2;i++)
		{
			double temp = oGcities.get(i).getFitness();
			double temp1 = oGcities.get(oGSize - i).getFitness();
			oGcities.get(i).setFitness(temp1);
			oGcities.get(oGSize - i).setFitness(temp);
		}
		//Assigns the fitness to of 100?
		double range = 0;
		for (int i = 0 ; i < oGcities.size(); i++)
		{
			oGcities.get(i).setRange(range, oGcities.get(i).getFitness());
			range += oGcities.get(i).getFitness();
		}
		range = 0;
		//Prints results
		for (int i = 0 ; i < oGcities.size(); i++)
		{
			System.out.println(oGcities.get(i).toString());
		}
	}
	//Selects
	public Cities selection()
	{
		Cities temp = new Cities();
		Random rGen = new Random();
		int firstSelection = rGen.nextInt(100);
		
		for(int i = 0; i< oGcities.size(); i++)
		{
			if (firstSelection >= oGcities.get(i).getRangeMin() && firstSelection <= oGcities.get(i).getRangeMax())
			{
				temp = (oGcities.get(i));
			}
		}
		return temp;
	}
	//Cross Over
	public void crossOver(Cities one, Cities two)
	{
		
		int random = numbercities;
		Cities crossOverOne = one;
		Cities crossOverTwo = two;
		
		Random rGen = new Random();
		int rangeMin = rGen.nextInt(random);
		int rangeMax = rGen.nextInt(random);
		while(rangeMin == rangeMax)
		{
			rangeMin = rGen.nextInt(random);
		}
		if (rangeMin > rangeMax )
		{
			int i = rangeMax;
			rangeMax = rangeMin;
			rangeMin = i;
		}
		ArrayList <Integer> firstNums = new ArrayList<Integer>();
		ArrayList <Integer> secondNums = new ArrayList<Integer>();
		for(int i = rangeMin; i <= rangeMax ; i++)
		{
			firstNums.add(crossOverOne.city.get(i).getCityPlacement());
			secondNums.add(crossOverTwo.city.get(i).getCityPlacement());
		}
		int range = rangeMin;
		//First
		while(firstNums.size() > 0)
		{
			for(int i = 0 ; i < crossOverTwo.city.size(); i++)
			{
				for(int b = 0; b < firstNums.size(); b++)
				{
					if(crossOverTwo.city.get(i).getCityPlacement() == firstNums.get(b))
					{
						crossOverOne.city.set(range,crossOverTwo.city.get(i));
						firstNums.remove(b);
						range++;
					}
				}
			}
		}
		range = rangeMin;
		//Second
		while(secondNums.size() > 0)
		{
			for(int i = 0 ; i < crossOverOne.city.size(); i++)
			{
				for(int b = 0; b < secondNums.size(); b++)
				{
					if(crossOverOne.city.get(i).getCityPlacement() == secondNums.get(b))
					{
						crossOverTwo.city.set(range,crossOverOne.city.get(i));
						secondNums.remove(b);
						range++;
					}
				}
			}
		}
		newCities.add(crossOverOne);
		newCities.add(crossOverTwo);
	}
	//Mutates
	public void mutation()
	{
		Random rGen = new Random();
		int number = rGen.nextInt(100);
		if (number % 9 == 0)
		{
			int mutator = rGen.nextInt(oGcities.size()-1);
			City temp = oGcities.get(mutator).city.get(oGcities.get(mutator).city.size()-1);
			oGcities.get(mutator).city.set(oGcities.get(mutator).city.size()-1, oGcities.get(mutator).city.get(0));
			oGcities.get(mutator).city.set(0, temp);
		}
			
	}
}
