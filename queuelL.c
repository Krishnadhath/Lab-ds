#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Function declarations */
void enqueue();
void dequeue();
void peek();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1 -> Enqueue\n2 -> Dequeue\n3 -> Peek\n4 -> Display\n5 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

/* Enqueue Operation (Insert at Rear) */
void enqueue() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue Overflow (Memory not available)\n");
        return;
    }

    printf("Enter value to enqueue: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (rear == NULL) {   // Queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element enqueued successfully\n");
}

/* Dequeue Operation (Remove from Front) */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow (Empty Queue)\n");
        return;
    }

    temp = front;
    printf("Dequeued element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {   // Queue became empty
        rear = NULL;
    }

    free(temp);
}

/* Peek Operation */
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

/* Display Queue */
void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
