#ifndef HEADERS_H
#define HEADERS_H 
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;

Node* createList(int);
void insertAtBeginning(Node ** , int );
void insertAtEnd(Node **, int );
void insertAtPosition(Node **, int , int );
void deleteAtBeginning(Node **);
void deleteAtEnd(Node **);
void deleteAtPosition(Node **, int );
void displayList(Node *);

#endif
