#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * head = NULL;
struct Node * tail = NULL;


void insert(int val){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new -> data = val;
    if(head == NULL){
        head = new;
        tail = new;
        head -> next = head;
    }
    else{
        struct Node * temp = tail;
        new -> next = head;
        tail -> next = new;
        tail = new;
    }
}

void delete(){
    if(head == NULL){
        return;
    }
    struct Node * temp = head;
    while(temp -> next -> next != head){
        temp = temp -> next;
    }
    struct Node * temp2 = temp -> next;
    temp -> next = head;
    free(temp2);
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        struct Node * temp;
        temp = head;
        do{
            printf("Data: %d\n", temp -> data);
            temp = temp -> next;
        }
        while(temp -> next != head);
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    display();
    return 0;
}
