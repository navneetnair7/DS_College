//Program to convert infix to postfix expression version 2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Stack
{
	int top, count;
	unsigned size;
	char *array;
	char *output;
};	
char pop(struct Stack*);
struct Stack* cstack(int size)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->count=-1;
	stack->size=size;
	stack->array=(char*)malloc(size*sizeof(char));
	stack->output=(char*)malloc(size*sizeof(char));
	return stack;
}
int isFull(struct Stack* stack)
{
	return (stack->top==stack->size-1);
}
int isEmpty(struct Stack* stack)
{
	return (stack->top==-1);
}	
int isOperand(char x)
{
	if(isalnum(x))
	{
		return 1;
	}	
	else
	{
		return 0;
	}	
}	
char precedence(struct Stack* stack, char x)
{
	if(x=='-' || x=='+')
	{
		if(stack->array[stack->top]=='*' || stack->array[stack->top]=='/' || stack->array[stack->top]=='-' || stack->array[stack->top]=='+' || stack->array[stack->top]=='^')
		{
			stack->output[++stack->count]=pop(stack);
		}	
		return x;
	}	
	else
	{
		if(stack->array[stack->top]=='*' || stack->array[stack->top]=='/' || stack->array[stack->top]=='^')
		{
			while(stack->array[stack->top]=='*' || stack->array[stack->top]=='/' || stack->array[stack->top]=='^')
			{
				stack->output[++stack->count]=pop(stack);
			}	
			return x;
		}	
		else
		{
			return x;
		}	
	}	
}	
int peek(struct Stack* stack)
{
	if(isEmpty(stack))
	{
		printf("The Stack is empty\n");
	}	
	else
	{
		return (stack->array[stack->top]);
	}	
}	
void push(struct Stack* stack, char x)
{
	char temp='\0';
	if(isFull(stack))
	{
		printf("STACK IS FULL\n");
	}
	else
	{
		if(isOperand(x))
		{
			stack->output[++stack->count]=x;
			printf("#");
			for(int i=0; i<=stack->top; i++)
			{
				printf("%c", stack->array[i]);
			}	
			printf("\t\t");
			for(int i=0; i<=stack->count; i++)
			{
				printf("%c", stack->output[i]);
			}	
			printf("\n");
		}	
		else
		{
			if(x=='(' || x=='{' || x=='[' || x=='^')
			{
				stack->array[++stack->top]=x;
				printf("#");
				for(int i=0; i<=stack->top; i++)
				{
					printf("%c", stack->array[i]);
				}	
				printf("\t\t");
				for(int i=0; i<=stack->count; i++)
				{
					printf("%c", stack->output[i]);
				}	
				printf("\n");
			}	
			else if(x==')' || x=='}' || x==']')
			{
				printf("#");
				while(1)
				{
					if(stack->array[stack->top]=='(' || stack->array[stack->top]=='{' || stack->array[stack->top]=='[')
					{
						pop(stack);
						break;
					}	
					else
					{
						stack->output[++stack->count]=pop(stack);
					}	
				}
				for(int i=0; i<=stack->top; i++)
				{
					printf("%c", stack->array[i]);
				}	
				printf("\t\t");
				for(int i=0; i<=stack->count; i++)
				{
					printf("%c", stack->output[i]);
				}	
				printf("\n");
			}	
			else
			{
				char a=precedence(stack, x);
				stack->array[++stack->top]=a;
				printf("#");
				for(int i=0; i<=stack->top; i++)
				{
					printf("%c", stack->array[i]);
				}	
				printf("\t\t");
				for(int i=0; i<=stack->count; i++)
				{
					printf("%c", stack->output[i]);
				}	
				printf("\n");
			}	
		}	
	}
}	
char pop(struct Stack* stack)
{
	return (stack->array[stack->top--]);
}	
void main()
{
	int size, i=0;
	
	printf("Enter the size of stack\n");
	scanf("%d", &size);
	char str[size];
	printf("Enter the infix expression\n");
	scanf("%s", &str);
	struct Stack* stack=cstack(size);
	
	printf("Reading\t\tStack\t\tOutput\n");
	while(str[i]!='\0')
	{
		printf("%c\t\t", str[i]);
		push(stack, str[i]);
		i++;
	}
	i=0;
	
	printf("\t\t#\t\t");	
	while(!isEmpty(stack))
	{
		if(stack->array[stack->top]!='(' || stack->array[stack->top]!='{' || stack->array[stack->top]!='[')
		{
			stack->output[++stack->count]=pop(stack);
		}
		else
		{
			pop(stack);
		}	
	}
	for(int i=0; i<=stack->count; i++)
	{
		printf("%c", stack->output[i]);
	}	
	printf("\n");
	printf("\nThe program ends here");
}	