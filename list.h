/*****************************************************************************************************
* File: list.h
* Course: Data Structures and Algorithms for Engineers
* Project: A2
* Author: Xincheng Huang
* Copyright: Copyright (c) 2018 Carnegie Mellon University
* Versions:
*	1.0 September 2018
*
* Description:
* This is the head file of list.c. This file claims all structs and functions used the linked list ADT.
*
* Compilation and Execution Instructions:
*
* 	Compiler: gcc
*	Operating System: Windows 7, 8. 10 MacOS
*	Special Libraries: none
* 	Execution Environment: Windows Comand Line, MacOS Command Line, Unix Command Line
*
* Parameters: None
*
*****************************************************************************************************/

#ifndef A2_CORE_LIST_H
#define A2_CORE_LIST_H

#endif //A2_CORE_LIST_H
#define NSIZE 51 //The maxsize of both the first name and the last name
#define DSIZE 11 //The maxsize for the date

//C doesn't have a boolean type, so...
typedef enum {
    false, true
} bool;

//The item for ADT, basically it can be changed to any other stuff;
typedef struct people {
    char firstName[NSIZE]; //The first name
    char lastName[NSIZE]; //The last name
    char birthday[DSIZE]; //The birthday
} Item;

//The struct for ADT. Each one includes an item and an pointer to the next node.
typedef struct node {
    Item item; //The information of one person, can be changed.
    struct node *next; //The pointer to the next node.
} Node;

//int globalCount=0; //GlobalCounter

typedef Node *List; //The pointer to the first node in the linked list

void initList(List *plist); //Initiates the list.

unsigned int length(const List *plist); //Calculates the size of the list.

bool listIsEmpty(const List *plist); //Checks if the list is empty.

bool listIsFull(const List *plist); //Checks if the list is full, which in C is to check if the memory has been used up.

bool append(Item item, List *plist); //Appends an item behind thr tail of the list.

bool insert(Item item, int index, List *plist); // Inserts an element at any specified position number.

void traverse(const List *plist, void(*pfun)(Item item)); //Traverses the list with a certain function

void emptyTheList(List *plist); //Delete the entire list

bool deleteAt(int index, List *plist); //Deletes the element at position number i.

bool deleteFirst(char lastname[], List *plist); //Deletes the first occurrence of element that has the specified Last Name.

int deleteAny(char lastname[], List *plist); //Deletes any elements that have the specified Last Name.

bool replace(Item item, int index, List *plist); //Replaces the data in the element at position i with a new data record.

bool swap(int indexA, int indexB, List *plist); //Swaps two elements at ant specified numbers.

int countByName(char lastname[], List *plist); //Counts the number of the people have the same lastname.

int countByBirth(char birthday[], List *plist); //Counts the number of the people have the same birthday.

Node *getNode(int index, List *plist); //Gets one person's information at position number.

int searchFirstName(char lastname[], List *plist); //Searches for the specified Last Name in the list.

int searchFirstBirth(char birthday[], List *plist); //Searches for the specified Birthday in the list.

int *searchAllName(char lastname[], List *plist); //Searches for all occurrences of the specified Last Name.

int *searchAllBirth(char birthday[], List *plist); //Searches for all occurrences of the specified Birthday.

//Bellow are Stack ADT

bool stackPush(Item item, List *plist);

Item stackPop(List *plist);

Item stackPeek(List *plist);

int stackLength(List *plist);

//Below are Queue ADT

bool queueEnqueue(Item item, List *plist);

Item queueDequeue(List *plist);

Item queuePeek(List *plist);

int queueLength(List *plist);










