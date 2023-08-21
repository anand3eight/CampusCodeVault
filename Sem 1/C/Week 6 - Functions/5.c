/* Collision Velocity Calculator */

#include<stdio.h>

float collVelocity(float m1, float v1, float m2, float v2)
{
	return (m1*v1 + m2*v2)/(m1 + m2);
}

void main()
{
	float m1, v1, m2, v2;
	printf("Enter Mass and Velocity for 2 Objects : ");
	scanf("%f%f%f%f", &m1, &v1, &m2, &v2);
	printf("Final Velocity = %.2f", collVelocity(m1,v1,m2,v2));
 } 
