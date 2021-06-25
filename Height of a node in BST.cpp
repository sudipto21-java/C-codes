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
		return -1;
	
	lh=height(root->left);
	rh=height(root->right);
	
	if(lh>rh)
		h=lh+1;
	else
		h=rh+1;
		
	return h;
}

int get_node_height(struct node *root, int key)
{
/*	if(root==NULL)
		return;*/
	int h;
	if(root->info==key)
	{
		h=height(root);
	}
	else
	{
		get_node_height(root->left,key);
		get_node_height(root->right,key);
	}
	return h;
}

int main()
{
	struct node *root=NULL;
	int i,n,x,key;
	
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	
	printf("enter a node for which you wanna compute height:");
	scanf("%d",&key);
	
	printf("height of %d is:%d",key,get_node_height(root,key));
	return 0;
}
