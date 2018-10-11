/*****************************************************************************************************
* File: list.c
* Course: Data Structures and Algorithms for Engineers
* Project: A2
* Author: Xincheng Huang
* Copyright: Copyright (c) 2018 Carnegie Mellon University
* Versions:
*	1.0 September 2018
*
* Description:
* This file clarifies all functions defined in list.h
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


static void CopyToNode(Item item, Node *pnode) // Copy the data (which in this case is a person) to an node
{
    pnode->item = item;
}

void initList(List *plist) //Initiates the list.
{
    *plist = NULL;
}

bool listIsEmpty(const List *plist)  //Checks if the list is empty.
{
    return *plist == NULL ? true : false;
}

bool listIsFull(const List *plist)  //Checks if the list is full.
{
    if (plist == NULL) return false;//The list hasn't been initialized
    Node *pt;
    pt = (Node *) malloc(sizeof(Node));
    return pt == NULL ? true : false; //Check if the memory has been used up.
}

unsigned int length(const List *plist) { //Calculates the size of the list.
    if (plist == NULL) return 0;//The list hasn't been initialized
    unsigned int count = 0; //Sets a counter
    Node *pnode = *plist; //Traverses the list
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

bool insert(Item item, int index, List *plist) { // Inserts an element at any specified position number.
    int currentLength = length(plist); // Checks if the input number is legal.
    if (currentLength < index) {
        puts("OutBounds!");
        return false; // Illegal
    } else {
        Node *pnew;
        Node *scan = *plist;
        pnew = (Node *) malloc(sizeof(Node)); // Allocate a new node
        if (pnew == NULL) return false; // Allocation failed
        CopyToNode(item, pnew); //Allocation successful

        //Case 1: Insert this node to the head of the list
        if (index == 0) {
            pnew->next = *plist;
            *plist = pnew;
            return true;
        }

        //Case 2: Insert this node between other nodes or at the tail
        for (int i = 0; i < index - 1; i++) {
            scan = scan->next;
        }

        pnew->next = scan->next;
        scan->next = pnew;
        return true;

    }

}

//Deletes the element at position number i.
bool deleteAt(int index, List *plist) {
    if (plist == NULL) return false;//The list hasn't been initialized
    // Checks if the input number is legal.
    int currentLength = length(plist);
    if (currentLength < index || index < 0) {
        puts("OutBounds!");
        return false;
    } else {
        //Case1: Delete the first node
        if (index == 0) {
            Node *temp = *plist;
            temp = temp->next;
            free(*plist);
            *plist = temp;
            return true;
        }

        //Case2: Delete other nodes
        Node *scan = *plist;
        for (int i = 0; i < index - 1; i++) {
            scan = scan->next;
        }

        Node *temp = scan;
        temp = temp->next;
        scan->next = scan->next->next;
        free(temp);
        return true;

    }

}


//Replaces the data in the element at position i with a new data record.
bool replace(Item item, int index, List *plist) {
    if (plist == NULL) return false;//The list hasn't been initialized
    //Check if the input number is legal
    int currentLength = length(plist);
    if (currentLength - 1 < index) {
        puts("OutBounds!");
        return false;
    } else {
        //Search for the node
        Node *scan = *plist;
        for (int i = 0; i < index; i++) {
            scan = scan->next;
        }
        //Modify its content
        scan->item = item;
        return true;

    }

}

//Swaps two elements at ant specified numbers.
bool swap(int indexA, int indexB, List *plist) {
    if (plist == NULL) return false;//The list hasn't been initialized
    int currentLength = length(plist);
    //Check if the input number is legal
    if (currentLength - 1 < indexA || currentLength - 1 < indexB) {
        puts("OutBounds!");
        return false;
    } else {
        //Find these two nodes based on given positions
        Node *scanA = *plist;
        Node *scanB = *plist;
        for (int i = 0; i < indexA; i++) {
            scanA = scanA->next;
        }
        for (int i = 0; i < indexB; i++) {
            scanB = scanB->next;
        }
        //Swap their contents
        Item itemA = scanA->item;
        scanA->item = scanB->item;
        scanB->item = itemA;
        return true;

    }


}

//Deletes the first occurrence of element that has the specified Last Name.
bool deleteFirst(char lastname[], List *plist) {
    if (plist == NULL) return false;//The list hasn't been initialized
    int index;
    //Seatch for its position
    if ((index = searchFirstName(lastname, plist)) < 0) {
        //Not found
        return false;
    }
    //Found, then delete it.
    deleteAt(index, plist);
    return true;
}

//Deletes any elements that have the specified Last Name.
//Returns the total number of deleted items, could be zero.
int deleteAny(char lastname[], List *plist) {
    if (plist == NULL) return 0;//The list hasn't been initialized
    int deletCount = 0;
    int index;
    //Keep deleting until there's no such item left/
    while ((index = searchFirstName(lastname, plist)) >= 0) {
        deleteAt(index, plist);
        ++deletCount;
    };
    return deletCount;
}

//Deletes any elements that have the specified Last Name.
//If found, returns its position.
//If not found returns -1.
int searchFirstName(char lastname[], List *plist) {
    if (plist == NULL) return 0;//The list hasn't been initialized
    Node *scan = *plist;
    int currentLength = length(plist);
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(lastname, scan->item.lastName) == 0) {
            return i;
        }
        scan = scan->next;
    }
    return -1;
}

//Searches for the specified Birthday in the list.
//If found, returns its position.
//If not found returns -1.
int searchFirstBirth(char birthday[], List *plist) {
    if (plist == NULL) return 0;//The list hasn't been initialized
    Node *scan = *plist;
    int currentLength = length(plist);
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(birthday, scan->item.birthday) == 0) {
            return i;
        }
        scan = scan->next;
    }
    return -1;
}


//Searches for all occurrences of the specified Last Name.
//Then stores their indexes in an array.
//The first position od the array stores the total number of qualified people, could be zero.
int *searchAllName(char lastname[], List *plist) {
    if (plist == NULL) return NULL;//The list hasn't been initialized
    int count = countByName(lastname, plist);
    //Traverses the list to counts how many people are qualified
    //Initialize the return array.
    int *returnArr;
    int arrIndex = 1;
    //Put the number of the qualified people at the first position of the array
    returnArr = (int *) malloc(sizeof(int) * (count + 1));
    returnArr[0] = count;
    Node *scan = *plist;
    int currentLength = length(plist);
    //Traverses again to add qualified people into the return array
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(lastname, scan->item.lastName) == 0) {
            returnArr[arrIndex] = i;
            ++arrIndex;
        }
        scan = scan->next;
    }
    //Return the pointer of the array.
    return returnArr;

}

//Searches for all occurrences of the specified birthday.
//Then stores their indexes in an array.
//The first position od the array stores the total number of qualified people, could be zero.
//It's basically the same compared to the fuction searchAllName.
//The only difference is that this function compares date rather than the name.
int *searchAllBirth(char birthday[], List *plist) {
    if (plist == NULL) return NULL;//The list hasn't been initialized
    int count = countByBirth(birthday, plist);
    int *returnArr;
    int arrIndex = 1;
    returnArr = (int *) malloc(sizeof(int) * (count + 1));
    returnArr[0] = count;
    Node *scan = *plist;
    int currentLength = length(plist);
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(birthday, scan->item.birthday) == 0) {
            returnArr[arrIndex] = i;
            ++arrIndex;
        }
        scan = scan->next;
    }
    return returnArr;

}

//Return the pointer to the node based on given index
Node *getNode(int index, List *plist) {
    if (plist == NULL) return NULL;//The list hasn't been initialized
    int len = length(plist);
    //Check if the input index is legal
    if (index > len - 1)
        return NULL;
    Node *scan = *plist;
    //Traverse
    for (int i = 0; i < index; i++) {
        scan = scan->next;
    }
    return scan;
}

//Counts how many people are there having the same lastname
int countByName(char lastname[], List *plist) {
    if (plist == NULL) return 0;//The list hasn't been initialized
    Node *scan = *plist;
    int count = 0;
    int currentLength = length(plist);
    //Traverse stuff
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(lastname, scan->item.lastName) == 0) {
            ++count;
        }
        scan = scan->next;
    }

    return count;

}

//Counts how many people are there having the same birthday
int countByBirth(char birthday[], List *plist) {
    if (plist == NULL) return 0;//The list hasn't been initialized
    Node *scan = *plist;
    int count = 0;
    int currentLength = length(plist);
    for (int i = 0; i < currentLength; i++) {
        if (strcmp(birthday, scan->item.birthday) == 0) {
            ++count;
        }
        scan = scan->next;
    }
    return count;

}

//Appends a node to the tail of the linked list
bool append(Item item, List *plist) {
    Node *pnew; // Declare a new node
    Node *scan = *plist;
    pnew = (Node *) malloc(sizeof(Node)); // Allocate memory for this new node
    if (pnew == NULL) return false; // Allocation failed
    CopyToNode(item, pnew); // Copy the item into the node
    pnew->next = NULL; // Set the pointer to the next node to null, meaning this is the tail node.
    if (scan == NULL) // If its an empty list, set it as the head node
        *plist = pnew;
    else {
        while (scan->next != NULL) //Search for the tail of current list
            scan = scan->next;
        scan->next = pnew; //Hook the new node to the old tail node.
    }
    return true;
}

void traverse(const List *plist, void(*pfun)(Item item)) // Put an function on each node from the list
{
    Node *pnode = *plist; // Put a pointer to the head node
    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void emptyTheList(List *plist) // Free the list
{
    Node *psave; // Free the entire list FIFO
    while (*plist != NULL) {
        psave = (*plist)->next;//Store the next node(if exists)
        free(*plist);
        *plist = psave;
    }
}

//Bellow are Stack ADT
bool stackPush(Item item, List *plist) {
    return append(item, plist);
}

Item stackPop(List *plist){
    int len=length(plist);
    Node *node=getNode(len-1,plist);

    //Can't return the pointer, since soon it will be deleted ;
    //Have to create a return item here.
    Item item= node->item;

    //Delete the node
    deleteAt(len-1, plist);

    return item;
}

Item stackPeek(List *plist){
    int len=length(plist);
    Node *node=getNode(len-1,plist);


    Item item= node->item;

    return item;
}

int stackLength(List *plist){
    return length(plist);
}

//Below are Queue ADT

bool queueEnqueue(Item item, List *plist){
    return append(item, plist);
}

Item queueDequeue(List *plist){
    //要检查第一个是否存在
    Node *node=getNode(0,plist);
    Item item= node->item;
    deleteAt(0, plist);
    return item;
}

Item queuePeek(List *plist){
    //要检查第一个是否存在
    Node *node=getNode(0,plist);
    Item item= node->item;
    return item;
}

int queueLength(List *plist){
    return length(plist);
}