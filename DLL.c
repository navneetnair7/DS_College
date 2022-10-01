#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data1;
    int data2;
    int ind;
    struct Node *next;
};

struct Node * head = NULL;
struct Node * tail = NULL;
int ovr_ctr;

void insert(int p, int d){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new -> data1 = p;
    new -> data2 = d;
    new -> next = NULL;
    if(head == NULL){
        head = new;
        head->next= head;  
        tail=head;
        tail->ind=ovr_ctr;
        ovr_ctr++;
    }
    else{
        tail->next=new;
        new->next=head;
        tail=new;
        tail->ind=ovr_ctr;
        ovr_ctr++;
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
            printf("Data: %d\n", temp -> data1);
            temp = temp -> next;
        }
        while(temp -> next != head);
    }
}

int main()
{
    printf("Enter the number of petrol pumps\n");
    int n, p, d;
	scanf("%d", &n);
	printf("Enter the amount of petrol followed by distance between petrol pumps\n");
	for(int i=1;i<=n;i++)
	{	scanf("%d %d", &p, &d);
		insert(p, d);
	}
	int flag=0, i=1, cap=0;
	struct Node *current = head;
	for(i=1;i<=n;i++)
	{	cap=0;
		while(current->ind!=i)
			current=current->next;
		cap=cap+current->data1;
		cap=cap-current->data2;
		if(cap<0)
			continue;
		current=current->next;
		while(current->ind!=i)
		{	cap=cap+current->data1;
			cap=cap-current->data2;
			if(cap<0)
				break;
			current=current->next;
		}
		if(cap>=0)
		{   if(flag==0)
				printf("The correct indices are: ");
			printf("%d ", i-1);
			flag=1;
			}	
		}
	if(flag==1)
		printf("\n");
	if(flag==0)
		printf("No possible solutions\n");
	return 0;
}
