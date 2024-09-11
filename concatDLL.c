#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *concatenate(struct Node *X1, struct Node *X2) {
    if (X1 == NULL) return X2;
    if (X2 == NULL) return X1;

    struct Node *temp = X1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = X2;
    X2->prev = temp;

    return X1;
}

void createList(struct Node **head, int size) {
    struct Node *temp = NULL;
    for (int i = 0; i < size; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(newNode->data));
        newNode->prev = temp;
        newNode->next = NULL;

        if (temp == NULL) *head = newNode;
        else temp->next = newNode;
        temp = newNode;
    }
}

void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, size1, size2;
    struct Node *X1 = NULL, *X2 = NULL;

    while (1) {
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Concatenate Lists\n");
        printf("4. Print Lists\n");
        printf("5. Print Concatenated List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of List 1: ");
                scanf("%d", &size1);
                createList(&X1, size1);
                break;
            case 2:
                printf("Enter size of List 2: ");
                scanf("%d", &size2);
                createList(&X2, size2);
                break;
            case 3:
                X1 = concatenate(X1, X2);
                printf("Lists concatenated.\n");
                break;
            case 4:
                printf("List 1:\n");
                printList(X1);
                printf("List 2:\n");
                printList(X2);
                break;
            case 5:
                if (X1 != NULL) {
                    printf("Concatenated List:\n");
                    printList(X1);
                } else {
                    printf("Lists not concatenated yet.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}