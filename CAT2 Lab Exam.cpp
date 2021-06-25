#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char word[10];
	int x,y;
	struct node *left, *right;
};

struct node *root=NULL;
int x_val=1;

struct node* create_node(char str[])
{
	int i;
	struct node *nn=(struct node*) malloc(sizeof(node));
	
	for(i=0;i<strlen(str);i++)
	{
		nn->word[i]=str[i];
	}
	nn->word[i]='\0';
	
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

struct node* bst(struct node *root, char str[])
{
	int i=0;
	
	if(root==NULL)
	{
		root=create_node(str);
	}
	
	else if((int) (str[i]) < (int) (root->word[i]))
	{
		root->left=bst(root->left,str);
	}
	
	else if((int) (str[i]) == (int) (root->word[i]))
	{
		while((int) (str[i]) == (int) (root->word[i]))
		{
			i++;
		}
		
		if((int) (str[i]) < (int) (root->word[i]))
		{
			root->left=bst(root->left,str);
		}
		
		else
		{
			root->right=bst(root->right,str);
		}
	}
	
	else
	{
		root->right=bst(root->right,str);
	}
	
	return root;
}

void compute_x(struct node *temp)
{
	temp->x=x_val++;
}

void get_x(struct node *temp)
{
	if(temp==NULL)
		return;
		
	get_x(temp->left);
	compute_x(temp);
	get_x(temp->right);
}

int depth(struct node *temp, char str[])
{
	int dep=0,i=0;
	
	if(temp->word==str)
		return dep;
		
	else if((int) (str[i]) < (int) (temp->word[i]))
	{
		dep=depth(temp->left,str);
	}
	
	else
	{
		dep=depth(temp->right,str);
	}
	
	return dep+1;
}

void get_y(struct node *temp)
{
	if(temp==NULL)
		return;
		
	get_y(temp->left);
	temp->y=depth(root,temp->word);
	get_y(temp->right);
}

void inorder(struct node *temp)
{
	if(temp==NULL)
		return;
		
	inorder(temp->left);
	printf("%s %d \t",temp->word,temp->x+temp->y);
	inorder(temp->right);
}

int main()
{
	int n,i;
	struct node *temp;
	char str[10];
	
	printf("enter number of word you wanna insert:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter word:");
		fflush(stdin);
		scanf("%s",str);
		root=bst(root,str);
	}
	
	get_x(root);
	get_y(root);
	inorder(root);
	
	return 0;
}
