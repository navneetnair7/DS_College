#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node * next;
};
typedef struct Node node;

node * initInsert(int data){
    node * new = (node *)malloc(sizeof(node));
    new -> val = data;
    new -> next = NULL;
    return new;
}

int modulo(int n){
    return n % 13;
}

void display(node * x){
    while(x -> next != NULL){
        printf("%d -> ", x -> val);
        x = x -> next;
    }
    printf("%d \n", x -> val);
}

void main(){
    int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    node * t[13];
    for(int i = 0; i < 13; i ++){
        t[i] = initInsert(c[i]);
    }
    int ins[] = {18, 41, 22, 44, 59, 32, 31, 73};
    for(int i = 0; i < sizeof(ins) / sizeof(ins[0]); i ++){
        int m = modulo(ins[i]);
        node * x = t[m];
        while(x -> next != NULL){
            x = x -> next;
        }
        x -> next = initInsert(ins[i]);
    }
    for(int i = 0; i < 13; i ++){
        display(t[i]);
    }
}