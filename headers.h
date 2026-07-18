#ifndef HEADERS_H
#define HEADERS_H 
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node *Node;

typedef enum{
    SUCCESS,
    FAILURE
} Status;

Node createList(int);
Status insertAtBeginning(Node , int );
Status insertAtEnd(Node , int );
Status insertAtPosition(Node , int , int );
Status deleteAtBeginning(Node );
Status deleteAtEnd(Node );
Status deleteAtPosition(Node , int );
void displayList(Node );

#endif
