/* Kattapa, as you all know was one of the
greatest warriors of his time. The kingdom of Maahishmati
had never lost a battle under him (as army-chief),
and the reason for that was their really powerful army,
 also called as Mahasena. Kattapa was known to be
 a very superstitious person. He believed that
 a soldier is "lucky" if the soldier is holding
 an even number of weapons, and "unlucky" otherwise.
 He considered the army as "READY FOR BATTLE"
 if the count of "lucky" soldiers is
 strictly greater than the count of "unlucky" soldiers,
 and "NOT READY" otherwise. Given the number of weapons
 each soldier is holding, your task is to determine
 whether the army formed by all these soldiers is
 "READY FOR BATTLE" or "NOT READY". */

 #include<stdio.h>

 void main()
 {
    int soldier_count, weapon_count, lucky_count = 0, unlucky_count = 0;
    int ch = 1;
    printf("Enter Number Of Weapons for");
    for(soldier_count = 1; ch != 0; soldier_count++)
    {
        printf("\nSoldier %d : ", soldier_count);
        scanf("%d", &weapon_count);
        if(weapon_count%2 == 0)   lucky_count++;
        else                      unlucky_count++;
        printf("To End Press 0 else any Number : ");
        scanf("%d", &ch);
    }
    if(lucky_count > unlucky_count)   printf("READY FOR BATTLE");
    else                              printf("NOT READY");

 }
