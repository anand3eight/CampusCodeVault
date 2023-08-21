/*2. Given that a 1.12 kg ball rolls forward with a
net acceleration of 1.11 m/s2

. Write a program to

calculate the net force on the ball.
[Formulae: Force = mass * acceleration]
Hint: Initialize the mass and acceleration in the program. */

#include <stdio.h>

void main()
{
  float mass = 1.12, acceleration = 1.11;
  float force = mass * acceleration;
  printf("Force = %.4f ", force);
}
