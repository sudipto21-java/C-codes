#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *left;
	struct node *right;
};

struct node* create(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->info=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

struct node* insert(struct node *root, int data)
{
	if(root==NULL)
	{
		root=create(data);
		return root;
	}
	else if(root->info>=data)
	{
		root->left=insert(root->left,data);
	}
	else
		root->right=insert(root->right,data);
		
	return root;
}

int height(struct node *root)
{
	int lh,rh,h;
	
	if(root==NULL)
	{
		return -1;
	}
	
	lh=height(root->left);
	rh=height(root->right);
	
	if(lh>rh)
		h=lh+1;
	else
		h=rh+1;
		
	return h;
	
}

int main()
{
	struct node *root=NULL;
	int i,n,x,maxh;
	printf("enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	
	maxh=height(root);
	printf("height is:%d",maxh);
	return 0;
}
