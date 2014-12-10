import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class mainTestTest {

	@Before
	public void setUp() throws Exception
	{
		tester = new main();
	}
   
   @Test
   public void equalNumber()
   {
	   tester.setNumber(10);
	   assertTrue(tester.getNumber() == 10);
   }
   
   private main tester;
}