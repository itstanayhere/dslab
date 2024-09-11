#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBefore(struct Node *beforeNode, int data) {
    if (beforeNode == NULL) {
        printf("Invalid beforeNode.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = beforeNode;
    if (head == beforeNode) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp != NULL && temp->next != beforeNode) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(struct Node *afterNode, int data) {
    if (afterNode == NULL) {
        printf("Invalid afterNode.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = afterNode->next;
    afterNode->next = newNode;
}

void deleteNode(int data) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (temp == head) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void traverse() {
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

void reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void sort() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteAlternateNodes() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp->next = temp->next->next;
        temp = temp->next;
    }
}

void insertSorted(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void createList() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertSorted(data); // Insert elements in sorted order
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("1. Create list\n");
        printf("2. Insert before\n");
        printf("3. Insert after\n");
        printf("4. Delete\n");
        printf("5. Traverse\n");
        printf("6. Reverse\n");
        printf("7. Sort\n");
        printf("8. Delete alternate nodes\n");
        printf("9. Insert sorted\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                traverse();
                break;
            case 2:
                printf("Enter data and node to insert before: ");
                scanf("%d", &data);
                struct Node *beforeNode = head;
                while (beforeNode != NULL && beforeNode->data != data) {
                    beforeNode = beforeNode->next;
                }
                if (beforeNode != NULL) {
                    insertBefore(beforeNode, data);
                } else {
                    printf("Node not found.\n");
                }
                traverse();
                break;
            case 3:
                printf("Enter data and node to insert after: ");
                scanf("%d", &data);
                struct Node *afterNode = head;
                while (afterNode != NULL && afterNode->data != data) {
                    afterNode = afterNode->next;
                }
                if (afterNode != NULL) {
                    insertAfter(afterNode, data);
                } else {
                    printf("Node not found.\n");
                }
                traverse();
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                traverse();
                break;
            case 5:
                traverse();
                break;
            case 6:
                reverse();
                traverse();
                break;
            case 7:
                sort();
                traverse();
                break;
            case 8:
                deleteAlternateNodes();
                traverse();
                break;
            case 9:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertSorted(data);
                traverse();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}