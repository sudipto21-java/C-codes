#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stack
{
	int digit;
	struct stack *link;
};

struct stack *top=NULL;
char postfix[30];
int result;

void create_stack(int d)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	nn->digit=d;
	nn->link=top;
	top=nn;
}

int isDigit(char c)
{
	return (c>='0' && c<='9');
}

int pop()
{
	int d=top->digit;
	top=top->link;
	return d;
}

void push(int d)
{
	create_stack(d-48);
}

void push_result(int d)
{
	create_stack(d);
}

int calc(int d1, int d2, char op)
{
	switch(op)
	{
		case '+':
			return d1+d2;
			
		case '-':
			return d2-d1;
			
		case '*':
			return d1*d2;
		
		case '/':
			return d2/d1;
		
		case '%':
			return d2%d1;
		
		case '^':
			return pow(d2,d1);
	}
	return -1;
}

void evaluate()
{
	int i,d1,d2;
	char op;
	
	for(i=0;i<strlen(postfix);i++)
	{
		if(isDigit(postfix[i])==1)
			push(postfix[i]);
			
		else
		{
			d1=pop();
			d2=pop();
			result=calc(d1,d2,postfix[i]);
			push_result(result);
		}
	}
	
	printf("\n\nresult is:%d",result);
}

int main()
{
	int i,n;
	char c;
	printf("enter how many characters does your postfix expression contains:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&c);
		postfix[i]=c;
	}
	postfix[i]='\0';
	
	printf("\npostfix expression is\n%s",postfix);
	evaluate();
	return 0;
}
