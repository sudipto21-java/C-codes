#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* create_node(int data)
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
		root=create_node(data);
		return root;
	}
		
	if(root->data>data)
		root->left=bst(root->left,data);
	else
		root->right=bst(root->right,data);
		
	return root;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

int count_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
		
	int left_nodes=count_nodes(root->left);
	int right_nodes=count_nodes(root->right);
	
	return left_nodes+right_nodes+1;
}

int main()
{
	struct node *root=NULL;
	int x,i;
	char d='y';
	while(d=='y' || d=='Y')
	{
		printf("enter node value:");
		scanf("%d",&x);
		root=bst(root,x);
		printf("do you wanna continue inserting nodes\npress Y for yes or N for no\n");
		scanf(" %c",&d);
	}
	printf("Inorder traversal of binary search tree is\n");
	inorder(root);
	printf("\ntotal number of nodes are:%d",count_nodes(root));
	return 0;
}
