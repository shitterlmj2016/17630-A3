#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showPeople(Item item);//Shows the information of a given person
bool isNumber(char num[]);//Determine if a string is a number or not

void showPeople(Item item) {
    //Printer the first name, the last name and the birthday of the one person.
    printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
}

//Return true only if the argument can be interpreted as a number
bool isNumber(char num[]) {
    int n = strlen(num);//Get the length of the number
    for (int i = 0; i < n; i++) {
        //As long as there are one character that is not a number, return false.
        if (!(num[i] >= '0' && num[i] <= '9'))
            return false;
    }
//All characters are numbers
    return true;
}

int main(void) {
    List people;//Create a list

    initList(&people);//Initialize the list

    //Check if the list is usable
    if (listIsFull(&people)) {//The memory is used up
        fprintf(stderr, "No memory available\n");
        exit(EXIT_FAILURE);
    }

    puts("User Menu");
    puts("Please choose your option by input a character:");
    puts("----------------------------------------------------------------");
    puts("1:Create a stack");
    puts("2:Create a queue");
    puts("x:Exit");
    puts("----------------------------------------------------------------");

    char buf[255];//User input something here to choose a option
    scanf("%s", buf);//Get user's input

    //*Clean the buff
    scanf("%*[^\n]");
    scanf("%*c");
    label0:
    //If the user input x or X, the program will terminate
    if (strcmp(buf, "x") == 0 || strcmp(buf, "X") == 0) {
        puts("exiting...");
        emptyTheList(&people); //Free the list, do some clean up job
        return 0;
    }

    if (strcmp(buf, "1") == 0) goto stack;
    if (strcmp(buf, "2") == 0) goto queue;
    puts("Wrong input, try again!");
    goto label0;


    stack:
    {
        puts("Stack Menu");
        puts("Please choose your option by input a character:");
        puts("----------------------------------------------------------------");
        puts("1:Create a stack from a file");
        puts("2:Push an element on the stack");
        puts("3:Pop an element from the stack");
        puts("4:Peek the stack");
        puts("5:Print number of elements in stack.");
        puts("6:Print elements in the stack");
        puts("x:Delete the stack and exit");
        puts("----------------------------------------------------------------");

        char buf[255];//User input something here to choose a option
        scanf("%s", buf);//Get user's input

        //*Clean the buff
        scanf("%*[^\n]");
        scanf("%*c");

        //If the user input x or X, the program will terminate
        if (strcmp(buf, "x") == 0 || strcmp(buf, "X") == 0) {
            puts("exiting...");
            emptyTheList(&people); //Free the list, do some clean up job
            return 0;
        }

        if (strcmp(buf, "1") == 0) goto s1;
        if (strcmp(buf, "2") == 0) goto s2;
        if (strcmp(buf, "3") == 0) goto s3;
        if (strcmp(buf, "4") == 0) goto s4;
        if (strcmp(buf, "5") == 0) goto s5;
        if (strcmp(buf, "6") == 0) goto s6;
        puts("Wrong input, try again!");
        goto stack;
    }

    s1:
    s2:
    s3:
    s4:
    s5:
    s6:


    queue:
    {
        puts("Queue Menu");
        puts("Please choose your option by input a character:");
        puts("----------------------------------------------------------------");
        puts("1:Create a queue from a file");
        puts("2:Enqueue an element");
        puts("3:Dequeue an element from the queue");
        puts("4:Peek the queue");
        puts("5:Print number of elements in queue");
        puts("6:Print elements in the queue");
        puts("x:Delete the queue and exit");
        puts("----------------------------------------------------------------");

        char buf[255];//User input something here to choose a option
        scanf("%s", buf);//Get user's input

        //*Clean the buff
        scanf("%*[^\n]");
        scanf("%*c");

        //If the user input x or X, the program will terminate
        if (strcmp(buf, "x") == 0 || strcmp(buf, "X") == 0) {
            puts("exiting...");
            emptyTheList(&people); //Free the list, do some clean up job
            return 0;
        }
        if (strcmp(buf, "1") == 0) goto q1;
        if (strcmp(buf, "2") == 0) goto q2;
        if (strcmp(buf, "3") == 0) goto q3;
        if (strcmp(buf, "4") == 0) goto q4;
        if (strcmp(buf, "5") == 0) goto q5;
        if (strcmp(buf, "6") == 0) goto q6;
        puts("Wrong input, try again!");
        goto queue;
    }

    q1:
    q2:
    q3:
    q4:
    q5:
    q6:


}