#include "headers.h"

Node* createList(int data) {
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    head->data = data;
    head->next = NULL;
    return head;
}

void insertAtBeginning(Node** head, int data) {
    Node* new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new->data = data;
    new->next = *head;
    *head = new;
    return ;
}

void insertAtEnd(Node** head, int data) {
    Node* new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return ;
    }
    new->data = data;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
        return ;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return;
}

void insertAtPosition(Node **head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return ;
    }
    if (position == 0) {
        insertAtBeginning(head, data);
        return ;
    }
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return ;
    }
    new->data = data;
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(new);
            return ;
        }
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return ;
}

void deleteAtBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return ;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return ;
}

void deleteAtEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return ;
    }
    Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return ;
}

void deleteAtPosition(Node **head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return ;
    }
    if (*head == NULL) {
        printf("List is empty\n");
        return ;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    Node *temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return ;
        }
        temp = temp->next;
    }
    Node *Delete = temp->next;
    if (Delete == NULL) {
        printf("Position out of bounds\n");
        return ;
    }
    temp->next = Delete->next;
    free(Delete);
    return ;
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ", temp->data);
    printf("NULL\n");
}

