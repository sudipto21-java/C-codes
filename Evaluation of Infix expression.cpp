#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stack
{
	char ch;
	struct stack *link;
};

struct stack2
{
	int digit;
	struct stack2 *link2;
};

struct stack *top=NULL;
struct stack2 *top2=NULL;
char infix[30];
int result;

void create_stack(char c)
{
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	nn->ch=c;
	nn->link=top;
	top=nn;
}

void create_stack2(int d)
{
	struct stack2 *nn=(struct stack2*) malloc(sizeof(struct stack2));
	nn->digit=d;
	nn->link2=top2;
	top2=nn;
}

char pop()
{
	char c=top->ch;
	top=top->link;
	return c;
}

int pop2()
{
	int d=top2->digit;
	top2=top2->link2;
	return d;
}

void push(char c)
{
	create_stack(c);
}

void push2(int d)
{
	create_stack2(d-48);
}

void push_result(int d)
{
	create_stack2(d);
}

int isEmpty()
{
	return (top==NULL);
}

int isDigit(char c)
{
	return (c>='0' && c<='9');
}

char peek()
{
	return top->ch;
}

int prec(char c)
{
	switch(c)
	{
		case '+':
		case '-':
			return 1;
				
		case '*':
		case '/':
		case '%':
			return 2;
			
		case '^':
			return 3;
	}
	return -1;
}

int calc(int d1, int d2, char c)
{
	switch(c)
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

int evaluate()
{
	int i,d1,d2;
	char op;
	
	for(i=0;i<strlen(infix);i++)
	{
		if(isDigit(infix[i]))
			push2(infix[i]);
			
		else if(infix[i]=='(')
			push(infix[i]);
		
		else if(infix[i]==')')
		{
			while(isEmpty()!=1 && peek()!='(')
			{
				d1=pop2();
				d2=pop2();
				op=pop();
				result=calc(d1,d2,op);
				push_result(result);
			}
			
			if(isEmpty()!=1 && peek()!='(')
				return -1;
			else
				pop();
		}
		
		else
		{
			while(isEmpty()!=1 && prec(infix[i])<=prec(peek()))
			{
				d1=pop2();
				d2=pop2();
				op=pop();
				result=calc(d1,d2,op);
				push_result(result);
			}
			push(infix[i]);
		}
	}
	
	while(top!=NULL)
	{
		d1=pop2();
		d2=pop2();
		op=pop();
		result=calc(d1,d2,op);
		push_result(result);
	}
	
	printf("\nresult is:%d",result);
}

int main()
{
	int i,n;
	char c;
	printf("enter how many characters does your infix expression contains:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a character:");
		scanf(" %c",&c);
		infix[i]=c;
	}
	infix[i]='\0';
	
	printf("\ninfix expression is\n%s",infix);
	evaluate();
	return 0;
}
