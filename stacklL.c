#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

/* Function declarations */
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1 -> Push\n2 -> Pop\n3 -> Peek\n4 -> Display\n5 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

/* Push Operation */
void push() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }

    printf("Enter value to push: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}

/* Pop Operation */
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow (Empty Stack)\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

/* Peek Operation */
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

/* Display Stack */
void display() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
