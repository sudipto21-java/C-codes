#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	char ch;
	struct stack *link;
};

struct stack *top=NULL;
char postfix[30];
char infix[30];

void create_stack(char c)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	
	nn->ch=c;
	nn->link=top;
	top=nn;
}

struct stack* isEmpty()
{
	if(top==NULL)
		return top;
}

char top_el()
{
	return top->ch;
}

int isOperand(char ch)
{
	return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

void push(char ch)
{
	create_stack(ch);
}

char pop()
{
	char c=top->ch;
	top=top->link;
	return c;
}

int precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
			
		case '^':
			return 3;
	}
	return -1;
}

int InfixToPostfix()
{
	int i,k=-1;
	
	for(i=0;i<strlen(infix);i++)
	{
		if(isOperand(infix[i])==1)
			postfix[++k]=infix[i];
			
		else if(infix[i]=='(')
			push(infix[i]);
			
		else if(infix[i]==')')
		{
			while(isEmpty()!=NULL && top_el()!='(')
			{
				postfix[++k]=pop();
			}
			
			if(isEmpty()!=NULL && top_el()!='(')    //invalid scenario
				return -1;
			else
				pop();
		}
		
		else
		{
			while(isEmpty()!=NULL && precedence(infix[i])<=precedence(top_el()))
			{
				postfix[++k]=pop();
			}
			push(infix[i]);
		}
	}
	
	while(isEmpty()!=NULL)
	{
		postfix[++k]=pop();
	}
	
	postfix[++k]='\0';
	printf("\n\nequivalent postfix expression\n%s",postfix);
}

int main()
{
	int n,i;
	char c;
	printf("enter total number of character which your infix expression contains:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&c);
		infix[i]=c;
	}
	infix[i]='\0';
	
	printf("\ninfix expression\n%s",infix);
	
	InfixToPostfix();
	
	return 0;
}

