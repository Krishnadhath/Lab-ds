#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node*left,*right;
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

struct node*insert(struct node*root,int key){
    if(root==NULL){
        return createnode(key);
    }

    if(root->key<key){
        root->right=insert(root->right,key);
    }
    
    else if(root->key>key){
        root->left=insert(root->left,key);
    }

    return root;
}

struct node*delete(struct node*root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->key>key){
        root->left=delete(root->left,key);
    }
    else if(root->key<key){
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
struct node*search(struct node*root,int key){
    if(root==NULL||root->key==key){
        return root;
    }

    if(root->key>key){
        return search(root->left,key);
    }
    else if(root->key<key){
        return search(root->right,key);
    }
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ,",root->key);
    inorder(root->right);
}
void preorder(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d ,",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ,",root->key);
}
int main(){
    while(1){
    int key;
    int choice,ch;
    printf("\n1.Insert\n 2.Delete\n 3.Search\n 4.Traversal\n 5.Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("enter element insert:");
        scanf("%d",&key);
        root=insert(root,key);
        break;
        case 2:
        printf("enter element to delete:");
        scanf("%d",&key);
        root=delete(root,key);
        break;
        case 3:
        printf("enter element to search:");
        scanf("%d",&key);
        if(search(root,key)!=NULL){
            printf("Elemenet found");
        }
        else{
            printf("element not found");
        }
        break;
        case 4:
        printf("1.Inorder\n 2.Preorder\n 3.Postorder\n");
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
        break;
        case 5:
        printf("exiting program");
        return 0;
        default:
        printf("invalid entry");

    }
   
}
}

