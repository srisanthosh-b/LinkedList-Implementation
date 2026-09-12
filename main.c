#include "headers.h"
int main() {
    Node* head = createList(10);
    displayList(head);
    insertAtBeginning(&head, 20);
    displayList(head);
    insertAtEnd(&head, 30);
    displayList(head);

    deleteAtBeginning(&head);
    displayList(head);

    deleteAtEnd(&head);
    displayList(head);

    deleteAtPosition(&head, 0);
    displayList(head);
    deleteList(&head);

    return 0;
}