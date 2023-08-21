/* 3. The University has to process the fees structure of
the student. The female students are given
10% waiver in their fees. The fees is calculated as follows:

Fees = Tuition_Fee + Book_fee + Placement_fees – waiver

Write a program that reads the name of the student,
gender (m - male, f - female), Tuition_fee,
Book_fee, Placement_fee and computes the fees to be paid
by the student. The output should be
displayed in this format:
Name of the Student: Arthi S
Gender: F
Fee Structure:
Tuition Fee: 10000
Book Fee: 3000
Placement Fee: 5000
Total Fees: Rs. 16200 */

#include<stdio.h>

void main()   {
    char name[80], gender ;
    float Tuition_fee, Book_fee, Placement_fee, waiver = 0 ;
    float Total_fee;
    printf("Enter Your Name, \nGender - M/F, \nBook_fee, \nTuition_fee, \nPlacement_fee : \n");
    gets(name);
    scanf("%c%f%f%f", &gender, &Book_fee, &Tuition_fee, &Placement_fee);
    Total_fee = Tuition_fee + Book_fee + Placement_fee - waiver;

    if(gender == 'F')   {
        waiver = 0.10 * Total_fee;
    }
    Total_fee = Tuition_fee + Book_fee + Placement_fee - waiver;
    printf("\nName of The Student : %s", name);
    printf("\nGender : %c", gender);
    printf("\nFee Structure : " );
    printf("\nTuition Fee : %f", Tuition_fee);
    printf("\nBook fee : %f", Book_fee);
    printf("\nPlacement_fee : %f", Placement_fee);
    printf("\nTotal Fees : Rs.%f", Total_fee);
}
