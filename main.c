#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void showPeople(Item item);//Shows the information of a given person
bool isNumber(char num[]);//Determine if a string is a number or not

void showPeople(Item item) {
    //Printer the first name, the last name and the birthday of the one person.
    //printf("%d\n:",globalCount);
    printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
    //globalCount++;
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
    List stackPeople;//Create a stack
    List queuePeople;//Create a queue

    initList(&stackPeople);//Initialize the list
    initList(&queuePeople);//Initialize the queue



    //Check if the list is usable
    if (listIsFull(&stackPeople)) {//The memory is used up
        fprintf(stderr, "No memory available\n");
        exit(EXIT_FAILURE);
    }

    if (listIsFull(&queuePeople)) {//The memory is used up
        fprintf(stderr, "No memory available\n");
        exit(EXIT_FAILURE);
    }



    stack:
    queue:
    //main menu
    {   puts("Please choose your option by input a character:");
        puts("Stack Menu");
        puts("----------------------------------------------------------------");
        puts("1:Create a stack from a file");
        puts("2:Push an element on the stack");
        puts("3:Pop an element from the stack");
        puts("4:Peek the stack");
        puts("5:Print number of elements in stack.");
        puts("6:Print elements in the stack");
        puts("7:Delete the stack and exit");
        puts("----------------------------------------------------------------");
        puts("");
        puts("Queue Menu");
        puts("----------------------------------------------------------------");
        puts("8:Create a queue from a file");
        puts("9:Enqueue an element");
        puts("10:Dequeue an element from the queue");
        puts("11:Peek the queue");
        puts("12:Print number of elements in queue");
        puts("13:Print elements in the queue");
        puts("14:Delete the queue");
        puts("----------------------------------------------------------------");
        puts("Press X or x to exit!");



        char buf[255];//User input something here to choose a option
        scanf("%s", buf);//Get user's input

        //*Clean the buff
        scanf("%*[^\n]");
        scanf("%*c");

        //If the user input x or X, the program will terminate
        if (strcmp(buf, "x") == 0 || strcmp(buf, "X") == 0) {
            puts("exiting...");
            return 0;
        }

        if (strcmp(buf, "1") == 0) goto s1;
        if (strcmp(buf, "2") == 0) goto s2;
        if (strcmp(buf, "3") == 0) goto s3;
        if (strcmp(buf, "4") == 0) goto s4;
        if (strcmp(buf, "5") == 0) goto s5;
        if (strcmp(buf, "6") == 0) goto s6;
        if (strcmp(buf, "7") == 0) goto s7;
        if (strcmp(buf, "8") == 0) goto q1;
        if (strcmp(buf, "9") == 0) goto q2;
        if (strcmp(buf, "10") == 0) goto q3;
        if (strcmp(buf, "11") == 0) goto q4;
        if (strcmp(buf, "12") == 0) goto q5;
        if (strcmp(buf, "13") == 0) goto q6;
        if (strcmp(buf, "14") == 0) goto q7;
        puts("Wrong input, try again!");
        goto stack;
    }

    //read from a file
    s1:
    {
        puts("Please input the file address using the following format:");
        puts("C:\\Users\\xchuang1995\\Desktop\\io.txt");
        puts("Now type in your file address:");
        char address[1024];//The buff for the address
        scanf("%s", address);//Get the address input by the user
        int len;
        FILE *fp;//Basic IO stuff
        if ((fp = fopen(address, "r")) == NULL)//Try to open the file
        {   //Fail to open
            perror("Fail to read");
            puts("please enter a correct file path!");
            puts("Returning to the main menu...");
            goto stack;
        }

        //File opened successfully.
        char buf[NSIZE];
        Item new;
        int counter=0;
        while (!feof(fp)) {   //In each round, copy the person's data from the file

            //Copy the first name
            fgets(buf, NSIZE, fp);
//            int len=strlen(buf);
//            //Add \0 to the end of the string
//            buf[len - 1] = '\0';
            //Add \0 to the end of the string
            //Copy the data
            if(buf[strlen(buf)-1] == '\n')
                buf[strlen(buf)-1] = '\0';
            if(counter%3==0)
                strcpy(new.firstName, buf);
            if(counter%3==1)
                strcpy(new.lastName, buf);
            if(counter%3==2) {
                strcpy(new.birthday, buf);
                append(new, &stackPeople);
            }
            counter++;
        }
        puts("Import successful!");
        fclose(fp);
        //Showing the whole list to user after importing the data
        printf("Here's the whole stack:\n");
        //Traverse the list to get the whole information
        traverse(&stackPeople, showPeople);
        printf("Returning to main menu...\n");
        goto stack;

    }


    s2:
    {// Push an element on the stack
        Item tempp;//Create an item to be added to the list
        puts("Please enter the first name, the last name and the birthday in order.");
        puts("Notice that the first name and the last name shall be no longer than 50 characters!");
        puts("Now enter the first name(Less than 50 characters):");

        scanf("%50s", &tempp.firstName);//Get the user's input
        scanf("%*[^\n]");
        scanf("%*c");//Clean the buff
        puts("Now enter the last name(Less than 50 characters):");

        scanf("%50s", &tempp.lastName);//Get the user's input
        puts("Now enter the brithday by MM-DD-YYYY:");
        scanf("%*[^\n]");
        scanf("%*c");//Clean the buff
        scanf("%10s", &tempp.birthday);//Get the user's input
        scanf("%*[^\n]");
        scanf("%*c");//Clean the buff

        if (append(tempp, &stackPeople) == false) {//Check if append is succesful
            fprintf(stderr, "Problem allocating memory\n");
        }

        if (listIsFull(&stackPeople)) {//Check if the list is full.
            puts("The list is now full.\n");
        }

        puts("Enter x to return, enter other characters to continue");
        //Check the user's input
        char buf1[255];
        scanf("%s", buf1);
        char ch1 = buf1[0];
        if (strcmp(buf1, "x") == 0 || strcmp(buf1, "X") == 0) {
            //Case 1: User wants to exit to the main menu
            printf("Here is the whole list:\n");
            //Show the user the whole list before exiting
            traverse(&stackPeople, showPeople);
            printf("Returning to main menu...\n");
            goto stack;
        } else {
            //Case 2: User wants to enter another person
            puts("continue...");
            goto s2;
        }

    }

    s3:
    {//Pop an element from the stack
        if (listIsEmpty(&stackPeople)) {
            printf("The list is empty.\n");
            goto stack;
        } else {
            Item item = stackPop(&stackPeople);
            int length = stackLength(&stackPeople);
            printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
            printf("The length of the stack is %d\n", length);
            goto stack;
        }
    }

    s4:
    {
        //Peak an element from the stack
        if (listIsEmpty(&stackPeople)) {
            printf("The list is empty.\n");
            goto stack;
        } else {
            Item item = stackPeek(&stackPeople);
            int length = stackLength(&stackPeople);
            printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
            printf("The length of the stack is %d\n", length);
            goto stack;
        }

    }

    s5:{//Print the length
    if (listIsEmpty(&stackPeople)) {
        printf("The list is empty.\n");
        goto stack;
    } else {
        int len=stackLength(&stackPeople);
        printf("The length is %d\n",len);
        goto stack;
    }
    }

    s6:{//Print all elements in the stack
    if (listIsEmpty(&stackPeople)) {
        printf("The list is empty.\n");
        goto stack;
    } else {
        traverse(&stackPeople, showPeople);
        printf("Returning to main menu...\n");
        goto stack;
    }

    }

    s7: {
    initList(&stackPeople);
    puts("Stack deleted! Now returning to the main menu");
    goto stack;
    }


    q1:
    {
        puts("Please input the file address using the following format:");
        puts("C:\\Users\\xchuang1995\\Desktop\\io.txt");
        puts("Now type in your file address:");
        char address[1024];//The buff for the address
        scanf("%s", address);//Get the address input by the user
        int len;
        FILE *fp;//Basic IO stuff
        if ((fp = fopen(address, "r")) == NULL)//Try to open the file
        {   //Fail to open
            perror("Fail to read");
            puts("please enter a correct file path!");
            puts("Returning to the main menu...");
            goto queue;
        }

        //File opened successfully.
        char buf[NSIZE];
        while (fgets(buf, NSIZE, fp) != NULL) {   //In each round, copy the person's data from the file
            //Copy the first name
            Item new;
            len = strlen(buf);
            //Add \0 to the end of the string
            if(buf[strlen(buf)-1] == '\n')
                buf[strlen(buf)-1] = '\0';
            strcpy(new.firstName, buf);

            //Copy the last name
            fgets(buf, NSIZE, fp);
            len = strlen(buf);
            if(buf[strlen(buf)-1] == '\n')
                buf[strlen(buf)-1] = '\0';
            strcpy(new.lastName, buf);

            //Copy user's birthday
            fgets(buf, NSIZE, fp);
            len = strlen(buf);
            if(buf[strlen(buf)-1] == '\n')
                buf[strlen(buf)-1] = '\0';
            strcpy(new.birthday, buf);
            append(new, &queuePeople);
        }
        puts("Import successful!");
        //Showing the whole list to user after importing the data
        printf("Here's the whole queue:\n");
        //Traverse the list to get the whole information
        traverse(&queuePeople, showPeople);
        printf("Returning to main menu...\n");
        goto queue;

    }

    q2:{

    Item tempp;//Create an item to be added to the list
    puts("Please enter the first name, the last name and the birthday in order.");
    puts("Notice that the first name and the last name shall be no longer than 50 characters!");
    puts("Now enter the first name(Less than 50 characters):");

    scanf("%50s", &tempp.firstName);//Get the user's input
    scanf("%*[^\n]");
    scanf("%*c");//Clean the buff
    puts("Now enter the last name(Less than 50 characters):");

    scanf("%50s", &tempp.lastName);//Get the user's input
    puts("Now enter the brithday by MM-DD-YYYY:");
    scanf("%*[^\n]");
    scanf("%*c");//Clean the buff
    scanf("%10s", &tempp.birthday);//Get the user's input
    scanf("%*[^\n]");
    scanf("%*c");//Clean the buff

    if (append(tempp, &queuePeople) == false) {//Check if append is succesful
        fprintf(stderr, "Problem allocating memory\n");
    }

    if (listIsFull(&queuePeople)) {//Check if the list is full.
        puts("The list is now full.\n");
    }

    puts("Enter x to return, enter other characters to continue");
    //Check the user's input
    char buf1[255];
    scanf("%s", buf1);
    char ch1 = buf1[0];
    if (strcmp(buf1, "x") == 0 || strcmp(buf1, "X") == 0) {
        //Case 1: User wants to exit to the main menu
        printf("Here is the whole list:\n");
        //Show the user the whole list before exiting
        traverse(&queuePeople, showPeople);
        printf("Returning to main menu...\n");
        goto queue;
    } else {
        //Case 2: User wants to enter another person
        puts("continue...");goto q2;
    }

}

    q3://Dequeue an element
    {
        if (listIsEmpty(&queuePeople)) {
            printf("The queue is empty.\n");
            goto queue;
        } else {
            Item item = queueDequeue(&queuePeople);
            int length = queueLength(&queuePeople);
            printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
            printf("The length of the queue is %d\n", length);
            goto queue;
        }

    }



    q4:
    {
        if (listIsEmpty(&queuePeople)) {
            printf("The queue is empty.\n");
            goto queue;
        } else {
            Item item = queuePeek(&queuePeople);
            int length = queueLength(&queuePeople);
            printf("Firstname: %s Lastname:%s Birthday:%s\n", item.firstName, item.lastName, item.birthday);
            printf("The length of the queue is %d\n", length);
            goto queue;
        }

    }
    q5:
    {
        if (listIsEmpty(&queuePeople)) {
            printf("The queue is empty.\n");
            goto queue;
        } else {
            int len=queueLength(&queuePeople);
            printf("The length is %d\n",len);
            goto queue;
        }

    }
    q6:
    if (listIsEmpty(&queuePeople)) {
        printf("The list is empty.\n");
        goto queue;
    } else {
        traverse(&queuePeople, showPeople);
        printf("Returning to main menu...\n");
        goto queue;
    }

    q7:
    initList(&queuePeople);
    puts("Queue deleted! Now returning to the main menu");
    goto queue;

}

