#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} CircularLinkedList;

// Initialize list
void initCircularLinkedList(CircularLinkedList *list) {
    list->head = NULL;
}

// Add element
void addCircular(CircularLinkedList *list, int element) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = element;

    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
    } else {
        Node *current = list->head;

        while (current->next != list->head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = list->head;
    }
}

// Remove element
void removeCircular(CircularLinkedList *list, int element) {

    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;

    do {
        if (current->data == element) {

            if (current == list->head &&
                current->next == list->head) {

                list->head = NULL;
            }

            else if (current == list->head) {

                Node *temp = list->head;

                while (temp->next != list->head) {
                    temp = temp->next;
                }

                temp->next = list->head->next;
                list->head = list->head->next;
            }

            else {
                prev->next = current->next;
            }

            free(current);
            printf("Element %d removed\n", element);
            return;
        }

        prev = current;
        current = current->next;

    } while (current != list->head);

    printf("Element not found\n");
}

// Display
void displayCircular(CircularLinkedList *list) {

    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = list->head;

    printf("Circular Linked List: ");

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("\n");
}

// Size
int sizeCircular(CircularLinkedList *list) {

    if (list->head == NULL)
        return 0;

    int count = 0;
    Node *current = list->head;

    do {
        count++;
        current = current->next;
    } while (current != list->head);

    return count;
}

int main() {

    CircularLinkedList list;

    initCircularLinkedList(&list);

    addCircular(&list, 1);
    addCircular(&list, 2);
    addCircular(&list, 3);

    printf("After adding:\n");
    displayCircular(&list);

    removeCircular(&list, 2);

    printf("After deleting:\n");
    displayCircular(&list);

    printf("Size = %d\n", sizeCircular(&list));

    return 0;
}