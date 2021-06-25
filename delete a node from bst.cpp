#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *left;
	struct node *right;
};

struct node* get_node(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->left=NULL;
	nn->right=NULL;
	nn->value=data;
	
	return nn;
}

struct node* bst(struct node *root, int data)
{
	if(root==NULL)
	{
		root=get_node(data);
		return root;	
	}
	
	if(root->value>data)
	{
		root->left=bst(root->left,data);
	}
	
	else
	{
		root->right=bst(root->right,data);
	}
	
	return root;
}

struct node* min_val_node(struct node *ad)
{
	struct node *temp=ad;
	
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	
	return temp;
}

struct node* delete_node(struct node *root, int key)
{
	if(root==NULL)
		return root;
		
	if(key<root->value)
	{
		root->left=delete_node(root->left,key);
	}
	
	else if(key>root->value)
	{
		root->right=delete_node(root->right,key);
	}
	
	else
	{
		if(root->left==NULL && root->right==NULL)
			return NULL;
		
		else if(root->left==NULL)
			return root->right;
		
		else if(root->right==NULL)
			return root->left;	
	
		struct node *min=min_val_node(root->right);
		root->value=min->value;
		root->right=delete_node(root->right,min->value);
	}
	
	return root;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	printf("%d ",root->value);
	inorder(root->right);
}

int main()
{
	struct node *root=NULL;
	int i,n,x,k;
	printf("enter total number of nodes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter a number:");
		scanf("%d",&x);
		root=bst(root,x);
	}
	
	inorder(root);
	printf("\nenter a number for deletion:");
	scanf("%d",&k);
	
	root=delete_node(root,k);
	
	printf("\nafter deletion\n");
	
	inorder(root);
	return 0;
}
