import java.lang.Math;
class q8
{
	int num, rem; 
	void armstrong(int n)
	{
		double sum = 0.0;
		num = n;
		while(n > 0)
		{
			rem = n % 10;
			sum = sum + Math.pow(rem, 3);
			n = n / 10;
		}
		if(num == sum)
		{
			System.out.println("Armstrong");
		}
		else
		{
			System.out.println("Not a Armstrong");
		}
	}
	public static void main(String args[])
	{
		q8 obj = new q8();
		obj.armstrong(Integer.parseInt(args[0]));
	}
}	