#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node* maketree(){
    Node *p;
    int info;

    printf("Enter info [-1 for NULL] : ");
    scanf("%d", &info);
    if(info==-1)
        return NULL;
    
    p=(Node*)malloc(sizeof(Node));
    p->info=info;
    printf("Enter the left child of %d\n", info);
    p->left=maketree();
    printf("Enter the right child of %d\n", info);
    p->right=maketree();

    return p;
}

void preorder(Node *p){
    if(p!=NULL){
        printf("%d-> ", p->info);
        preorder(p->left);
        preorder(p->right);
    }   
}

void postorder(Node *p){
    if(p!=NULL){
        preorder(p->left);
        preorder(p->right);
        printf("%d-> ", p->info);
    }
}

void inorder(Node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d=> ", p->info);
        inorder(p->right);
    }
}

int main(){
    Node *root;
    root=maketree();

    printf("Preorder :-\n");
    preorder(root);
    printf("\n\nPostorder :-\n");
    postorder(root);
    printf("\n\nInorder :-\n");
    inorder(root);

    return 0;
}