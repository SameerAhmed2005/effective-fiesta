#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "bmi.h"

//Menu for BMI Tools
void BMIMenu(void)
{
    int choice;

    printf("\n----------- BMI Tools -----------\n");
    printf("1. Calculate BMI\n");
    printf("2. View History\n");
    printf("3. Back to Main Menu\n");
    printf("--------------------------------------\n");

    printf("Select item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            calculateBMI();
            break;

        case 2:
            viewBMIHistory();
            break;

        case 3:
            getchar();            
            return;

        default:
            printf("Invalid option!\n");
            return;
    }
}


//Func to calc BMI, save result and print what category they fall into
void calculateBMI(){
    FILE *BMIfile;
    float weight;
    float height;
    float BMI;

    printf("\n----------- BMI Calculator -----------\n");
    //user inputs using valid ranges to avoid wrong calculations
    //ask for height
    do {
        printf("Please Enter Height (Cm): ");
        scanf("%f", &height);

        if (height < 0 || height > 250) {
            printf("Please Enter a valid height in Cm\n");
            printf("If not sure you can use unit converter function!\n");
        }
    } while (height < 0 || height > 250);

    //asks for weight
    do {
        printf("Please Enter Weight (Kg): ");
        scanf("%f", &weight);

        if (weight < 0 || weight > 300) {
            printf("Please Enter a valid weight in Kg\n");
            printf("If not sure you can use unit converter mode!\n");
        }
    } while (weight < 0 || weight > 300);


    //bmi formula
    BMI = ((weight) / (height*height)) * 10000;
    printf("Your Bmi is: %.2f\n", BMI);

    //opens bmi file to append entry
    BMIfile = fopen("bmi.txt", "a");
    if (BMIfile == NULL) {
        printf("Error!");
        return;
    }

    //saves Date and when BMI was added 
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(BMIfile, "%02d/%02d/%04d - BMI: %.2f\n",
        t->tm_mday,
        t->tm_mon + 1,
        t->tm_year + 1900,
        BMI);

    //closes file
    fclose(BMIfile);
    printf("BMI Saved :)\n");


    //display what their BMI category is

    if (BMI < 18.5) {
        printf("Your BMI Suggests Your Underweight!");
    }

    else if (BMI < 24.9) {
        printf("Your BMI Suggests Your Healthy");
    }

    else if (BMI < 30) {
        printf("Your BMI Suggests Your Overweight!");
    }
    
    else if (BMI >= 30) {
        printf("Your BMI Suggests Your Obese!");
    }
}

//func to view BMI History reads all saved enteries from bmi.txt
void viewBMIHistory() {
    FILE *file;
    file = fopen("bmi.txt", "r");
    char BMIHistory[100];

    printf("\n----------- View your BMI History -----------\n");
    //checks if file exists
    if (file == NULL) {
        printf("error opening file!");
        return;
    }

    else {
        //prints line by line
        while(fgets(BMIHistory, 100, file)) {
        printf("%s", BMIHistory);}}
    
    //closes file
    fclose(file);
}