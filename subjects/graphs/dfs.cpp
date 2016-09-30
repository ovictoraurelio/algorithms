/***
	*
	* @author victoraurelio.com
	* @since 27/09/16
	*	
	DFS - Beepth-first Search.	
	[br]: Busca em profundidade.
***/
#include <bits/stdc++.h>
#define maxVertices 100

using namespace std;

typedef struct graph{	
	int id, value;
	list<int> adjs;
} Graph;

int visitedRecursively[maxVertices], visitedIterative[maxVertices];


void dfsRecursively(Graph graph[], int started, int v){	
	visitedRecursively[started] = 1;	
	if(graph[started].adjs.size() > 0){		
		for(list<int>::iterator adj = graph[started].adjs.begin(); adj != graph[started].adjs.end(); adj++){			
			if(visitedRecursively[*adj] == 0){				
				dfsRecursively(graph, *adj, v);			
			}
		}
	}
	printf("%d\n", graph[started].id);	
}

void dfsIterative(Graph graph[], int started, int v){
	int current;
	stack<int> sGraphs;
	sGraphs.push(started);	
	while(!sGraphs.empty()){
		current = sGraphs.top();		
		printf("%d\n", graph[current].id);
		sGraphs.pop();
		if(visitedIterative[current] == 0){			
			visitedIterative[current] = 1;
			for(list<int>::iterator adj = graph[current].adjs.begin(); adj != graph[current].adjs.end(); adj++){
				sGraphs.push(*adj);
			}
		}
		/*for(list<int>::iterator adj = graph[sGraphs.top()].adjs.begin(); adj != graph[sGraphs.top()].adjs.end(); ){			
			if(visitedIterative[sGraphs.top()] == 0){
				visitedIterative[sGraphs.top()] = 1;
				sGraphs.push((*adj));
				if(graph[sGraphs.top()].adjs.size() > 0){
					adj = graph[sGraphs.top()].adjs.begin();				
				}else{
					printf("%d\n", graph[sGraphs.top()].id);
					sGraphs.pop();
				}
			}else{
				adj++;
				if(adj == graph[sGraphs.top()].adjs.end()){
					printf("%d\n", graph[sGraphs.top()].id);
					sGraphs.pop();
					adj = graph[sGraphs.top()].adjs.begin();
				}
			}
		}*/	
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
	printf("\n :: Dfs Recursively Result :: \n");
	dfsRecursively(graphs, 0, v);// 0 started dfs search on vertice 0, you can change anytime
	printf("\n :: Dfs Iterative and Inverse Result :: \n");
	dfsIterative(graphs, 0, v);// 0 started dfs search on vertice 0, you can change anytime	
	return 0;	
}

