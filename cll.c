#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int size = 0;
struct node *head = NULL;
struct node *temp, *newnode, *delnode;

/* DISPLAY */

void display(struct node *ptr){
    if(ptr == NULL){
        printf("List is empty\n");
        return;
    }

    temp = ptr;
    printf("HEAD -> ");

    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("HEAD\n");
}

/* INSERT FUNCTIONS */

void ins_beg(){
    if(head == NULL){
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void ins_end(){
    temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

void ins_anypos(){
    int pos;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > size+1){
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        ins_beg();
        return;
    }

    if(pos == size+1){
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
            printf("Invalid choice\n");
            free(newnode);
            return;
    }

    size++;
    display(head);
}

/* DELETE FUNCTIONS */

void dlt_beg(){
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    delnode = head;
    head = head->next;
    temp->next = head;
    free(delnode);
}

void dlt_end(){
    temp = head;
    struct node *prev = NULL;

    while(temp->next != head){
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void dlt_anypos(){
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos < 1 || pos > size){
        printf("Invalid position\n");
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
    int i = 2;

    while(i < pos){
        temp = temp->next;
        i++;
    }

    delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}

void deletion(){
    if(size == 0){
        printf("List is empty\n");
        return;
    }

    if(size == 1){
        free(head);
        head = NULL;
        size--;
        display(head);
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
            printf("Invalid choice\n");
            return;
    }

    size--;
    display(head);
}

/* MAIN */

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
