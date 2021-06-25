#include<stdio.h>
#include<stdlib.h>

struct node
{
	char info;
	struct node *left;
	struct node *right;
};


struct node* create_node(char val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->info=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}


struct node* insert_node(struct node *root, char data)
{
	if(root==NULL)
	{
		root=create_node(data);
		return root;
	}
	else if((int)(root->info)>=(int)(data))
	{
		root->left=insert_node(root->left,data);
	}
	else
	{
		root->right=insert_node(root->right,data);
	}
	return root;
}


void inorder(struct node *address)
{
	if(address==NULL)
		return;
	inorder(address->left);
	printf("%c ",address->info);
	inorder(address->right);
}


void preorder(struct node *address)
{
	if(address==NULL)
		return;
	printf("%c ",address->info);
	preorder(address->left);
	inorder(address->right);
}


void postorder(struct node *address)
{
	if(address==NULL)
		return;
	postorder(address->left);
	postorder(address->right);
	printf("%c ",address->info);
}


int main()
{
	struct node *root=NULL;
	int n,i;
	char c;
	
	printf("enter number of chars:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter char:");
		fflush(stdin);
		scanf("%c",&c,1);
		root=insert_node(root,c); 
	}
	
/* 	root=insert_node(root,'E');
 	root=insert_node(root,'F');
 	root=insert_node(root,'A');
 	root=insert_node(root,'C');
 	root=insert_node(root,'D');
 	root=insert_node(root,'B');  */
 	
 	printf("inorder traversal is\n");
	inorder(root);
	printf("\npreorder traversal is\n");
	preorder(root);
	printf("\npostorder traversal is\n");
	postorder(root);
	return 0;
}
