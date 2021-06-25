#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* create_node(int val)
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
		root=create_node(data);
		return root;
	}
	
	if(root->data>data)
		root->left=bst(root->left,data);
	else
		root->right=bst(root->right,data);
		
	return root;
}

void print_all_nodes_without_sibling(struct node *root)
{
	if(root==NULL)
		return;
	
	if(root->left==NULL && root->right!=NULL)
		printf("%d ",root->right->data);
		
	if(root->right==NULL && root->left!=NULL)
		printf("%d ",root->left->data);	
	
	print_all_nodes_without_sibling(root->left);
	print_all_nodes_without_sibling(root->right);
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
	
	print_all_nodes_without_sibling(root);
	return 0;
}
