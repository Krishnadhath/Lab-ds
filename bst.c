#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node*right,*left;
};

struct node*root=NULL;
struct node*newnode,*temp;

struct node*createnode(int key){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node*findmin(struct node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}


struct node*delete(struct node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->key){
        root->left=delete(root->left,key);
    }
    else if(key>root->key){
        root->right=delete(root->right,key);
    }
    else{
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
        temp=findmin(root->right);
        root->key=temp->key;
        root->right=delete(root->right,temp->key);

    }
    return root;
}

struct node*insert(struct node*root,int key){
    if(root==NULL){
        return createnode(key);
    }
    if(key<root->key){
        root->left=insert(root->left,key);
    }
     else if(key>root->key){
        root->right=insert(root->right,key);
    }
    return root;

}
struct node*search(struct node*root,int key)
{
if(root==NULL||key==root->key){
    return root;
}
if(key<root->key){
    return search(root->left,key);
}
else if(key>root->key){
    return search(root->right,key);
}
};
void inorder(struct node*root){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ,",root->key);
    inorder(root->right);
}
void preorder(struct node*root){
    if(root==NULL)
    return;
    printf("%d ,",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ,",root->key);
}




void main(){
    while(1){
        int choice,key,ch;
        printf("enter choice 1 for insertion 2 for deletion 3 for search");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter key to enter");
            scanf("%d",&key);
            root=insert(root,key);
            break;
            case 2:
            printf("enter key to delete");
            scanf("%d",&key);
            root=delete(root,key);
            break;
            case 3:
            printf("enter key to search");
            scanf("%d",&key);
            if(search(root,key)!=NULL){
                printf("element found");
            }
            else{
                printf("element not found");
            }
            break;
            case 4:
            printf("enter 1 for inorder 2 for preorder 3 for post order");
            scanf("%d",&ch);
            switch(ch){
                case 1:
                inorder(root);
                break;
                case 2:
                preorder(root);
                break;
                case 3:
                postorder(root);
                break;

            }







        }
    
    }
}