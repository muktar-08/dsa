#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char ssn[20], name[30], dept[20], desg[20];
    float sal;
    long phNo;
    struct Node *prev, *next;
};

typedef struct Node *NODE;
NODE head = NULL;
int count = 0;

NODE createNode() {
    NODE temp = (NODE)malloc(sizeof(struct Node));
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone: ");
    scanf("%s %s %s %s %f %ld", temp->ssn, temp->name, temp->dept, temp->desg, &temp->sal, &temp->phNo);
    temp->prev = temp->next = NULL;
    count++;
    return temp;
}

void insertEnd() {
    NODE temp = createNode();
    if (!head) {
        head = temp;
    } else {
        NODE cur = head;
        while (cur->next) cur = cur->next;
        cur->next = temp;
        temp->prev = cur;
    }
}

void insertFront() {
    NODE temp = createNode();
    if (!head) {
        head = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void deleteEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    if (!head->next) {
        printf("Deleted: %s\n", head->ssn);
        free(head);
        head = NULL;
    } else {
        while (temp->next) temp = temp->next;
        printf("Deleted: %s\n", temp->ssn);
        temp->prev->next = NULL;
        free(temp);
    }
    count--;
}

void deleteFront() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    printf("Deleted: %s\n", temp->ssn);
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
    count--;
}

void display() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    NODE cur = head;
    printf("DLL Contents:\n");
    while (cur) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, PhNo: %ld\n",
               cur->ssn, cur->name, cur->dept, cur->desg, cur->sal, cur->phNo);
        cur = cur->next;
    }
    printf("Total nodes: %d\n", count);
}

int main() {
    int choice;
    do {
        printf("\n1. Create DLL (Insert at End)\n2. Display DLL and Count Nodes\n");
        printf("3. Insert at Front\n4. Delete from Front\n5. Insert/Delete at End\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertEnd();
            break;
        case 2:
            display();
            break;
        case 3:
            insertFront();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            printf("1. Insert at End\n2. Delete from End\n");
            int subChoice;
            scanf("%d", &subChoice);
            if (subChoice == 1)
                insertEnd();
            else if (subChoice == 2)
                deleteEnd();
            else
                printf("Invalid choice!\n");
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

