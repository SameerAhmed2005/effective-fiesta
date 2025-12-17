#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

//menu for converter
void ConverterMenu(void)
{
    int choice;

    printf("\n----------- Unit Converter -----------\n");
    printf("1. Kg to Lbs\n");
    printf("2. Lbs to Kg\n");
    printf("3. Cm to Ft & Inches\n");
    printf("4. Ft & Inches to Cm\n");
    printf("5. Back to Main Menu\n");
    printf("--------------------------------------\n");

    printf("Select item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            kgtolbs();
            break;

        case 2:
            lbstokg();
            break;

        case 3:
            cmtoft();
            break;

        case 4:
            fttocm();
            break;

        case 5:
            printf("Returning to main menu...\n");
            return;

        default:
            printf("Invalid option!\n");
            return;
    }
}

//func to calc kg to lbs
void kgtolbs(){
    float kg;
    float lbs;
    printf("\n----------- Kg to Lbs -----------\n");
    printf("Please Enter Weight in Kg: \n");
    scanf("%f", &kg);
    lbs = kg * 2.20462;
    printf("Your Weight in Pounds(lbs): %.2f ",lbs);
}

//func to calc lbs to kg
void lbstokg(){
    float kg;
    float lbs;
    printf("\n----------- Lbs to Kg -----------\n");
    printf("Please Enter Weight in lbs: \n");
    scanf("%f", &lbs);
    kg = lbs/2.20462;
    printf("Your Weight in KG: %.2f \n",kg);
}


//func to calc cm to feet
void cmtoft(){
    float cm;
    int feet;
    float inches;
    printf("\n----------- Cm to Feet -----------\n");
    printf("Please Enter Height in Cm: \n");
    scanf("%f", &cm);
    feet = (int)(cm / 30.48);
    inches = (cm / 2.54) - (feet * 12);
    printf("%.2f cm is equal to %d feet %.0f inches.\n", cm, feet, inches);


}
//func to calc feet to cm
void fttocm(){
    float cm;
    int feet;
    float inches;
    printf("\n----------- Feet to Cm -----------\n");
    printf("Enter feet: \n");
    scanf("%d", &feet);
    printf("Enter inches: \n");
    scanf("%f", &inches);
    cm = (feet * 30.48) + (inches * 2.54);
    printf("%d feet %.0f inches is equal to %.2f cm.\n", feet, inches, cm);
}