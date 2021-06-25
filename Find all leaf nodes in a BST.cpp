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

void find_all_leaf_nodes(struct node *root)
{
	if(root==NULL)
		return;
		
	if(root->left==NULL && root->right==NULL)
		printf("%d ",root->data);
		
	find_all_leaf_nodes(root->left);
	find_all_leaf_nodes(root->right);
}

int count_leaf_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
	
	if(root->left==NULL && root->right==NULL)
		return 1;
	
	return count_leaf_nodes(root->left)+count_leaf_nodes(root->right);
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
	printf("leafs in binary search tree are\n");
	find_all_leaf_nodes(root);
	printf("\ntotal leaf nodes in binary search tree is:%d",count_leaf_nodes(root));
	return 0;
}
