public class q2
{
	double a, b, c, d, e;
	public double mul1()
	{
		return a*b;
	}
	public double mul2()
	{
		return c*d;
	}

	public static void main(String args[])
	{
		q2 obj1 = new q2();
		obj1.a = 9.5;
		obj1.b = 8.5;
		obj1.c = 5.5;
		obj1.d = 2;
		obj1.e = 150.49 - 121.09;
		double num = (obj1.mul1() - obj1.mul2())/obj1.e;
		System.out.println(num);
	}

}

