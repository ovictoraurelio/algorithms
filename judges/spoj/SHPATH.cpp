#include <bits/stdc++.h>

using namespace std;

int s,n,nE,nS, dist[10001], vE;
typedef pair<int,int> path;//first is the weight, and second is index of vertice
path tmp, a;
priority_queue<path, vector<path>, greater<path> > bestPaths;
vector<path> adjs[10001];
bool visited[10001];

void init(){
	memset(visited, false, (n+1)*sizeof(bool));
	for(int i=1; i<=n; i++) dist[i] = INT_MAX;	
	while(!bestPaths.empty())bestPaths.pop();	
}

int dijkstra(int source, int to){	
	dist[source] = 0;
	bestPaths.push(make_pair(0, source));

	while(!bestPaths.empty()){

		tmp = bestPaths.top();
		bestPaths.pop();
		
		if(!visited[tmp.second]){			
			visited[tmp.second] = true;
			for(int i=0; i<adjs[tmp.second].size(); i++){				
				a = adjs[tmp.second][i];
				if(!visited[a.second] && (a.first + dist[tmp.second]) < dist[a.second]){
					dist[a.second] = a.first + dist[tmp.second];
					bestPaths.push(make_pair(dist[a.second], a.second));
				}
			}			
		}
		if(tmp.second == to) break;

	}

}

int main(){
	scanf("%d",&s);	
	while(s--){
		map<string,int> names;
		char name[11], sourceName[11], toName[11];
		scanf("%d", &n);	
		for(int j=1; j<=n; j++){				
				if(!adjs[j].empty())adjs[j].clear();
			scanf(" %s", name);
			names.insert(make_pair(name, j));
			scanf("%d", &nE);			
			while(nE--){
				scanf("%d%d", &tmp.second,&tmp.first);
				adjs[j].push_back(tmp);
			}
		}
		scanf("%d", &nS);
		while(nS--){
			init();
			scanf(" %s%s", sourceName,toName);			
			vE = names[toName];			
			dijkstra(names[sourceName], vE);
			printf("%d\n", dist[vE]);
		}		
	}
	return 0;
}
