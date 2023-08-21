/* It's IPL time and as usual RCB are finding it
tough to qualify for playoffs. RCB needs
a minimum of X more points to qualify for playoffs
in their remaining Y matches. A win, tie and loss
in a match will yield 2, 1, 0 points respectively to a team.
You being a true RCB supporter want to
find the minimum number of matches RCB needs to win
to qualify for playoffs. It is guaranteed that
RCB will qualify for playoffs if they win all their
remaining Y matches.
Sample Input:
Example 1: 10 5
Output: 5
(Note: In first case X=10 and Y=5,
so RCB needs 10 points from remaining 5 matches to
qualify for playoffs. It is only possible if
they win all their remaining 5 matches.)
Example 2: 1 5
5
0
(Note: X=1 and Y=5, so RCB needs 1 points from
their remaining 5 matches to qualify for playoffs.
It can be done if
they tie any one of their 5 matches and lose the remaining 4.
So they need to win 0 matches.)*/

#include<stdio.h>

void main()
{
    int matches, points, i, zero = 0;
    printf("RCB Calculator");
    printf("\nNumber Of Points Required : ");
    scanf("%d", &points);
    printf("Number Of Matches Left : ");
    scanf("%d", &matches);
    for(i = 0; i <= matches; i++)
    {
        if((i*2) == points || (i*2) == points-1)   printf("%d", i);
    }
}
