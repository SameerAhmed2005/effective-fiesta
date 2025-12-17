#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "assistant.h"

void AssistantMenu(void)
{
    int choice;

    printf("\n----------- Assistant -----------\n");
    printf("1. Ask Assistant\n");
    printf("2. Quiz\n");
    printf("3. Back to Main Menu\n");
    printf("--------------------------------------\n");

    printf("Select item: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Assistant();
            break;

        case 2:
            Quiz();
            break;

        case 3:
            printf("Returning to main menu...\n");
            return;

        default:
            printf("Invalid option!\n");
            return;
    }
}

//assistant function
void Assistant() {
    char input[200];
    char name[40];
    FILE *namefile;

    printf("\n----------- Assistant -----------\n");
    //opens file to check if users name has been previously stored
    namefile = fopen("username.txt", "r");
    //if user hasn't entered name before or file doesn't exist
    if (namefile == NULL) {
        printf("Hello Welcome to the Assistant I can help give you advice on your fitness goals!\n");
        printf("To get started, I need to know your name?: \n");
        //reads users name
        scanf("%39s", name);
        //saves and writes name to file 
        namefile = fopen("username.txt", "w");
        if (namefile != NULL) {
            fprintf(namefile, "%s\n", name);
            fclose(namefile);
        }
        printf("Nice to meet you, %s!\n", name);
        printf("Try Ask me questions like: How can I build Muscle?\n");
    }
    //if user has used assistant before and file exists
    else {
        //reads name from file
        fgets(name, sizeof(name), namefile);
        name[strcspn(name, "\n")] = '\0';
        fclose(namefile);
        printf("Welcome back, %s!\n", name);

    }
    //asks user to enter a question
    printf("Hello %s how can I help you today?: \n", name);
    getchar();
    //reads sentence using fgets
    while(1) { 
    //while loop so user can keep asking questions
        fgets(input, sizeof(input), stdin);
        printf("You Asked me: %s\n", input);
        //using strstr to do keyword matching and deciding on advice to give user
            if (strstr(input, "sleep") || strstr(input, "tired") || strstr(input, "rest")) {
                    printf("To Sleep Better: \n");
                    printf("• Try Sleep 7-9 Hours\n");
                    printf("• Avoid Caffiene 6 hours before sleep\n");
                    printf("• Limit Screen time before bed or use blue light glasses\n");
                    printf("• Try sleep same time everyday\n");
                    printf("Let me Know if you need anything else :) \n");

                }
            else if (strstr(input, "lose") || strstr(input, "fat")) {
                    printf("To Lose Fat: \n");
                    printf("• Try A Calorie Deficit (eat fewer calories than you burn)\n");
                    printf("• Try aim for 7,000-10,000 steps everyday\n");
                    printf("• Stay Hydrated\n");
                    printf("• Try to be more active as it increases metabolism\n");
                    printf("Let me Know if you need anything else :) \n");
                    
                }
            else if (strstr(input, "muscle") || strstr(input, "build") || strstr(input, "gain")) {
                printf("To build muscle: \n");
                printf("• Train with strength exercise 3-4 times a week\n");
                printf("• Make sure your increasing the weights weekly\n");
                printf("• Aim for 7-9 hours sleep per night\n");
                printf("• Add more Protein to your diet, and slightly more calories\n");
                printf("Let me Know if you need anything else :) \n");
                }

            else if (strstr(input, "study") || strstr(input, "revision") || strstr(input, "exam")) {
                    printf("To improve your studying: \n");
                    printf("• Break your studying into short bursts like 25-45 mins with small breaks\n");
                    printf("• Keep your phone in another room or away!!\n");
                    printf("• Focus on understanding the content, then practice questions\n");
                    printf("• Sleep well as memory will retain better!\n");
                    printf("Let me Know if you need anything else :) \n");
                }

            else if (strstr(input, "diet") || strstr(input, "food") || strstr(input, "eat")) {
                    printf("To Improve your diet: \n");
                    printf("• Focus on whole foods like rice, chicken, fruit and veggies\n");
                    printf("• Try eat 20-40g protein per meal\n");
                    printf("• Follow the 80/20 rule where most of your food is healthy, but sometimes you can have cheat ones\n");
                    printf("Let me Know if you need anything else :) \n");
                }
            else if (strstr(input, "steps") || strstr(input, "walk") || strstr(input, "activity")) {
                    printf("To increase activity: \n");
                    printf("• Try walk 7,000-10,000 steps a day \n");
                    printf("• Take short walks during breaks instead of just sitting\n");
                    printf("• Use stairs instead of the lift if possible\n");
                    printf("Let me Know if you need anything else :) \n");
                }
        else if (strstr(input, "water") || strstr(input, "drink") || strstr(input, "hydration")) {
                    printf("Hydration Advice: \n");
                    printf("• Drink 2-3 litres water a day \n");
                    printf("• Keep a bottle with you when working\n");
                    printf("• Drink more water during physical activites or hot days\n");
                    printf("• Staying Hydrated improves focus and reduces fatigue\n");
                    printf("Let me Know if you need anything else :) \n");
                }
            //this for if assistant can't match what user is saying
            else {
                printf("Im afriad im not sure about that yet :(\nTry ask me something fitness related!\n");
            }
    }
}
//quiz function
void Quiz(){
    int score;
    int answer;
    score = 0;

    printf("\n----------- Test your knowledge!! -----------\n");
    //question One
    printf("1) How Many Hours should you sleep per night?\n");
    printf("1. 4-6\n2. 7-9\n3. 3-4\nYour answer: ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct! :)\n");
        score++;
    }
    else {
        printf("Nope it's 7-9 hours!\n");
    }
    //question Two
    printf("2) When Trying to build muscle you should eat more ___?\n");
    printf("1. Carbohydrates\n2. Protein\n3. Fats\nYour answer: ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct! :)\n");
        score++;
    }
    else {
        printf("Nope it's Protein, think of eating more meat, eggs and dairy\n");
    }
    //question Three
    printf("3) When trying to lose weight you should go on a calorie ___?\n");
    printf("1. Surplus\n2. Maintenece \n3. Deficit\nYour answer: ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct! :)\n");
        score++;
    }
    else {
        printf("Nope it's a deficit, you want to eat less calories!\n");
    }
    //question Four
    printf("4) How Many Litres of water should you drink a day?\n");
    printf("1. 2-3\n2. 1-1.5\n3. 4\nYour answer: ");
    scanf("%d", &answer);
    if (answer == 1) {
        score++;
        printf("Correct! :)\n");
    }
    else {
        printf("Not quite, for most people 2-3 litres a day is good enough!\n");
    }
    //question Five
    printf("5) How Many Steps should aim for daily?\n");
    printf("1. 10,000\n2. 5,000\n3. 20,000\nYour answer: ");
    scanf("%d", &answer);
    if (answer == 1) {
        score++;
        printf("Correct! :)\n");
    }
    else {
        printf("Not quite, around 7,000-10,000 is a good goal!\n");
    }
    //shows score out of 5 
    printf("Your Score is %d/5", score);
}