#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

int size = 0;
struct node *head = NULL;
struct node *temp, *newnode, *delnode;

void insertion();
void deletion();
void display(struct node *ptr);

void ins_beg();
void ins_end();
void ins_anypos();

void dlt_beg();
void dlt_end();
void dlt_anypos();

int main(){
    int choice;
    while(1){
        printf("\n1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: insertion(); break;
            case 2: deletion(); break;
            case 3: display(head); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}

/* INSERT FUNCTIONS */

void ins_beg(){
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
}

void ins_end(){
    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void ins_anypos(){
    int pos;
    printf("Enter position to insert: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > size + 1){
        printf("INVALID POSITION\n");
        return;
    }

    if(pos == 1){
        ins_beg();
        return;
    }

    if(pos == size + 1){
        ins_end();
        return;
    }

    temp = head;
    int i = 2;

    while(i < pos){
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}

void insertion(){
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d",&newnode->data);

    if(size == 0){
        ins_beg();
        size++;
        display(head);
        return;
    }

    int type;
    printf("1 -> Insert at beginning\n2 -> Insert at end\n3 -> Insert at any position\n");
    printf("Enter choice: ");
    scanf("%d",&type);

    switch(type){
        case 1: ins_beg(); break;
        case 2: ins_end(); break;
        case 3: ins_anypos(); break;
        default:
            printf("Invalid type\n");
            free(newnode);
            return;
    }

    size++;
    display(head);
}

/* DELETE FUNCTIONS */

void dlt_beg(){
    delnode = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(delnode);
}

void dlt_end(){
    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void dlt_anypos(){
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > size){
        printf("INVALID POSITION\n");
        return;
    }

    if(pos == 1){
        dlt_beg();
        return;
    }

    if(pos == size){
        dlt_end();
        return;
    }

    temp = head;
    int i = 1;

    while(i < pos){
        temp = temp->next;
        i++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void deletion(){
    if(size == 0){
        printf("List is empty\n");
        return;
    }

    int type;
    printf("1 -> Delete from beginning\n2 -> Delete from end\n3 -> Delete from any position\n");
    printf("Enter choice: ");
    scanf("%d",&type);

    switch(type){
        case 1: dlt_beg(); break;
        case 2: dlt_end(); break;
        case 3: dlt_anypos(); break;
        default:
            printf("Invalid type\n");
            return;
    }

    size--;
    display(head);
}

/* DISPLAY */

void display(struct node *ptr){
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }

    printf("NULL <-> ");
    while(ptr != NULL){
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
