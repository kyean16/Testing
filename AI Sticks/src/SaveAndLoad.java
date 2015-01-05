import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

/** This class is responsible for:
 * 		-Loading a save file
 * 		-Saving a save file
 * 		-Parsing the 2-D array information back to Main
 * 
 * @author Kevin yean
 *@author Dakota Watson
 */

public class SaveAndLoad 
{
	private FileOutputStream saveFile;
	private ObjectOutputStream  save;
	
	//Constructor is responsible for creating or loading the file given its name
	public SaveAndLoad(String fileName) 
	{
		try 
		{
			saveFile = new FileOutputStream(fileName);
			save = new ObjectOutputStream(saveFile);
		} 
		catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//Saves 2-D Arrays
	public void saveArray(int[][] temp)
	{
		try 
		{
			save.writeObject(temp);
		}
		catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//Loads/Get 2-D array from the file.
	
}
