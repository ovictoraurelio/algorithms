	#include <bits/stdc++.h>

using namespace std;
/***
	Implementar com BFS ou DFS.
	Basicamente é uma forma de ordenar todos os vertices atraves das arestas, sem colisões de dependencias.	
***/

int i,j,k,l,visited[100], ordened[100],ind=0, n,bN, nAdj, tmp;
list<int> adjs[100];
void orderInBfs(){
	visited[0] = 1;
	for(i=0; i<100; i++){		
		for(list<int>::iterator vertice=adjs[i].begin(); vertice != adjs[i].end(); vertice++){
			if(visited[*vertice] == 1){//Já visitado.
						
			}else{
				ordened[ind] = ind++;
				visited[*vertice] = 1;
			}
		}
	}
}	
int main(){
	printf("Digite a quantidade de vertices: ");
	scanf("%d", &n);
	for(l=0; l<n; l++){
		printf("Digite a quantidade de adjacencias desse vertice e depois quem são tais vertices adjacentes: ");
		scanf("%d", &nAdj);
		for(k=0; k<nAdj; k++){
			scanf("%d", &tmp);
			adjs[k].push_back(tmp);
		}
	}
	orderInBfs();
	printf("\nOrdened: ");
	for(i=0; i<n; i++)printf("%d ", ordened[i]);
	return 0;
}
