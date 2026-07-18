#include "headers.h"

Node createList(int data) {
    Node head = (Node)malloc(sizeof(struct node));
    if (head == NULL) {
        return NULL;
        printf("Memory allocation failed\n");
    }
    head->data = data;
    head->next = NULL;
    return head;
}

Status insertAtBeginning(Node head, int data) {
    Node new = (Node)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return FAILURE;        
    }
    new->data = data;
    new->next = head;
    head = new;
    return SUCCESS;
}

Status insertAtEnd(Node head, int data) {
    Node new = (Node)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    new->data = data;
    new->next = NULL;
    if (head == NULL) {
        head = new;
        return SUCCESS;
    }
    Node temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return SUCCESS;
}

Status insertAtPosition(Node head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return FAILURE;
    }
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node new = (Node)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    new->data = data;
    Node temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(new);
            return FAILURE;
        }
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    return SUCCESS;
}

Status deleteAtBeginning(Node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return FAILURE;
    }
    Node temp = head;
    head = head->next;
    free(temp);
    return SUCCESS;
}

Status deleteAtEnd(Node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return FAILURE;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return SUCCESS;
    }
    Node temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return SUCCESS;
}

Status deleteAtPosition(Node head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return FAILURE;
    }
    if (head == NULL) {
        printf("List is empty\n");
        return FAILURE;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    Node temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of bounds\n");
            return FAILURE;
        }
        temp = temp->next;
    }
    Node Delete = temp->next;
    if (Delete == NULL) {
        printf("Position out of bounds\n");
        return FAILURE;
    }
    temp->next = Delete->next;
    free(Delete);
    return SUCCESS;
}

void displayList(Node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

