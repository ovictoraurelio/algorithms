/***
	*
	* @author victoraurelio.com
	* @since 13/05
	*
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
	int **matriz1, **matriz2, **multiplicada, i,j,k,n,m,o;
	scanf("%d %d %d", &n, &m, &o);
	
	matriz1 = (int*) malloc(sizeof(int*) * n);
	multiplicada = (int*) malloc(sizeof(int*) * n);
	for(i=0; i<n; i++){
		matriz1[i] = (int) malloc(sizeof(int) * m);
		for(j=0; j<m; j++)
			scanf("%d", &matriz1[i][j]);
	}
	
	matriz2 = (int*) malloc(sizeof(int*) * m);
	for(i=0; i<m; i++){
		matriz2[i] = (int) malloc(sizeof(int) * o);
		multiplicada[i] = (int) calloc(o, sizeof(int));//Poderia usar malloc e depois usar memset(multiplicada[i],0,o); 		
		for(j=0; j<o; j++){		
			scanf("%d", &matriz2[i][j]);			
		}			
	}
		
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			for(k=0; k<o; k++){
				multiplicada[i][k] += (matriz1[i][j] * matriz2[j][k]);
			}
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<o; j++){		
			printf("%d", multiplicada[i][j]);
			if(j+1 != o)
				printf(" ");
		}
		printf("\n");
	}
		
	return 0;
}
