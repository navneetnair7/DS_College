#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};


int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int height(struct Node * n){
    if(n == NULL){
        return 0;
    }
    return 1 + max(height(n -> left), height(n -> right));
}

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node -> data   = key;
    node -> left   = NULL;
    node -> right  = NULL;
    node -> height = 1;
    return(node);
}

struct Node * rightrotate(struct Node * x){
    struct Node * y = x -> left;
    struct Node * z = y -> right;
    y -> right = x;
    x -> left = z;
    x -> height = height(x);
    y -> height = height(y);

    return y;
}

struct Node * leftrotate(struct Node * x){
    struct Node * y = x -> right;
    struct Node * z = y -> left;
    y -> left = x;
    x -> right = z;
    x -> height = height(x);
    y -> height = height(y);

    return y;
}

int bal(struct Node * n){
    if (n == NULL)
        return 0;
    return height(n -> left) - height(n -> right);
}

struct Node * Insert(struct Node * node, int val){
    if (node == NULL)
        return newNode(val);
    if (val < node -> data)
        node -> left = Insert(node -> left, val);
    else if (val > node -> data)
        node -> right = Insert(node -> right, val);
    else
        return node;
    
    if(bal(node) > 1 && val < node -> left -> data){
        printf("Left-Left Rotation");
        return leftrotate(node);
    }
    else if (bal(node) < 1 && val > node -> right -> data){
        printf("Right-Right Rotation");
        return rightrotate(node);
    }
    else if(bal(node) > 1 && val > node -> left -> data){
        printf("Left-Right Rotation");
        node -> left = leftrotate(node -> left);
        return rightrotate(node);
    }
    else if(bal(node) < 1 && val < node -> right -> data){
        printf("Right-Left Rotation");
        node -> right = rightrotate(node -> right);
        return leftrotate(node);
    }
    return node;
}

void Display(struct Node * new){
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void main(){
    struct Node * root = NULL;
    Insert(root, 63);
    Insert(root, 19);
    Insert(root, 9);
    Display(root);
}