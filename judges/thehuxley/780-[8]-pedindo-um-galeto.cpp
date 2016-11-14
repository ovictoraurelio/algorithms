/***
	*
	*	team JPV
	*
***/
#include <bits/stdc++.h>

using namespace std;

char c;
int a,d,exist[100000];
vector<int> order;

int main(){
	while(scanf("%c", &c) != EOF){
		switch(c){
			case 'a': 
				scanf("%d", &d);
				exist[d] = 1;				
				order.push_back(d);				
			break;			
			case 'r':
				scanf("%d", &d);
				if(exist[d] == 0){
					printf("falha\n");
				}else{
					exist[d] = 0;
					for(int i=0; i<order.size(); i++){
						if(order[i] == d)
							order.erase(order.begin() + i);
					}
					printf("removido\n");					
				}
			break;
			case 'p':
				if(order.size() == 0) printf("vazia");
				else{
					printf("%d",order[0]);
					for(int i=1; i<order.size(); i++)
						printf(" %d",order[i]);
				}
				printf("\n");
			break;
		}
	}
	return 0;
}