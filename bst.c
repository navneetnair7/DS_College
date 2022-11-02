#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    struct Node * parent;
};
typedef struct Node node;
node * root = NULL;

void Insert(int val){
    node * new = (node *)malloc(sizeof(node));
    node * x = root;
    node * y = NULL;
    new -> data = val;
    while(x != NULL){
        y = x;
        if (new -> data < x -> data){
            x = x -> left;
        }
        else{
            x = x -> right;
        }
    }
   
    new -> parent = y;
    if (y == NULL){
        root = new;
    }
    else if(new -> data < y -> data){
        y -> left = new;
    }
    else{
        y -> right = new;
    }
}

void Display(node * new){
    if(new == NULL){
    return;
    }
    Display(new -> left);
    printf(" %d ", new -> data);
    Display(new -> right);
}

node * max(node * x){
    while(x -> right != NULL){
        x = x -> right;
    }
    return x;
}

node* min(node* root){
 while(root->left != NULL){
 root = root->left;
 }
 return root;
}

node * Predecessor(node * x){
    if (x -> left != NULL){
        return max(x -> left);
    }
    node * y = x -> parent;
    while(y != NULL && x == y -> left){
        x = y;
        y = y -> parent;
    }
    if(y == NULL){
        return 0;
    }
    return y;
}

node * Successor(node * x){
    if(root -> right != NULL){
        return min(x -> right);
    }
    node * y = x -> parent;
    while(y != NULL && x == y -> right){
        x = y;
        y = y -> parent;
    }
    if(y == NULL){
        return 0;
    }
    return y;
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
        count(x-> left);
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
int countLeaf(node * x){
    if(x -> right == NULL && x -> left == NULL){
        leaf ++;
    }
    if(x -> left != NULL){
        countLeaf(x-> left);
    }
    if(x -> right != NULL){
        countLeaf(x -> right);
    }
}

node * find(int x){
    node *p = root;
    while(p -> data != x){
        if(p -> data >= x){
            p = p -> left;
        }
        else{
            p = p -> right;
        }
    }
    return p;
}

void delete(node* x){
    if(x->left == NULL && x->right == NULL){
        x->parent->left = NULL;
        x->parent->right = NULL;
        free(x);
        return;
    }
    if(x->left == NULL){
        if(x->parent->left == x){
            x->parent->left = x->right;
            free(x);
        }
        else{
            x->parent->right = x->right;
            free(x);
        }   
    }
    if(x->right == NULL){
        if(x->parent->left == x){
            x->parent->left = x->left;
            free(x);
        }
        else{
            x->parent->right = x->left;
            free(x);
        }
    }
    
    node * temp = Predecessor(x);
    x->data = temp->data;
    delete(temp);
}

int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Display(root);
    printf("\nThe predecessor is: %d ", Predecessor(root));
    printf("\nThe successor is: %d ", Successor(root));
    printf("\nNumber of elements in the tree is: %d ", count(root));
    countLeaf(root);
    printf("\nThe number of leaves in the tree are: %d", leaf);
    printf("\nThe minimum value is: %d", min(root));
    printf("\nThe maximum value is: %d", max(root));
    printf("\nThe height of the tree is: %d\n", height);

    return 0;
}
