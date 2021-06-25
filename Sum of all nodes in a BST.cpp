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

int sum_of_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
		
	int left_sum=sum_of_nodes(root->left);
	int right_sum=sum_of_nodes(root->right);
	
	return root->data+left_sum+right_sum;
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
	printf("Inorder traversal of binary search tree is\n");
	inorder(root);
	printf("\nsum of all nodes is:%d",sum_of_nodes(root));
	return 0;
}
