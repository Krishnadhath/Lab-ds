#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int size = 0;
struct node *head = NULL;
struct node *newnode, *temp, *temp1, *delnode;

int insertion();
int deletion();
void display(struct node *ptr);

// ============ MAIN ============

int main() {
    int choice;
    while (1) {
        printf("\n1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);           // FIXED: &choice

        switch (choice) {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display(head);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

// ============ INSERTION HELPERS ============

void ins_beg() {
    newnode->next = head;
    head = newnode;
}

void ins_end() {
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void ins_anypos() {
    int pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    // FIXED condition: invalid if pos < 1 or > size + 1
    if (pos < 1 || pos > size + 1) {
        printf("INVALID POSITION\n");
        return;
    }

    if (pos == 1) {
        ins_beg();
        return;
    }

    if (pos == size + 1) {
        ins_end();
        return;
    }

    int i = 2;
    while (i < pos) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// ============ INSERTION MAIN ============

int insertion() {
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    temp = head;

    printf("Enter element to insert: ");
    scanf("%d", &newnode->data);

    if (size == 0) {
        ins_beg();
        size++;
        display(head);
        return 0;
    }

    int type;
    printf("1 -> Insert at beginning\n2 -> Insert at end\n3 -> Insert at any position\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    switch (type) {
    case 1:
        ins_beg();
        break;
    case 2:
        ins_end();
        break;
    case 3:
        ins_anypos();
        break;
    default:
        printf("Invalid type\n");
        free(newnode);
        return 0;
    }

    size++;
    display(head);
    return 0;
}

// ============ DELETION HELPERS ============

void dlt_beg() {
    temp = head;
    head = temp->next;
    free(temp);
}

void dlt_end() {
    while (temp->next != NULL) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
}

void dlt_anypos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {          // FIXED condition
        printf("INVALID POSITION\n");
        return;
    }

    if (pos == 1) {
        dlt_beg();
        return;
    }

    if (pos == size) {
        dlt_end();
        return;
    }

    temp = head;
    int i = 2;
    while (i < pos) {
        temp = temp->next;
        i++;
    }

    delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}

// ============ DELETION MAIN ============

int deletion() {
    if (size == 0) {
        printf("List is empty\n");
        return 0;
    }

    temp = head;

    if (size == 1) {
        dlt_beg();
        size--;
        display(head);
        return 0;
    }

    int type;
    printf("1 -> Delete from beginning\n2 -> Delete from end\n3 -> Delete from any position\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    switch (type) {
    case 1:
        dlt_beg();
        break;
    case 2:
        dlt_end();
        break;
    case 3:
        dlt_anypos();
        break;
    default:
        printf("Invalid type\n");
        return 0;
    }

    size--;
    display(head);
    return 0;
}

// ============ DISPLAY ============

void display(struct node *ptr) {
    if (ptr == NULL) {                // FIXED: just ptr == NULL
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (ptr != NULL) {             // FIXED: traverse until NULL
        printf("%d -> ", ptr->data);  // FIXED: print data, not address
        ptr = ptr->next;
    }
    printf("NULL\n");
}
