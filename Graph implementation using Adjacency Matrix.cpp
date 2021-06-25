#include<stdio.h>

int main()
{
	int v,e,i,v1,v2,j;

	printf("enter number of vertices and edges in graph\n");
	scanf("%d%d",&v,&e);
	
	int graph[v][v];
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			graph[i][j]=0;
		}
	}
	
	for(i=0;i<e;i++)
	{
		printf("enter two adjecency vertices\n");
		scanf("%d%d",&v1,&v2);
		graph[v1][v2]=1;
		graph[v2][v1]=1;	// undirected graph
	}
	
	printf("adjacency matrix of graph is\n");
	
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}
