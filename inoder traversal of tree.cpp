#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *left;
	struct node *right;
} *root;

struct node* create_node(int val)
{
	struct node *nn=(struct node*) malloc(sizeof(node));
	nn->info=val;
	nn->left=NULL;
	nn->right=NULL;
	
	return nn;
}

void inorder(struct node *root)
{
	struct node *current, *pre; 
  
    if (root == NULL) 
        return; 
  
    current = root; 
    while (current != NULL)
	 { 
  
        if (current->left == NULL) 
		{ 
            printf("%d ", current->info); 
            current = current->right; 
        } 
        else 
		{ 
  
            /* Find the inorder predecessor of current */
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder  
               predecessor */
            if (pre->right == NULL) 
			{ 
                pre->right = current; 
                current = current->left; 
            } 
  
            /* Revert the changes made in the 'if' part to restore  
               the original tree i.e., fix the right child 
               of predecessor */
            else 
			{ 
                pre->right = NULL; 
                printf("%d ", current->info); 
                current = current->right; 
            }
        }
    } 
}

int main()
{
	root=create_node(30);
	root->left=create_node(20);
	root->right=create_node(40);
	root->left->left=create_node(15);
	root->left->right=create_node(25);
	inorder(root);
	return 0;
}
