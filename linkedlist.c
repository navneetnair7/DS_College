#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node* next;

};

struct node* insert(struct node* head, int c, int e)
{
    struct node* temp;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    
    new->coeff=c;
    new->expo=e;
    new->next=NULL;
    
    if(head == NULL || e > head->expo)
    {
        
        new->next=head;
        head=new;
        
    }
    else
    {
        
        temp=head;
        while(temp->next!=NULL && temp->next->expo > e)
        {
            temp=temp->next;
            
        }
        struct node * temp2;
        temp2 = temp -> next;
        temp->next=new;
        new -> next = temp2;
        
    }
    
    return head;
    
}

struct node* create(struct node* head)
{
    int n, i, coeff, expo;
    
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        printf("\nEnter the coefficient for term %d:", i+1);
        scanf("%d", &coeff);
        
        printf("Enter the exponent for term %d:", i+1);
        scanf("%d", &expo);
        
        head = insert(head, coeff, expo);
    }
    
    return head;
    
}
  
  
    
void print(struct node* head)
{
    
    if(head == NULL)
    {
        printf("No polynomial.");
        
    }
    else
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            printf("(%dx^%d)", temp->coeff, temp->expo);
            temp=temp->next;
            if(temp!=NULL)
            {
                
                printf(" + ");
                
            }
            else
            {
                
                printf("\n");
                
            }
        
        }
    
    }

}
    
void add(struct node* head1, struct node* head2)
{
    
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expo);
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        
        }
        else if(ptr1->expo > ptr2->expo)
        {
            
            head3=insert(head3, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
            
            
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=insert(head3, ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
            
        }
        
    }
    while(ptr1!=NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1=ptr1->next;
        
    }
    while(ptr2!=NULL)
    {
        head3=insert(head3, ptr2->coeff, ptr2->expo);
        ptr2=ptr2->next;
        
    }
    int c=1;
    printf("\nAdded polynomial is:");
    print(head3);
    
    
}


void sub(struct node* head1, struct node* head2)
{
    
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff-ptr2->coeff, ptr1->expo);
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        
        }
        else if(ptr1->expo > ptr2->expo)
        {
            
            head3=insert(head3, ptr1->coeff, ptr1->expo);
            ptr1=ptr1->next;
            
            
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=insert(head3, -ptr2->coeff, ptr2->expo);
            ptr2=ptr2->next;
            
        }
        
    }
    while(ptr1!=NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1=ptr1->next;
        
    }
    while(ptr2!=NULL)
    {
        head3=insert(head3, ptr2->coeff, ptr2->expo);
        ptr2=ptr2->next;
        
    }
    
    printf("\nSubtracted polynomial is:");
    print(head3);
    
    
}


int main()
{
    
    struct node* head1=NULL;
    struct node* head2=NULL;
    printf("\nEnter the first polynomial\n ");
    head1=create(head1);
    
    printf("\nEnter the second polynomial\n ");
    head2=create(head2);
    
    printf("\nThe first polynomial:");
    print(head1);
    
    printf("\nThe second polynomial:");
    print(head2);
    
    add(head1, head2);
    sub(head1, head2);
    
    return 0;
    
}