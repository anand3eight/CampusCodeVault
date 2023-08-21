/* 1. Given the physics, chemistry and mathematics marks
(out of 200) of the student, Write a progam
to calculate the cut-off.

Cut_off = (physics_mark/4) + (chemistry_mark/4) + (Maths_mark/2) */
#include <stdio.h>

void main()
{
    int phy, chem, math;
    float cut_off;
    printf("\nEnter Physics, Chemistry And Math Marks : ");
    scanf("%d%d%d", &phy, &chem, &math);
    cut_off = (phy / 4) + (chem / 4) + (math / 2);
    printf("\nCut Off = %.2f", cut_off);
}
