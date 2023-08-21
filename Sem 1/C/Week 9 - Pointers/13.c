/* PIN Verification */

#include<stdio.h>
#include<string.h>

int pinCheck(char *p, int size, char* pin)
{
    int index;
    for(index = 0; index < size; index++)
    {
      if(*(p + index) != *(pin + index))
      {
          return 0;
      }
    }
    return 1;
}

void main()
{
    char pin[10], username[30], correctPIN[10] = "ABc@123";
    int try = 1;
    printf("Enter Username : ");
    scanf("%s", username);
    for(try = 1; try <= 4; try++)
    {
        printf("Enter PIN : ");
        scanf("%s", pin);
        if(pinCheck(pin, strlen(correctPIN), correctPIN) == 1)
        {
            printf("Pin Verified, Welcome!\n");
            break;
        }

        else
            printf("Wrong PIN, Try Again\n");
    }
    if(pinCheck(pin, strlen(correctPIN), correctPIN) == 0)
        printf("Sorry, Login Unsuccessful.");
}
