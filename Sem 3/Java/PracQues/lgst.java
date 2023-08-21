class lgst
{
	public static void main(String args [])
	{
		int i, num, max = 0 ;
		for(i = 0; i < args.length; i++)
		{
			num = Integer.parseInt(args[i]);
			if(max < num)
			{
				max = num;
			}	
		}
		System.out.println(max);
	}
}