public class main {

	public int number;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//System.out.println(args[0]);
		main test = new main();
		
	}
	
	public main()
	{
		int one = 10;
		printNumber(one);
	}
	
	//Print Number
	public void printNumber(int one)
	{
		System.out.println(one);
	}
	
	//Set number
	public void setNumber(int one)
	{
		number = one;
	}
	
	//Return number
	public int getNumber()
	{
		return number;
	}
}
