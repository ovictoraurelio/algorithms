/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
*/
#include <stdio.h>
int main(){
	int producao[2][12],i,j;
	double custoLucro[2][2],soma[2][2]={0,0,0,0};
	for(i=0; i<12; i++){
		scanf("%d", &producao[0][i]);
		scanf("%d", &producao[1][i]);
	}

	scanf("%lf",&custoLucro[0][0]);//custo
	scanf("%lf",&custoLucro[0][1]);//lucro
	scanf("%lf",&custoLucro[1][0]);//custo
	scanf("%lf",&custoLucro[1][1]);//custo

	for(i=0; i<2; i++){
		for(j=0; j<12; j++){
			printf("Motor[%d], Mes[%d], custo=[%.2f], lucro=[%.2f]\n", i, j+1,producao[i][j]*custoLucro[i][0], producao[i][j]*custoLucro[i][1]);
			soma[i][0]+=producao[i][j]*custoLucro[i][0];
			soma[i][1]+=producao[i][j]*custoLucro[i][1];
		}
	}
	printf("Motor[0], anual, custo=[%.2f], lucro=[%.2f]\n",soma[0][0], soma[0][1]);
	printf("Motor[1], anual, custo=[%.2f], lucro=[%.2f]\n",soma[1][0], soma[1][1]);
	return 0;
}