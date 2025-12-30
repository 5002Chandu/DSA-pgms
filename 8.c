#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold employee data
struct Employee {
    char ssn[20];
    char name[50];
    char dept[30];
    char designation[30];
    float sal;
    char phno[15];
    struct Employee* prev;
    struct Employee* next;
};

typedef struct Employee* NODE;
NODE head = NULL;

// Function to create a new node
NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter SSN: ");
    scanf("%s", newNode->ssn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Dept: ");
    scanf("%s", newNode->dept);
    printf("Enter Designation: ");
    scanf("%s", newNode->designation);
    printf("Enter Salary: ");
    scanf("%f", &newNode->sal);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);

    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd() {
    NODE newNode = createNode();

    if (head == NULL) {
        head = newNode;
    } else {
        NODE temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Employee inserted at the end.\n");
}

// Insert at front
void insertFront() {
    NODE newNode = createNode();

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Employee inserted at the front.\n");
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted employee with SSN: %s\n", head->ssn);
        free(head);
        head = NULL;
        return;
    }

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted employee with SSN: %s\n", temp->ssn);
    temp->prev->next = NULL;
    free(temp);
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE temp = head;

    if (head->next == NULL) {
        printf("Deleted employee with SSN: %s\n", head->ssn);
        free(head);
        head = NULL;
        return;
    }

    head = head->next;
    head->prev = NULL;
    printf("Deleted employee with SSN: %s\n", temp->ssn);
    free(temp);
}

// Display list and count nodes
void displayAndCount() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int count = 0;
    NODE temp = head;

    printf("\n--- Employee List ---\n");
    while (temp != NULL) {
        printf("SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %.2f | Phone: %s\n",
               temp->ssn, temp->name, temp->dept,
               temp->designation, temp->sal, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total employees: %d\n", count);
}

// Double Ended Queue demo
void doubleEndedQueueDemo() {
    int choice;
    while (1) {
        printf("\nDouble Ended Queue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: insertFront(); break;
        case 2: insertEnd(); break;
        case 3: deleteFront(); break;
        case 4: deleteEnd(); break;
        case 5: return;
        default: printf("Invalid choice.\n");
        }
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Employee DLL Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display and Count\n");
        printf("3. Insert at Front\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Front\n");
        printf("6. Double Ended Queue Demo\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: insertEnd(); break;
        case 2: displayAndCount(); break;
        case 3: insertFront(); break;
        case 4: deleteEnd(); break;
        case 5: deleteFront(); break;
        case 6: doubleEndedQueueDemo(); break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}
