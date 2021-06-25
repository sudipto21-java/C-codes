#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct queue
{
	struct node q_node;
	struct queue *link;
};

struct queue *rear=NULL, *front=NULL;

void enqueue(struct node *root)
{
	struct queue *nn=(struct queue*) malloc(sizeof(struct queue));
	
	nn->q_node.data=root->data;
	nn->q_node.left=root->left;
	nn->q_node.right=root->right;
	nn->link=NULL;
	
	if(front==NULL && rear==NULL)
		front=rear=nn;
	else
	{
		rear->link=nn;
		rear=nn;
	}
}

struct queue* dequeue()
{
	struct queue *temp;
	
	if(front==rear)
	{
		printf("%d ",front->q_node.data);
		temp=front;
		front=rear=NULL;
	}
	else
	{
		printf("%d ",front->q_node.data);
		temp=front;
		front=front->link;
	}	
	
	return temp;
}

struct node* create_bst(int val)
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
		root=create_bst(data);
		return root;
	}
	
	if(root->data>data)
		root->left=bst(root->left,data);
	else
		root->right=bst(root->right,data);
		
	return root;
}

void level_order_traversal(struct node *root)
{
	struct queue *temp;
	
	if(root==NULL)
		return;
	
	enqueue(root);
	
	while(front!=NULL)
	{
		temp=dequeue();
		
		if(temp->q_node.left!=NULL)
			enqueue(temp->q_node.left);
			
		if(temp->q_node.right!=NULL)
			enqueue(temp->q_node.right);
	}
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
	
	level_order_traversal(root);
	return 0;
}
