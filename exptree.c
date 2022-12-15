#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};
typedef struct Node node;

node * root = NULL;
node * insert(int ele[], int i, int n){
    // printf("Hello ");
    if(i < n){
        node * new = (node *)malloc(sizeof(node));
        if(root == NULL){
            root = new;
        }
        else{
            new -> data = ele[i];
            new -> left = insert(ele, 2 * i + 1, n);
            new -> right = insert(ele, 2 * i + 2, n);
        }
    }
    return root;
}

int c = 0;
int height = 0;
int h = 0;
int count(node * x){
    if(root == NULL){
        h = 0;
        return 0;
    }
    c ++;
    if(x -> left != NULL){
        h ++;
        count(x -> left);
    }
    if(x -> right != NULL){
        h ++;
        count(x -> right);
    }
    if(h > height){
        height = h;
    }
    return c;
}

int leaf = 0;
void countLeaf(node * x){
    if(x -> right == NULL && x -> left == NULL){
        leaf++;
    }
    if(x -> left != NULL){
        countLeaf(x -> left);
    }
    if(x -> right != NULL){
        countLeaf(x -> right);
    }
}

void display(node * root){
    if(root != NULL){
        display(root -> left);
        printf("%d", root -> data);
        display(root -> right);
    }
}

void main(){
    int n;
    scanf("%d", &n);
    int ele[n];
    for(int i = 0; i < n; i ++){
        scanf("%d", &ele[i]);
    }
    node * root2 = insert(ele, 0, n);
    display(root);
    printf("No. of nodes: ", count(root));
    printf("No. of leaves: ", count(root));
    printf("The height of the tree is: ", height);
}