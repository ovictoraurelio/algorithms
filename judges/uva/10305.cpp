#include <bits/stdc++.h>
 
using namespace std;
int n,m,a,b,f;
vector<int> adjs[110];
vector<int> order;
int canVisit[110];

void bfsTopSort(){
        queue<int> q;
        for(int i=1; i<=n; i++)
        	if(canVisit[i] == 0)
        		q.push(i);
 
        while(!q.empty()){
        	f = q.front();
            order.push_back(f);
            q.pop();
 
            for(int i=0; i<adjs[f].size(); i++){
                canVisit[adjs[f][i]]++;
                if(canVisit[adjs[f][i]] == 0)
                    q.push(adjs[f][i]);
            }
        }
}
 
int main(){
    while(scanf("%d%d", &n,&m) != EOF && !(n == 0 && m == 0)){        
        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            adjs[a].push_back(b);
            canVisit[b]--;
        }
 		bfsTopSort();
        printf("%d", order[0]);
        for(int i=1; i<order.size(); i++) printf(" %d", order[i]);
        printf("\n");

    	order.clear();
    	memset(canVisit, sizeof(int)*n+5, 0);
    	for(int i=1; i<=n; i++) adjs[i].clear();
    }
    return 0;
}