#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char postfix[30],infix[30];
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

void push(char c)
{
//	printf("push\n");
	create_stack(c);
}

void push2(char c)
{
//	printf("push2\n");
	create_stack2(c);
}

char pop()
{
	char c=top->ch;
	top=top->link;
//	printf("pop\n");
	return c;
}

char pop2()
{
	char c=top2->ch2;
	top2=top2->link2;
//	printf("pop2\n");
	return c;
}

int isOperand(char c)
{
	return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
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

void PostfixToInfix()
{
	int i;
	
	for(i=0;i<strlen(postfix);i++)
	{
		if(isOperand(postfix[i])==1)
		{
//			printf("\nif operand\n");
			push(postfix[i]);
		}
			
		else
		{
			if(isOperand(top->ch)==1 && isOperand(top->link->ch)==1)
			{	
//				printf("in else..if\n");
				push2(pop());
				push2(postfix[i]);
				push2(pop());
				
				while(top2!=NULL)
				{
//					printf("in else..if..while\n");
					push(pop2());
				}
			}
			
			else
			{
				int opt=0,opn=0;
//				printf("in else..else\n");
				while(opt==opn)
				{
//					printf("in else..else..while1\n");
					
					if(isOperand(top->ch)==1)
						++opn;
					if(isOperand(top->link->ch)==0)
						++opt;
					if(opt==opn)
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
//					printf("in else..else..while2\n");
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
	
	rev_infix(infix);
	printf("\n\nequivalent infix expression is\n%s",infix);
/*	while(top!=NULL)
	{
		printf("%c",top->ch);
		top=top->link;
	}  */
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
	PostfixToInfix();
	return 0;
}
