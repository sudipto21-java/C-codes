#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create_bst(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

struct node* bst(struct node *root, int data)
{
	if(root==NULL)
	{
		root=create_bst(data);
		return root;
	}
	
	if(root->data>data)
		root->left=bst(root->left,data);
	else
		root->right=bst(root->right,data);
		
	return root;
}

int height(struct node *root)
{
	int lh,rh,h;
	
	if(root==NULL)
		return -1;
		
	lh=height(root->left);
	rh=height(root->right);
	
	if(lh>rh)
		h=lh;
	else
		h=rh;
		
	return h+1;	
}

void print_levels(struct node *root, int level)
{
	if(root==NULL)
		return;
	
	if(level==0)
		printf("%d ",root->data);
	
	if(level>0)
	{
		print_levels(root->left,level-1);
		print_levels(root->right,level-1);
	}
}

void level_order(struct node *root)
{
	int i,h=height(root);
	
	for(i=0;i<=h;i++)
	{
		print_levels(root,i);
	}
}

int main()
{
	struct node *root=NULL;
	int x,i,n;
	printf("enter total number of nodes\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("enter node value:");
		scanf("%d",&x);
		root=bst(root,x);
	}
	
	printf("level order traversal result is\n");
	level_order(root);
	return 0;
}
