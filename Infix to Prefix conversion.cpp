#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	char ch;
	struct stack *link;
};

char infix[30];
char prefix[30];
struct stack *top=NULL;

void create_stack(char c)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	nn->ch=c;
	nn->link=top;
	top=nn;
}

char pop()
{
	char ch=top->ch;
	top=top->link;
	return ch;
}

void push(char c)
{
	create_stack(c);
}

char peek()
{
	return top->ch;
}

int isEmpty()
{
	if(top==NULL)
		return 1;
}

char top_el()
{
	return top->ch;
}

int isOperand(char c)
{
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

int prec(char ch)
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

void rev_infix(char str[])
{
	int i,j;
	char temp[30];
	
	for(i=strlen(str)-1, j=0; i>=0; i--,j++)
	{
		if(str[i]=='(')
			temp[j]=')';
			
		else if(str[i]==')')
			temp[j]='(';
			
		else
			temp[j]=str[i];
	}
	temp[j]='\0';
	
	strcpy(infix,temp);
}

void rev_prefix(char str[])
{
	int i,j;
	char temp[30];
	
	for(i=strlen(str)-1, j=0; i>=0; i--,j++)
	{
		temp[j]=str[i];
	}
	temp[j]='\0';
	
	strcpy(prefix,temp);
}

int InfixToPrefix()
{
	int i,k;
	
	rev_infix(infix);
	
	for(i=0,k=-1;i<strlen(infix);i++)
	{
		if(isOperand(infix[i])==1)
		{
			prefix[++k]=infix[i];
		}
			
		else if(infix[i]=='(')
			push(infix[i]);
		
		else if(infix[i]==')')
		{
			while(isEmpty()!=1 && top_el()!='(')
			{
				prefix[++k]=pop();
			}
				
			if(isEmpty()!=1 && top_el()!='(')    //invalid expression
				return -1;
			else
				pop();
		}
		
		else
		{
			while(isEmpty()!=1 && prec(infix[i])<=prec(top_el()))
			{
				prefix[++k]=pop();
			}
			push(infix[i]);
		}
	}
		
	while(isEmpty()!=1)
	{
		prefix[++k]=pop();
	}
	
	prefix[++k]='\0';
	rev_prefix(prefix);
	printf("\n\nequivalent prefix expression is\n%s",prefix);
}

int main()
{
	int i,n;
	char c;
	printf("enter how many characters does your infix expression have:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter character:");
		scanf(" %c",&c);
		infix[i]=c;
	}
	infix[i]='\0';
	
	printf("\nInfix expression is\n%s",infix);
	InfixToPrefix();
	return 0;
}
