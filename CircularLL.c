#include <stdio.h>  
#include <stdlib.h>  

//Represent a node of singly linked list  
struct node{  
    int petrol;
    int dist;  
    int ind;
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *curr = NULL;
int ovr_ctr; 
   
void addNode(int p, int d) {  //inserting after rear
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->petrol = p;  
    newNode->dist=d;
    newNode->next = NULL;  
    if(head == NULL) {   
        head = newNode;
        head->next= head;  
        curr=head;
        curr->ind=ovr_ctr;
        ovr_ctr++;
    }  
    else {   
        curr->next=newNode;
        newNode->next=head;
        curr=newNode;
        curr->ind=ovr_ctr;
        ovr_ctr++;
    }  
}  
void addNode1(int p, int d, struct node *curr)
{	
	struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->petrol = p;  
    newNode->dist=d; 
    newNode->next=curr->next;
    curr->next=newNode;
}
void remove1(struct node *current)
{	if(current->next!=head)
	{	struct node *temp= current->next;
		current->next=temp->next;
		free(temp);
		}
}
		

int main()
{	
	int p, d;
	int n;
	printf("Enter the number of petrol pumps\n");
	scanf("%d", &n);
	printf("Enter the amount of petrol followed by distance between petrol pumps\n");
	for(int i=1;i<=n;i++)
	{	scanf("%d %d", &p, &d);
		addNode(p, d);
	}
	int flag=0, i=1, cap=0;
	struct node *current = head;
	for(i=1;i<=n;i++)
	{	cap=0;
		while(current->ind!=i)
			current=current->next;
		cap=cap+current->petrol;
		cap=cap-current->dist;
		//printf("%d %d \n", cap, i);
		if(cap<0)
			continue;
		current=current->next;
		while(current->ind!=i)
		{	cap=cap+current->petrol;
			cap=cap-current->dist;
			if(cap<0)
				break;
			current=current->next;
		}
		//printf("%d \n", cap);
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
