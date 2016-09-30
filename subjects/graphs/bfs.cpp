/***
	*
	* @author victoraurelio.com
	* @since 27/09/16
	*
	Busca em profundidade.
	DFS - Depth-first Search.	
*/
#include <bits/stdc++.h>
#define maxVertices 100
using namespace std;

typedef struct graph{	
	int id, value;
	list<int> adjs;
} Graph;

int visited[maxVertices];

void bfs(Graph graph[], int started, int v){	
	list<int> bfsWay;		
	bfsWay.push_back(graph[started].id);
	visited[started] = 1;
	printf("%d\n", graph[bfsWay.front()].id);
	while(!bfsWay.empty()){
		for(list<int>::iterator adj = graph[bfsWay.front()].adjs.begin(); adj != graph[bfsWay.front()].adjs.end();  adj++){			
			if(visited[(*adj)] == 0){
				visited[(*adj)] = 1;
				bfsWay.push_back(*adj);
				printf("%d\n", *adj);
			}
		}
		bfsWay.pop_front();
	}
}
int read(Graph graphs[]){
	int nAdj, n,tmp;
	printf("\nType the number of vertices: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){		
		graphs[i].id = i; 
		printf("\nType the number of vertices adjacent and all of adjacency vertices: ");
		scanf("%d", &nAdj);
		for(int j=0; j<nAdj; j++){
			scanf("%d", &tmp);
			graphs[i].adjs.push_back(tmp);
		}
	}
	return n;
}
int main(){
	int v;
	Graph graphs[maxVertices];
	v = read(graphs);	
	printf("\n :: Bfs Result :: \n");
	bfs(graphs, 0, v);// 0 started bfs search on vertice 0, you can change anytime
	return 0;	
}
