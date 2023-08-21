/* Cholestrol Checker */

void main()
{
    int age, ldl, hdl;
    printf("Enter Your Age, LDL and HDL Cholestrol Levels(in mg/dl) : ");
    scanf("%d%d%d", &age, &ldl, &hdl);
    if(age <= 19)
    {
        if(ldl < 100 || hdl >= 45)   printf("No Cholestrol");
        else  printf("LDL/HDL is High");
    }
    else if(age > 19)
    {
        int gender;
        printf("Enter Your Gender (Male - 1/Female - 2) : ");
        scanf("%d", &gender);
        if(gender == 1)
        {
          if(ldl < 100 || hdl >= 40)   printf("No Cholestrol");
          else  printf("LDL/HDL is High");
        }
        else if(gender == 2)
        {
          if(ldl < 100 || hdl >= 50)   printf("No Cholestrol");
          else  printf("LDL/HDL is High");
        }
    }
}
