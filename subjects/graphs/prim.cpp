/***
	*
	* @author victoraurelio.com
	* @since 14/11/16
	*	
	Prim: minimum-spanning-tree algorithm (just connected graphs)
***/
#include <bits/stdc++.h>

using namespace std;

#define WHITE -1
#define GREY 0

#define maxV 100

int v[maxV], n;
typedef pair<int,int> edge;//first is weight and second is vertice
vector<edge> edges[maxV];
edge p[maxV],tmp;
int mst[maxV];
int color[maxV];

void primMST(int source){
	edge u,v;
	priority_queue<edge, vector<edge>, greater<edge> > q;	
	for(int i=0; i<n; i++){
		 p[i].first = INT_MAX;
		 p[i].second = color[i] = WHITE;
	}
	
	q.push(make_pair(0, source));
	p[source].first = 0;

	while(!q.empty()){		
		v = q.top();		
		q.pop();	
		for(int i=0; i<edges[v.second].size(); i++){			
			u = edges[v.second][i];							
			if(color[u.second] == WHITE){
					color[u.second] = GREY;
					mst[u.second] = v.second;					
					p[u.second].first = u.first;
					p[u.second].second = v.second;								
					q.push(u);
			}else if(p[u.second].first > u.first){				
				mst[u.second] = v.second;				
				p[u.second].first = u.first;
				p[u.second].second = v.second;								
				q.push(u);
			}
		}	
	}
}


void read(){
	int nv;
	edge e;
	printf("\nType the number of vertices: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){		
		printf("\nType the number of vertices adjacent and all of adjacencies vertices (adj, weight): ");
		scanf("%d", &nv);
		for(int j=0; j<nv; j++){
			scanf("%d%d", &e.second, &e.first);			
			edges[i].push_back(e);
		}
	}	
}
void showMST(int source){
	for(int i=0; i<n; i++){		
		printf("%d - %d\n", mst[i], i);
	}
}
int main(){
	int source=3;
	read();
	primMST(source);	
	showMST(source);
	return 0;
}
