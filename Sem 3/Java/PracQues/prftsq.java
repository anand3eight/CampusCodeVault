import java.lang.Math;
class prftsq
{
	public static void main(String args[])
	{
		int num = Integer.parseInt(args[0]);
		int sqrt = (int)Math.pow(num, 0.5);
		int i;
		for(i = sqrt; i > 0; i--)
		{
			if(i*i == num)
			{
				System.out.println("Perfect Square");
				break;
			}
		}
	}
}