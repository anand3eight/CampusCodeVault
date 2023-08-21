/* To Insert an element in an array */

#include<stdio.h>

void main()
{
    int size;
    printf("Enter The Array Size : ");
    scanf("%d", &size);
    int arr[size], i;
    //Input of Array Elements
    printf("Enter The Array :\n");
    for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
    int elmt, pos, temp;
    printf("Enter Element And Position To be Inserted : ");
    scanf("%d%d", &elmt, &pos);
    for(i = pos-1; i < 6; i++ )
    {
        temp = arr[i];
        arr[i] = elmt;
        elmt = temp;
    }
    size++;
    printf("ARRAY ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

}
