#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int reg;
	int marks;
	char gen;
	char name[10];
	struct node *left;
	struct node *right;
};

struct stack
{
	int reg;
	int marks;
	char gen;
	char name[10];
	struct stack *next;
};

struct stack *head;

struct node* bst_node(int r, char g, int m, char nm[10])
{
//	printf("get_node\n");
	int i=0;
	
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->left=NULL;
	nn->right=NULL;
	nn->marks=m;
	nn->gen=g;
	nn->reg=r;
	
	while(i<strlen(nm))
	{
//		printf("while get_node\n");
		nn->name[i]=nm[i];
		++i;
	}
	
	return nn;
}

struct stack* push(int m, char g, int r, char nm[10])
{
//	printf("push\n");
	int i=0;
	
	struct stack *nn=(struct stack*) malloc(sizeof(struct stack));
	
	nn->marks=m;
	nn->reg=r;
	nn->gen=g;
	
	while(i<strlen(nm))
	{
//		printf("push while\n");
		nn->name[i]=nm[i];
		++i;
	}
	
	nn->next=head;
	head=nn;
	
	return head;
}

void print_stack(struct stack *ad)
{
	if(ad==NULL)
		printf("stack is empty");
	else
	{
		while(ad!=NULL)
		{
			printf("\n%d \n%s \n%c \n%d\n\n", ad->reg, ad->name, ad->gen, ad->marks);
			ad=ad->next;
		}
	}
}

struct node* bst(struct node *root, int reg, char name[10], char gen, int mrk)
{
	int i=0,j;
	
	if(root==NULL)
	{
//		printf("bst if\n");
		root=bst_node(reg,gen,mrk,name);
		return root;
	}
		
	else if((int)(name[i]) < (int)(root->name[i]))
	{
//		printf("bst else-if\n");
		root->left=bst(root->left,reg,name,gen,mrk);
	}
	
	else if((int)(name[i]) == (int)(root->name[i]))
	{	
		for(j=i+1;(name[j] == root->name[j]) || (name[j] != root->name[j]);j++)
		{
			if((int)(name[j]) < (int)(root->name[j]))
			{
				root->left=bst(root->left,reg,name,gen,mrk);
				break;
			}
		
			else if((int)(name[j]) > (int)(root->name[j]))
			{
				root->right=bst(root->right,reg,name,gen,mrk);
				break;
			}
		}
	}
	
	else
	{
//		printf("bst else\n");
		root->right=bst(root->right,reg,name,gen,mrk);
	}
	
	return root;
}

struct node* MinValNode(struct node *node)
{
//	printf("min val node\n");
	struct node *min=node;
	
	while(min->left!=NULL)
	{
		min=min->left;
	}
	
	return min;
}

struct node* delete_node(struct node *root)
{
//	printf("delete_node\n");
		
	if(root->left==NULL && root->right==NULL)
	{
		free(root);
		root=NULL;
	}
		
	if(root->left==NULL)
	{
//		printf("delete_node if\n");
		struct node *temp=root->right;
		free(root);
		return temp;
	}
		
	else if(root->right==NULL)
	{
//		printf("delete_node else_if\n");
		struct node *temp=root->left;
		free(root);
		return temp;	
	}
		
	else
	{
//		printf("delete_node else\n");
		struct node *temp=MinValNode(root->right);
		int k=0;
//		printf("got min value in temp and temp is:%s\n",temp->name);
	
		while(k<strlen(root->name))
		{
//			printf("delete_node while\n");
			root->name[k]=temp->name[k];
			++k;
		}
		root->name[k]='\0';
		
		root->gen=temp->gen;
		root->marks=temp->marks;
		root->reg=temp->reg;
		
/*		printf("after while\n");
		printf("else in delete_node and root is:%s\n",root->name);
		printf("else in delete_node and right of root is:%s\n",root->right->name); */
		
		//root->right=delete_node(root->right);
		root->right->left=NULL;
//		printf("else in delete_node and right of root is:%s\n",root->right->name);
	}
	return root;
}

struct node* find_nodes_for_del(struct node *root)
{
	if(root==NULL)
		return root;
	
	root->left=find_nodes_for_del(root->left);
	root->right=find_nodes_for_del(root->right);
	
	if(root->marks<30)
	{
		return delete_node(root);
	}
	
	return root;
}

void print_details(struct node *root)
{	
	if(root==NULL)
		return;
	
//	printf("inorder\n");
	print_details(root->left);
	
	if(root->gen=='m')
	{
		printf("\n%d \n%s \n%c \n%d\n\n", root->reg, root->name, root->gen, root->marks);
	}
	else
	{
		head=push(root->marks,root->gen,root->reg,root->name);
	}
	
	print_details(root->right);
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
		
	inorder(root->left);
	printf("%s\n",root->name);
	inorder(root->right);
}

int main()
{
	struct node *root=NULL;
	head=NULL;
	
	int reg,marks,n,i;
	char gen;
	char name[10];
	
	printf("enter number of students:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter registration number:");
		scanf("%d",&reg);
		printf("enter name:");
		scanf(" %s",name);
		printf("enter gender:");
		scanf(" %c",&gen);
		printf("enter total marks:");
		scanf("%d",&marks);	
		root=bst(root,reg,name,gen,marks);
	}
	
	print_details(root);
	print_stack(head);
	root=find_nodes_for_del(root);
	printf("after deletion\n\n");
	inorder(root);
	
	return 0;
}
