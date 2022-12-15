#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int Top;
    char *A;
};

int StackTop(struct stack* S)
{
    return S -> A[S -> Top];
}

int isEmpty(struct stack *ptr)
{
    if(ptr -> Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr -> Top == ptr -> size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack* ptr, char element)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow: Element cannot be pushed into the stack\n");
    }
    else
    {
        ptr -> Top++;
        ptr -> A[ptr -> Top] = element;
    }
}

char Pop(struct stack* ptr)
{
    char element;
    if(isEmpty(ptr))
    {
        printf("Stack Underflow: Stack is empty. No element can be popped\n");
        return -1;
    }
    else
    {
        element = ptr -> A[ptr -> Top];
        ptr -> Top--;
        return element;
    }
}

int Precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch == '+' || ch <= '-' || ch == '*' || ch == '/')
    {
         return 1;
    }
    else
    {
        return 0;
    }
}

char* Convert(char* Infix)
{
    struct stack* S = (struct stack*)malloc(sizeof(struct stack));
    S -> Top = -1;
    printf("Enter the size of the stack");
    scanf("%d", &(S -> size));
    S -> A = (char*)malloc(S -> size * sizeof(char));

    char * Postfix = (char *) malloc((strlen(Infix) + 1) * sizeof(char));
    
    int i = 0;
    int j = 0;
    while(Infix[i] != '\0')
    {
        if(!isOperator(Infix[i]))
        {
            Postfix[j] = Infix[i];
            j++;
            i++; 
        }
        else
        {
            if(Precedence(Infix[i]) >= Precedence(StackTop(S)))
            {
                Push(S, Infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = Pop(S);
                j++;
            }
        }
    }

    while(!isEmpty(S))
    {
        Postfix[j] = Pop(S);
        j++;
    }
    Postfix[j] = '\0';
    return Postfix;
}

int main()
{
    char * Infix;
    printf("Enter input Infix\n");
    scanf("%s", Infix);

    printf("The required Postfix is: %s\n", Convert(Infix));
    return 0;
}