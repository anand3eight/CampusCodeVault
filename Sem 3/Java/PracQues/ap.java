class ap
{
	public static void main(String args[])
	{
		int start, loop, check, flag = 0;
		for(start = 2; start < 50; start++)
		{
			check = 1;
			for(loop = 2; loop < start; loop++)
			{
				if(start % loop == 0)
				{
					check = 0;
				}
			}
			if(check == 1)
			{
				if(flag %2 == 0)
				{
					System.out.println(start);
						
				}
				flag += 1;
									
			}
			
		}	
	}
}	