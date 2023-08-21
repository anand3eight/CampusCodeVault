class cla
{
	public static void main(String args[])
	{
		int i, sum = 0;
		for(i = 0; i < args.length; i++)
		{
			sum += Integer.parseInt(args[i]);
		}
		System.out.println(sum);

	}
}