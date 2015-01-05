import java.util.ArrayList;

/** City class that holds the distance from other cities from itself
 * 
 * @author Kevin Yean
 * @author Dakota Watson
 *
 */

public class City
{
	public ArrayList<Integer> cityDistance = new ArrayList<Integer>(); //Holds the city distance
	public int cityPlacement;
	
	//Empty Constructor
	public City()
	{
	}
	//Adds the distance of a city from Cities
	public void addCityDistance(int temp)
	{
		cityDistance.add(temp);
	}
	//Finds the city of the distance from the arrayList cityDistance
	public void findCityPlacement()
	{
		for(int i = 0 ; i < cityDistance.size() ; i++)
		{
			if (cityDistance.get(i) == 0)
			{
				cityPlacement = i;
				break;
			}
		}
	}
	//Return the city placement
	public int getCityPlacement()
	{
		return cityPlacement;
	}
	//Return the distance of a specific distance in the arrayList of cityDitance
	public int getCityDitance(int temp)
	{
		return cityDistance.get(temp);
	}
}
