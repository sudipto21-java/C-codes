#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *left;
	struct node *right;
};

struct node* newnode(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->info=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}

struct node* insert(struct node *address, int data)
{
	if(address==NULL)
	{
		address=newnode(data);
		return address;
	}
	else if(data<=address->info)
	{
		address->left=insert(address->left, data);
	}
	else 
	{
		address->right=insert(address->right, data);
	}
//	printf("nodes inserted");
	return address;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->info);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->info);
}

int main()
{
	struct node *root=NULL;
	int x,i,n;
	printf("enter number of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	printf("Inorder traversal is\n");
	inorder(root);
	printf("\nPreorder traversal is\n");
	preorder(root);
	printf("\nPostorder traversal is\n");
	postorder(root);
	return 0;
}
