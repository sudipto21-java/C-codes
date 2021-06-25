#include<stdio.h>

int v,e;

void DFS_traversal(int graph[][v]), int visited[], int sv)
{
	
}

int main()
{
	int i,j,v1,v2,sv;
	
	printf("enter number of vertices and edges in a graph\n");
	scanf("%d%d",&v,&e);
	
	int visited[v];
	int graph[v][v];
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			graph[i][j]=0;
		}
	}
	
	for(i=0;i<v;i++)
	{
		visited[i]=0;
	}
	
	for(i=0;i<e;i++)
	{
		printf("enter two adjacent vertices\n");
		scanf("%d%d",&v1,&v2);
		graph[v1][v2]=1;
		graph[v2][v1]=1;
	}
	
	printf("enter source vertex from where you wanna start traversing graph:");
	scanf("%d",&sv);
	
	DFS_traversal(graph, visited, sv);
	
	return 0;
}
