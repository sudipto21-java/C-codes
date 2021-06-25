#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack
{
	char ch;
	struct stack *link;
};

struct stack2
{
	char ch2;
	struct stack2 *link2;
};

char prefix[30], infix[30], postfix[30];
struct stack *top=NULL;
struct stack2 *top2=NULL;

void create_stack(char c)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	nn->ch=c;
	nn->link=top;
	top=nn;
}

void create_stack2(char c)
{
	struct stack2 *nn2=(struct stack2*) malloc(sizeof(struct stack2));
	nn2->ch2=c;
	nn2->link2=top2;
	top2=nn2;
}

char top_el()
{
	return top->ch;
}

int isEmpty()
{
	if(top==NULL)
		return 1;
}

void push(char c)
{
	create_stack(c);
}

void push2(char c)
{
	create_stack2(c);
}

char pop()
{
	char c=top->ch;
	top=top->link;
	return c;
}

char pop2()
{
	char c=top2->ch2;
	top2=top2->link2;
	return c;
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
		temp[j]=str[i];
	}
	temp[j]='\0';
	
	strcpy(infix,temp);
}

void rev_postfix(char str[])
{
	int i,j;
	
	for(i=strlen(str)-1, j=0; i>=0; i--,j++)
	{
		prefix[j]=str[i];
	}
	prefix[j]='\0';
}

void PostfixToPrefix()
{
//	postfix to infix
	int i,k;
	
	for(i=0;i<strlen(postfix);i++)
	{
		if(isOperand(postfix[i])==1)
			push(postfix[i]);
			
		else
		{
			if(isOperand(top->ch)==1 && isOperand(top->link->ch)==1)
			{
				push2(pop());
				push2(postfix[i]);
				push2(pop());
				
				while(top2!=NULL)
				{
					push(pop2());
				}
			}
			
			else
			{
				int opt=0,opn=0;
				while(opt==opn)
				{
					if(isOperand(top->ch)==1)
						++opn;
					if(isOperand(top->link->ch)==0)
						++opt;
					if(opn==opt)
					{
						push2(pop());
						push2(pop());
					}
					else
						break;
				}
				
				push2(pop());
				push2(postfix[i]);
				push2(pop());
				
				while(top2!=NULL)
				{
					push(pop2());
				}
			}
		}
	}
	
	for(i=0;top!=NULL;i++)
	{
		infix[i]=pop();
	}
	infix[i]='\0';
	
//	infix to prefix
	for(i=0,k=-1;i<strlen(infix);i++)
	{
		if(isOperand(infix[i])==1)
		{
			postfix[++k]=infix[i];
		}
		
		else
		{
			while(isEmpty()!=1 && prec(infix[i])<=prec(top_el()))
			{
				postfix[++k]=pop();
			}
			push(infix[i]);
		}
	}
		
	while(isEmpty()!=1)
	{
		postfix[++k]=pop();
	}
	
	postfix[++k]='\0';
	rev_postfix(postfix);
	printf("\n\nequivalent prefix expression is\n%s",prefix);
}

int main()
{
	int i,n;
	char c;
	printf("enter number of characters which your postfix expression conatins:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&c);
		postfix[i]=c;
	}
	postfix[i]='\0';
	
	printf("\npostfix expression is\n%s",postfix);
	PostfixToPrefix();
	return 0;
}
