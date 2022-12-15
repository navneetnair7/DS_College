#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
    struct node* next;
};

struct node *head=NULL;
struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
     
    return (node);
}

void display(struct node* node)
{
    if (node == NULL)
        return;
    else{
        display(node->left);
        printf("%c ", node->data);
        display(node->right);
    }
}
 
void push(struct node* x)
{
    if(head==NULL)
    head = x;
    else
    {
        (x)->next = head;
        head  = x;
    }
}

struct node* pop()
{
    struct node* p = head;
    head = head->next;
    return p;
}

int c = 0;
int height = 0;
int h = 0;
int count(struct node * x){
    if(head == NULL){
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
void countLeaf(struct node * x){
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

int main()
{
    // char s[] = {'E', 'B', 'C', 'A', '^', '*', '+', 'D', '-'};
    char s[] = {'A', 'B', 'C', '*', 'D', '*', '-'};
    int l = sizeof(s) / sizeof(s[0]);
    // printf("%d", l);
    struct node *x, *y, *z;
    for (int i = 0; i < l; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^') {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf("\nThe Inorder Traversal of Expression Tree: ");
    display(z);
    countLeaf(head);
    printf("\nNo. of nodes: %d", count(head) - leaf);
    printf("\nNo. of leaves: %d", leaf);
    printf("\nThe height of the tree is: %d", height / 2);
    return 0;
}