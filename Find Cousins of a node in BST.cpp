#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *root=NULL;

struct node* CreateNode(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=data;
	nn->left=nn->right=NULL;
	
	return nn;
}

struct node* Bst(struct node* root, int data)
{
	if(root==NULL)
	{
		root=CreateNode(data);
		return root;
	}
	
	if(root->data>data)
		root->left=Bst(root->left,data);
	else
		root->right=Bst(root->right,data);
	
	return root;
}

struct node* getFather(struct node *temp, int k, struct node *parent)
{
	if(temp->data==k)
		return parent;
	
	if(temp->data>k)
		getFather(temp->left,k,temp);
	else
		getFather(temp->right,k,temp);
}

struct node* getSibling(struct node *temp, struct node *self, struct node *dad)
{
	if(temp==NULL)
	{
//		printf("if\n%d",root);
		return NULL;
	}
		
	else if(temp==self)
	{
		printf("else-if\n");
		if(dad->left==NULL || dad->right==NULL || dad==root)
		{
		//	printf("else-if_if\n");
			return NULL;
		}
			
		else if(dad->left==self)
		{
		//	printf("else-if_else\n");
			return dad->right;	
		}
		
		else
			return dad->left;
				
	}
	
	else
	{
//		printf("else\n");
		getSibling(temp->left,self,root);
		getSibling(temp->right,self,root);
	}
}

void getCousins(struct node *temp, int k)
{
	struct node *dad, *uncle;
	
	dad=getFather(temp,k,NULL);
	printf("\n%d",dad->data);
	uncle=getSibling(temp,dad,NULL);
	printf("\n%d",uncle->data);
	
	if(dad==NULL || uncle==NULL)
		printf("%d does not have any cousins",k);
		
	else if(uncle->left!=NULL && uncle->right!=NULL)
		printf("%d and %d are cousins of %d",uncle->left->data,uncle->right->data,k);
		
	else if(uncle->left==NULL)
		printf("%d is cousin of %d",uncle->right->data,k);
		
	else
		printf("%d is cousin of %d",uncle->left->data,k);
}

void inorder(struct node *temp)
{
	if(temp==NULL)
		return;
	
	inorder(temp->left);
	printf("%d\t",temp->data);
	inorder(temp->right);
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
	
	printf("enter a node for which you wanna get cousins:");
	scanf("%d",&k);
	getCousins(root,k);
	
//	inorder(root);
	
	return 0;
}
