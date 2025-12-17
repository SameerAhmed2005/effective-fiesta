#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calories.h"

void CaloricMenu(void)
{
    int choice;

    printf("\n----------- Caloric Tools -----------\n");
    printf("1. Calculate Daily Calories\n");
    printf("2. Track your Calories\n");
    printf("--------------------------------------\n");

    printf("Select item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            CalcCalories();
            break;

        case 2:
            trackCalories();
            break;

        case 3:
            printf("Returning to main menu...\n");
            return;

        default:
            printf("Invalid option!\n");
            return;
    }
}
//func to calc users caloric goal
void CalcCalories() {
    int age;
    float weight, height, BMR, dailyCalories;
    char gender; 
    char goal;


    printf("\n----------- Calculate Your Daily Caloric Intake -----------\n");
    //asks for Gender
    do {
        printf("Please Enter Gender: \n 'M' for Male\n 'F' for Female\n Enter: ");
        scanf(" %c", &gender);

        if (gender != 'M' && gender !='F') {
            printf("Try Again: ");
        }
    } while (gender != 'M' && gender != 'F');

    //ask for age
    do {
        printf("Please Enter Age: ");
        scanf("%d", &age);

        if (age < 0 || age > 100) {
            printf("Please Enter a valid age!\n");
        }
    } while (age < 0 || age>100);

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

    //asks for Weight Goal
    do {
        printf("Please Enter Goal Weight: \n 'M' for Maintain \n 'L' for Lose \n 'G' for Gain\n Enter: ");
        scanf(" %c", &goal);
       

        if (goal != 'M' && goal != 'L' && goal != 'G') {
            printf("Please Enter a valid goal!\n");
        }
    } while (goal != 'M' && goal != 'L' && goal != 'G');

    
    
    //Calcs BMR
    BMR = (10*weight) + (6.25*height) - (5*age);
    //printf("%f",BMR); for debugging

    //Calcs BMR based on gender
    //male
    if(gender == 'M'){
        BMR += 5;
    }
    else {
        BMR -= 161;
    }

    //Calcs Daily Calories based On Weight goal
    //Lose weight
    if(goal == 'L') {
        dailyCalories = BMR - 200;

    }
    //Gain Weight
    else if(goal == 'G') {
        dailyCalories = BMR + 500;
        
    }
    //Maintain Weight
    else{
        dailyCalories = BMR + 300;
    }

    //Displays Daily Calories.
    printf("Your Daily Calories are: %.0f", dailyCalories);


    //writes their goal daily calories to a file.
    FILE *g = fopen("goal.txt", "w");
    if (g != NULL) {
    fprintf(g, "%.0f\n", dailyCalories);
    fclose(g);
    }

}


//tracks cals func
void trackCalories() {
    int todayCalories;
    FILE *caloriefile;
    FILE *goalFile;
    int goal;

    printf("\n----------- Track Today's Calories -----------\n");
    //asks for calories eaten today
    printf("How Many Calories did you eat today: ");
    scanf("%d", &todayCalories);
    //opens file to get their calorie goal
    goalFile = fopen("goal.txt", "r");
    if (goalFile != NULL) {
        fscanf(goalFile, "%d", &goal);
        fclose(goalFile);
    //for if they haven't calculated their caloric goal yet.
    } else {
        printf("Please use Calorie Calculator, To calculate your goal first!\n");
        return;
    }
    //appends the calories they've eaten today to calories file
    caloriefile = fopen("calories.txt", "a");
    if (caloriefile == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(caloriefile, "%d\n", todayCalories);
    fclose(caloriefile);
    //displays what they ate today against their goal
    printf("Your Calorie Goal: %d\n Today You ate: %d Kcals\n", goal, todayCalories);
    //displays if they met/exceeded/underexceeded their caloric goal
    if(todayCalories>goal) {
        printf("You've eaten Above your goal Calories :(\n");
    }
    else if(todayCalories<goal) {
        printf("You've eaten Below your goal Calories :(\n");
    }
    else {
        printf("You've Reached your caloric goal :)\n");
    }
    //displays calories saved
    printf("Todays Calories Saved!\n");
}

