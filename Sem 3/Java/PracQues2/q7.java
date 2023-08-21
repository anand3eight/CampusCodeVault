class q7
{
	int n;
	q7(int num)
	{
		n = num;
	}
	int prime()
	{
		for(int i = 2; i < n; i++)
		{
			if(n % i == 0)
			{
				System.out.println("Not Prime");
				return 0;
			} 
		}
		System.out.println("Prime");
		return 0;
	}
	public static void main(String args[])
	{
		q7 obj = new q7(Integer.parseInt(args[0]));
		int ch = obj.prime();
	}
}