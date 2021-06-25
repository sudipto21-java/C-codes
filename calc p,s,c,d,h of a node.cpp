#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *left;
	struct node *right;
};


struct node* create(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	nn->info=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}


struct node* insert(struct node *root, int data)
{
	if(root==NULL)
	{
		root=create(data);
		return root;
	}
	
	else if(root->info>=data)
	{
		root->left=insert(root->left,data);
	}
	
	else
		root->right=insert(root->right,data);
		
	return root;
}


void get_parent(struct node *address, int val, int parent)
{
	if(address==NULL)
		return;
		
	else if(address->info==val)
		printf("parent is:%d\n",parent);
		
	else
	{
		get_parent(address->left,val,address->info);
		get_parent(address->right,val,address->info);
	}
}


void get_children(struct node *root, int val)
{
	if(root==NULL)
		return;
		
	else if(root->info==val)
	{
		if(root->left==NULL && root->right==NULL)
		{
			printf("no childrens\n");
		}
		else if(root->left==NULL || root->right==NULL)
		{
			if(root->left==NULL)
				printf("no left child and right child is:%d\n",root->right->info);
			else
				printf("no right child and left child is:%d\n",root->left->info);
		}
		else
		{
			printf("childrens are %d, %d\n",root->left->info,root->right->info);
		}
	}
	else
	{
		get_children(root->left,val);
		get_children(root->right,val);
	}
}


void get_sibling(struct node *root, int val, struct node *parent)
{
	if(root==NULL)
		return;
		
	else if(root->info==val)
	{
		if(parent->left==NULL || parent->right==NULL || root==parent)
		{
			printf("no sibling\n");
			return;
		}
		
		else if(parent->left->info==val)
			printf("sibling is:%d\n",parent->right->info);
			
		else
			printf("sibling is:%d\n",parent->left->info);
	}
	else
	{
		get_sibling(root->left,val,root);
		get_sibling(root->right,val,root);
	}
}


int node_height(struct node *address)
{
	int lh,rh,h;
	
	if(address==NULL)
		return -1;
		
	lh=node_height(address->left);
	rh=node_height(address->right);
	
//	printf("lh:%d\n",lh);
//	printf("rh:%d\n",rh);
	
	if(lh>rh)
	{
		h=lh+1;
//		printf("h of if:%d\n",h);
	}
	
	else
	{
		h=rh+1;
//		printf("h of else:%d\n",h);
	}
	
//	printf("h of return:%d\n",h);
	
	return h;		
}


int get_node_height(struct node *root, int val)
{
	int height,lnh,rnh,nh;
	
	if(root==NULL)
	{
//		printf("control\n");
		return -1;
	}
		
	if(root->info==val)
	{
		height=node_height(root);
//		printf("height if gnh:%d",height);
	}
	
	else
	{
		lnh=get_node_height(root->left,val);
		rnh=get_node_height(root->right,val);
		
		if(lnh>rnh)
		{
			nh=lnh;
//			printf("nh of if:%d\n",nh);
			return nh;
		}
		else
		{
			nh=rnh;
//			printf("nh of else:%d\n",nh);
			return nh;
		}
	}
//	printf("final nh is:%d\n",nh);
	
	if(height>=nh)
		return height;
}


int depth(struct node *root, int val)
{
	int dep;
	if(val==root->info)
		return 0;
	if(val<=root->info)
		dep=depth(root->left,val);
	else
		dep=depth(root->right,val);
		
	return dep+1;
}


int main()
{
	struct node *root=NULL;
	int i,n,x,node,d,h;
	
	printf("enter number of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter element:");
		scanf("%d",&x);
		root=insert(root,x);
	}
	
	printf("enter value of node:");
	scanf("%d",&node);
	
	get_parent(root,node,-1);
	get_children(root,node);
	get_sibling(root,node,root);
	d=depth(root,node);
	printf("depth is:%d\n",d);
	h=get_node_height(root,node);
	printf("height is: %d",h);
	return 0;
}
