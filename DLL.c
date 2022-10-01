#include <stdio.h>
#include <stdlib.h>
struct Node{
 int data;
 struct Node *next;
 struct Node *prev;
};
typedef struct Node node;
node *head = NULL;
node *head2 = NULL;
void insert(int val){
 node *new = (node *)malloc(sizeof(node));
 if(head == NULL){
 new -> data = val;
 head = new;
 new -> next = NULL;
 new -> prev = NULL;
 }
 else{
 new -> data = val;
 node * temp = head;
 while(temp -> next != NULL){
 temp = temp -> next;
 }
 temp -> next = new;
 new -> prev = temp;
 new -> next = NULL;
 }
}
void insert2(int val){
 node *new = (node *)malloc(sizeof(node));
 if(head2 == NULL){
 new -> data = val;
 head2 = new;
 new -> next = NULL;
 new -> prev = NULL;
 }
 else{
 new -> data = val;
 node * temp = head2;
 while(temp -> next != NULL){
 temp = temp -> next;
 }
 temp -> next = new;
 new -> prev = temp;
 new -> next = NULL;
 }
}
void delete(){
 node *temp = head;
 if(head == NULL){
 printf("Empty");
 }
 else if(head -> next == NULL){
 free(head);
 head = NULL;
 }
 else{
 while(temp -> next -> next != NULL){
 temp = temp -> next;
 }
 node *temp2 = temp -> next;
 temp -> next = NULL;
 free(temp2);
 }
}
void display(){
 if(head == NULL){
 printf("Empty");
 }
 else{
 node * temp = head;
 while(temp -> next != NULL){
 printf("%d ", temp -> data);
 temp = temp -> next;
 } 
 printf("%d\n", temp -> data);
 }
}
void display2(){
 if(head2 == NULL){
 printf("Empty");
 }
 else{
 node * temp = head2;
 while(temp -> next != NULL){
 printf("%d ", temp -> data);
 temp = temp -> next;
 } 
 printf("%d\n", temp -> data);
 }
}
void sortInsert(int val){
 node *new = (node *)malloc(sizeof(node));
 new -> data = val;
 if(head == NULL){
 head = new;
 new -> next = NULL;
 new -> prev = NULL;
 }
 else if(head -> data > val){
 new -> next = head;
 head -> prev = NULL;
 head = new;
 }
 else{
 node * temp = head;
 while(temp -> next != NULL && temp -> next -> data <= val){
 temp = temp -> next;
 }
 new -> prev = temp;
 new -> next = temp -> next;
 temp -> next = new;
 }
}
void sortInsert2(int val){
 node *new = (node *)malloc(sizeof(node));
 new -> data = val;
 if(head2 == NULL){
 head2 = new;
 new -> next = NULL;
 new -> prev = NULL;
 }
 else if(head2 -> data > val){
 new -> next = head2;
 head2 -> prev = NULL;
 head2 = new;
 }
 else{
 node * temp = head2;
 while(temp -> next != NULL && temp -> next -> data <= val){
 temp = temp -> next;
 }
 new -> prev = temp;
 new -> next = temp -> next;
 temp -> next = new;
 }
}
void removeDup(){
 node * temp = head;
 while(temp -> next -> next != NULL){
 if(temp -> data == temp -> next -> data){
 node *temp2 = temp -> next;
 temp -> next = temp -> next -> next;
 temp -> next -> prev = temp;
 free(temp2);
 }
 else{
 temp = temp -> next;
 }
 }
 if(temp -> data == temp -> next-> data){
 node* temp2 = temp -> next;
 temp -> next = NULL;
 free(temp2);
 }
}
void removeDup2(){
 node * temp = head2;
 while(temp -> next -> next != NULL){
 if(temp -> data == temp -> next -> data){
 node *temp2 = temp -> next;
 temp -> next = temp -> next -> next;
 temp -> next -> prev = temp;
 free(temp2);
 }
 else{
 temp = temp -> next;
 }
 }
 if(temp -> data == temp -> next-> data){
 node* temp2 = temp -> next;
 temp -> next = NULL;
 free(temp2);
 }
}
void join(){
 node *temp = head2;
 while(temp -> next != NULL){
 sortInsert(temp -> data);
 temp = temp -> next;
 }
 while(temp -> prev != NULL){
 node *temp2 = temp;
 temp = temp -> prev;
 temp -> next = NULL;
 free(temp2);
 }
 free(temp);
}
int main()
{
 int n, m;
 printf("How many elements do you want in list1: ");
 scanf("%d", &n);
 for(int i = 0; i < n; i ++){
 printf("Enter the element: ");
 int p;
 scanf("%d", &p);
 sortInsert(p);
 }
 printf("How many elements do you want in list2: ");
 scanf("%d", &m);
 for(int i = 0; i < m; i ++){
 printf("Enter the element: ");
 int p;
 scanf("%d", &p);
 sortInsert2(p);
 }
 printf("List 1: \n");
 removeDup();
 display();
 printf("List 2: \n");
 removeDup2();
 display2();
 printf("Merged list- \n");
 join();
 display();
 return 0;
}
