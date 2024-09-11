#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Function to insert a node at the rear end
void insertRear(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the rear end
void deleteRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp == head) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
}

// Function to insert a node at a given position
void insertAt(int data, int position) {
    if (position < 1 || position > countNodes() + 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) { // Insert at the beginning
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from a given position
void deleteAt(int position) {
    if (position < 1 || position > countNodes()) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) { // Delete the first node
        struct Node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        struct Node *temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }

        struct Node *toBeDeleted = temp->next;
        temp->next = toBeDeleted->next;
        if (toBeDeleted->next != NULL) {
            toBeDeleted->next->prev = temp;
        }
        free(toBeDeleted);
    }
}

// Function to insert a node after another node
void insertAfter(struct Node *afterNode, int data) {
    if (afterNode == NULL) {
        printf("Invalid afterNode.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = afterNode->next;
    newNode->prev = afterNode;
    if (afterNode->next != NULL) {
        afterNode->next->prev = newNode;
    }
    afterNode->next = newNode;
}

// Function to insert a node before another node
void insertBefore(struct Node *beforeNode, int data) {
    if (beforeNode == NULL) {
        printf("Invalid beforeNode.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->prev = beforeNode->prev;
    newNode->next = beforeNode;
    if (beforeNode->prev != NULL) {
        beforeNode->prev->next = newNode;
    }
    beforeNode->prev = newNode;
}

// Function to traverse the list
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverse() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;
    }

    head = temp->prev;
}

// Function to count the number of nodes in the list
int countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice, data, position;

    while (1) {
        printf("1. Insert at Rear\n");
        printf("2. Delete from Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Insert After\n");
        printf("6. Insert Before\n");
        printf("7. Traverse\n");
        printf("8. Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 2:
                deleteRear();
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAt(data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAt(position);
                break;
            case 5:
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
                break;
            case 6:
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
                break;
            case 7:
                traverse();
                break;
            case 8:
                reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}