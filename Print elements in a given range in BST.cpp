#include<stdio.h>
#include<stdlib.h>

int ub,lb;

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newnode(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->data=data;
	nn->left=nn->right=NULL;
	return nn;
}

struct node* bst(struct node *root, int data)
{
	if(root==NULL)
	{
		root=newnode(data);
		return root;
	}
	
	if(root->data>data)
		root->left=bst(root->left,data);
	else
		root->right=bst(root->right,data);
		
	return root;
}

void find_elements(struct node *root, int lb, int ub)
{
	if(root==NULL)
		return;
	
	find_elements(root->left,lb,ub);
	if(root->data<ub && root->data>lb)
		printf("%d\t",root->data);
	find_elements(root->right,lb,ub);
}

int main()
{
	struct node *root=NULL;
	int x,i,n;
	printf("enter number of nodes in BST:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a value for node:");
		scanf("%d",&x);
		root=bst(root,x);
	}
	printf("enter lower bound and upper bound of the range\n");
	scanf("%d%d",&lb,&ub);
	printf("elements between %d to %d\n",lb,ub);
	find_elements(root,lb,ub);
}
