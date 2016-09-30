/***
	*
	* @author victoraurelio.com
	* @since 27/09/16
	*
*/
#include <bits/stdc++.h>

using namespace std;


int n, operation, a;

int status[5];
int main(){
	while(scanf("%d", &n) != EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		while(n--){
			scanf("%d%d", &operation, &a);

			if(status[0] == 0 || status[1] == 0 || status[2] == 0)
				if(operation == 1){				
					s.push(a);
					q.push(a);
					pq.push(a);
				}else{
					if(s.top() != a)
						status[0] = 1;
					if(q.front() != a)
						status[1] = 1;
					if(pq.top() != a)
						status[2] = 1;
					s.pop();q.pop();pq.pop();
				}			
		}
		if(status[0] == 0 && status[1] == 1 && status[2] == 1)
				printf("stack\n");
			else if(status[0] == 1 && status[1] == 0 && status[2] == 1)
				printf("queue\n");
			else if(status[0] == 1 && status[1] == 1 && status[2] == 0)
				printf("priority queue\n");
			else if(status[0] == 0 || status[1] == 0 || status[2] == 0)
				printf("not sure\n");
			else printf("impossible\n");
		for(int i=0; i<5; i++)status[i]=0;
	};
	return 0;
}