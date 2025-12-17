#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "activity.h"

void ActivityMenu(void)
{
    int choice;

    printf("\n----------- Activity Steps -----------\n");
    printf("1. Track Today's Steps\n");
    printf("2. View Weekly Summary\n");
    printf("3. Activity Menu\n");
    printf("--------------------------------------\n");

    printf("Select item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            LogActivity();
            break;

        case 2:
            ViewSummary();
            break;

        case 3:
            ActivityMenu();
            return;

        case 4:
            printf("Returning to main menu...\n");
            return;

        default:
            printf("Invalid option!\n");
            return;
    }
}
//func for logging steps
void LogActivity() {
    int steps;
    float cals;
    FILE *stepsfile;

    printf("\n----------- Log Today's Steps :) -----------\n");
    //asks how many steps walked
    do {
        printf("How many steps did you walk today?\n");
        scanf("%d", &steps);

        if (steps < 0 || steps > 50000) {
            printf("Please enter a valid range of steps!\n");
        }
    } while (steps < 0 || steps > 50000);

    //Calcs how many calories burnt from walking
    cals = steps * 0.04;

    //Displays Calories burnt
    printf("You've Burned %.2f, Calories from walking today!\n", cals);

    //appends how many steps walked today
    stepsfile = fopen("steps.txt", "a");
    if (stepsfile == NULL) {
        printf("Error!");
        return;
    }
    //saves steps
    fprintf(stepsfile, "%d\n", steps);
    fclose(stepsfile);
    printf("Steps Saved :)");


}

//func for viewing weekly steps and calories burnt
void ViewSummary() {
    //opens file in read mode
    FILE *stepsFile = fopen("steps.txt", "r");
    int stepsArray[700];
    int count = 0;
    int steps;
    int total = 0;


    printf("\n----------- View Weekly Steps -----------\n");
    //exits function if unable to open file 
    if (stepsFile == NULL) {
        printf("unable to open file!\n");
        return;
    }
    //reads each step entry and adds to array
    while (fscanf(stepsFile, "%d", &steps) == 1) {
     stepsArray[count] = steps;
     count++;
    }
    //close file 
    fclose(stepsFile);
    //if less than seven days of enteries recorded 
    if (count<7) {
        printf("You need at least 7 days of steps recorded to view weekly summary!\n");
        printf("Right now you only have: %d\n days", count);
        return;
    }
    //sum only last 7 enteries so its weekly
    for (int i = count - 7; i < count; i++) {
        total += stepsArray[i];
    }
    //displays weekly steps
    printf("\nWeekly total steps (last 7 days): %d\n", total);
    //displays calories burned in week from steps
    printf("Calories burned: %.2f\n", total * 0.04);
 }






