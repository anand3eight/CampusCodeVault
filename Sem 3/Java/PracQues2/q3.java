class q3
{
	int a, b, c, d, e, f; 
	public q3(int a1, int b1, int c1, int d1, int e1, int f1)
	{
		a = a1;
		b = b1;
		c = c1;
		d = d1;
		e = e1;
		f = f1;
	}
	float cramerx()
	{
		float x = (e*d - b*f)/(a*d - b*c);
		return x;
	}
	float cramery()
	{
		float y = (a*f - e*c)/(a*d - b*c);
		return y;
	}
	public static void main(String args[])
	{
		q3 obj = new q3(1,2,3,4,5,6);
		System.out.println(obj.cramerx() + " " + obj.cramery());
	}
}
		
		