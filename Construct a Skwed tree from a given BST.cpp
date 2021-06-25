#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *root=NULL;
struct node *rootRSkw=NULL;
struct node *rootLSkw=NULL;
int arr[100],n=0;

struct node* CreateNode(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=data;
	nn->left=nn->right=NULL;
	
	return nn;
}

struct node* Bst(struct node *root, int k)
{
	if(root==NULL)
	{
		root=CreateNode(k);
		return root;
	}
	
	if(root->data>=k)
		root->left=Bst(root->left,k);
	else
		root->right=Bst(root->right,k);
	
	return root;
}

void ConstructRightSkewedTree(struct node *temp)
{
	if(temp==NULL)
		return;
	
	ConstructRightSkewedTree(temp->left);
	rootRSkw=Bst(rootRSkw,temp->data);
	ConstructRightSkewedTree(temp->right);
}

void preorder(struct node *temp)
{
	if(temp==NULL)
		return;
	
	printf("%d\t",temp->data);
	preorder(temp->left);
	preorder(temp->right);
}

void getArrayForLeftSkwTree(int k)
{
	arr[n++]=k;
}

void StoreInArr(struct node *temp)
{
	if(temp==NULL)
		return;
	
	StoreInArr(temp->left);
	getArrayForLeftSkwTree(temp->data);
	StoreInArr(temp->right);
}

void ConstructLeftSkewedTree()
{
	for(int i=n-1;i>=0;i--)
	{
		rootLSkw=Bst(rootLSkw,arr[i]);
	}
}

int main()
{	
	int n,i,x,k;
	
	printf("enter count of nodes:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root=Bst(root,x);
	}
	
	printf("Preorder traversal of original Binary search tree\n");
	preorder(root);
	
	ConstructRightSkewedTree(root);
	printf("\nPreorder traversal of Right Skewed Binary search tree\n");
	preorder(rootRSkw);
	
	StoreInArr(root);
	ConstructLeftSkewedTree();
	
	printf("\nPreorder traversal of Left Skewed Binary search tree\n");
	preorder(rootLSkw);
	
	return 0;
}
