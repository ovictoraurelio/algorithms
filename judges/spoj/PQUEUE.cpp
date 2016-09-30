/***
	*
	* @author victoraurelio.com
	* @since 24/09/16
	*
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> print;
print tmp;
int n,i,j,qtd,pos, weight, ind;
int main(){
	scanf("%d", &n);
	for(i=0; i<n; i++){
		
		priority_queue<print> p;
		queue<print> s;

		scanf("%d%d", &qtd, &pos);
		for(j=0; j<qtd; j++){			
			scanf("%d", &tmp.first);
			tmp.second = j;
			p.push(tmp);
			s.push(tmp);
		}
		for(j=0; (!s.empty()); ){
			//always remove on front of queue
			weight = s.front().first;
			ind = s.front().second;
			s.pop();
			if(weight != p.top().first){
				//if not to print, send to end and not up time...
				tmp.first = weight; tmp.second = ind;				
				s.push(tmp);
			}else{
				j++;
				p.pop();				
				if(ind == pos){
					printf("%d\n", j);
					break;
				}									
			}			
		}		
	}
	return 0;
}