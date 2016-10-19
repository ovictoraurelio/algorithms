/****
    *
    *   @author victoraurelio.com
    *   @since 05/10/2016
    *
**/
#include <bits/stdc++.h>

using namespace std;

int nV, nE, c=0, a, b, visited[200];
vector<int> adjs[200];

int dfs(int v){	
	if(visited[v] == -1){	
		visited[v] = 0;
		for(int i=0; i<adjs[v].size(); i++){// vector fica mais simples que list		
			if(visited[adjs[v][i]] == -1){
				if(dfs(adjs[v][i]) == 1){	
					return 1;
				}
			}else if(visited[adjs[v][i]] == 1){	
				return 1;
			}
		}
		visited[v] = 1;
	}
	return 0;
}

int main(){
	
	while(scanf("%d%d", &nV, &nE) != EOF){		
		memset(visited, -1, 200);
		for(int i=0; i<nE; i++){
			scanf("%d%d", &a, &b);
			adjs[a].push_back(b);			
		}
		printf("%d %d\n", ++c, dfs(0));
		for(int i=0; i<nV; i++)adjs[i].clear();
	}		
	return 0;
}