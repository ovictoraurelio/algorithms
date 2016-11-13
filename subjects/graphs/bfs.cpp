/***
	*
	* @author victoraurelio.com
	* @since 27/09/16
	*	
	BFS - Breadth-first Search.	
	[br]: Busca em largura.
***/
#include <bits/stdc++.h>
#define maxVertices 100

using namespace std;

int graph[maxVertices];
vector<int> adjs[maxVertices];

int visited[maxVertices];

void bfs(int started, int v){	
	list<int> bfsWay;
	bfsWay.push_back(started);
	visited[started] = 1;
	printf("%d\n", started);
	while(!bfsWay.empty()){
		for(int i=0; i<adjs[bfsWay.front()].size(); i++){
			if(visited[adjs[bfsWay.front()][i]] == 0){
				visited[adjs[bfsWay.front()][i]] = 1;
				bfsWay.push_back(adjs[bfsWay.front()][i]);
				printf("%d\n", adjs[bfsWay.front()][i]);
			}
		}
		bfsWay.pop_front();
	}
}
int read(){
	int nAdj, n,tmp;
	printf("\nType the number of vertices: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){		
		printf("\nType the number of vertices adjacent and all of adjacency vertices: ");
		scanf("%d", &nAdj);
		for(int j=0; j<nAdj; j++){
			scanf("%d", &tmp);
			adjs[i].push_back(tmp);
		}
	}
	return n;
}
int main(){
	int v;	
	v = read();	
	printf("\n :: Bfs Result :: \n");
	bfs(0, v);// 0 started bfs search on vertice 0, you can change anytime
	return 0;	
}
