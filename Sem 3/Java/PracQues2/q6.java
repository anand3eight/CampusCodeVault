class q6
{
	public static void fibo(int n)
	{
		int a = -1, b = 1, c;
		for(int i = 0; i < n; i++)
		{
			c = a + b;
			System.out.print(c + " ");
			a = b;
			b = c;
		}
	}
	public static void main(String args[])
	{
		fibo(Integer.parseInt(args[0]));
	}
}
			 
		 