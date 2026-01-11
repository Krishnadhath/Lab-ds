#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

int size=0;
struct node*head=NULL;
struct node*temp,*newnode,*delnode;

void display(struct node*ptr){
    if(ptr==NULL){
        printf("List empty\n");
        return;
    }
    while(ptr!=NULL){
        printf("%d<->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");

}

void ins_beg(){
    newnode->next=head;
    newnode->prev==NULL;
    if(head!=NULL){
        head->prev=newnode;
    }
    head=newnode;
}
void ins_end(){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
}
void ins_anypos(){
    int pos;
    printf("enter position to enter");
    scanf("%d",&pos);
    if(pos<1||pos>size+1){
        printf("invalid position");
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
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    
}
void insertion(){
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("allocation failed");
        return;
    }
    printf("enter element to enter:");
    scanf("%d",&newnode->data);

    temp=head;
    
    if(size==0){
        ins_beg();
        size++;
        display(head);
        return;
    }

    int type;
    printf("1.Insert at beginning\n 2.at end \n 3.at any pos\n");
    printf("enter choice");
    scanf("%d",&type);
    switch(type){
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
            printf("invalid");
            free(newnode);
            return;
        
    }
    size++;
    display(head);
    return;
}

void dlt_beg(){
    temp=head;
    head=temp->next;
    
    if(head!=NULL){
        head->prev=NULL;
    }
    free(temp);
}

void dlt_end(){
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->prev!=NULL){
        temp->prev->next=NULL;
    }
    else
        head=NULL;
    
    free(temp);
}
void dlt_anypos(){
    int pos;
    printf("enter position to delete");
    scanf("%d",&pos);
    if(pos<1||pos>size){
        printf("invalid position");
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
    int i=1;
    while(pos>i){
        temp=temp->next;
        i++;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

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
    return;
}
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
    

