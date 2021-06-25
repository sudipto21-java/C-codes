#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *root1=NULL;
struct node *root2=NULL;

struct node* CreateNode(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=data;
	nn->left=nn->right=NULL;
	
	return nn;
}

struct node* Bst(struct node *temp, int k)
{
	if(temp==NULL)
	{
		temp=CreateNode(k);
		return temp;
	}
	
	if(temp->data>=k)
		temp->left=Bst(temp->left,k);
	else
		temp->right=Bst(temp->right,k);
	
	return temp;
}

void Check(struct node *temp, int k, int value)
{
	if(temp==NULL)
		return;
	
	Check(temp->left,k,value);
	
	if((temp->data+k)>value)
		printf("%d %d\n",k,temp->data);
		
	Check(temp->right,k,value);
}

void getNodeFromBST1(struct node *temp, int value)
{
	if(temp==NULL)
		return;
	
	getNodeFromBST1(temp->left,value);
	Check(root2,temp->data,value);
	getNodeFromBST1(temp->right,value);
}

int main()
{
	int n1,n2,i,x,k;
	
	printf("enter count of nodes for first BST:");
	scanf("%d",&n1);
	
	for(i=0;i<n1;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root1=Bst(root1,x);
	}
	
	printf("enter count of nodes for second BST:");
	scanf("%d",&n2);
	
	for(i=0;i<n2;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root2=Bst(root2,x);
	}

	printf("enter a value:");
	scanf("%d",&k);
	
	printf("\nPair of nodes having sum more then %d is\n",k);
	getNodeFromBST1(root1,k);
	
	return 0;
}
