#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct list
{
	struct node *head;
};

struct graph
{
	int ver;
	struct list *array;
};

struct graph* create_graph(int v)
{
	struct graph *ptr=(struct graph*) malloc(sizeof(struct graph));
	
	ptr->ver=v;
	ptr->array=(struct list*) malloc(v*sizeof(struct list));
	
	int i;
	for(i=0;i<v;i++)
	{
		ptr->array[i].head=NULL;
	}
	return ptr;
}

struct node* create_node(int data)
{
	struct node *nn=(struct node*) malloc(sizeof(struct node));
	
	nn->data=data;
	nn->next=NULL;
	
	return nn;
}

void add_edge(struct graph *graph, int s, int d)
{
	struct node *temp=create_node(d);
	temp->next=graph->array[s].head;	// insertion at begining 
	graph->array[s].head=temp;
}

void print_graph(struct graph *graph)
{
	int v;
	for(v=0;v<graph->ver;v++)
	{
		struct node *temp= graph->array[v].head;
		printf("\nadjacency list of vertex %d\n head",v);
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int v=5;
	struct graph *graph=create_graph(v);
	add_edge(graph,0,1);
	add_edge(graph,0,4);
	add_edge(graph,1,2);
	add_edge(graph,1,3);
	add_edge(graph,1,4);
	add_edge(graph,2,3);
	add_edge(graph,3,4);
	
	print_graph(graph);
	
	return 0;
}
