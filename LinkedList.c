#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

int size=0;
struct node*head=NULL;
struct node *temp,*temp1,*newnode,*delnode;

void insertion();
void deletion();
void display();

int main(){
    int choice;
    while(1){
        printf("\n1 -> Insert\n2 -> Delete\n3 -> Display\n4 -> Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
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
void ins_beg(){
    newnode->next=head;
    head=newnode;
}
void ins_end(){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;

}
void ins_anypos(){
    int pos;
    printf("enter position to enter");
    scanf("%d",&pos);
    if(pos<1||pos>size+1){
        printf("INVALID POSITION\n");
        return;
    }
    if(pos==1){
        ins_beg();
        return;
    }
    if(pos==size+1){
        ins_end();
        return;
    }
    int i=2;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void insertion(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter elemnet");
    scanf("%d",&newnode->data);
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return ;
    }
    temp=head;

    if(size==0){
        ins_beg();
        size++;
        display(head);
        return;
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
        return ;
    }

    size++;
    display(head);
    return;

}
void dlt_beg(){
    temp=head;
    head=temp->next;
    free(temp);
}
void dlt_end(){
    while(temp!=NULL){
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=NULL;
    free(temp);
}
void dlt_anypos(){
    int pos;
    printf("enter position to enter");
    scanf("%d",&pos);
    if(pos<1||pos>size){
        printf("INVALID POSITION\n");
        return;
    }
    if(pos==1){
        dlt_beg();
        return;
    }
    if(pos==size){
        dlt_end();
        return;
    }
    int i=2;
    while(i>pos){
        temp=temp->next;
        i++;
    }
    delnode=temp->next;
    temp->next=delnode->next;
    free(temp);
}

void deletion(){
    if(size==0){
        printf("List is empty\n");
        return ;
    }
    
    temp=head;

    if(size==1){
        dlt_beg();
        size--;
        display(head);
        return;
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
        return ;
    }
    size--;
    display(head);
    return;

}

void display(struct node*ptr){
    if(ptr==NULL){
        printf("List is empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");

}
