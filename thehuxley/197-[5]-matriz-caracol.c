/***
	* 
	* @author victoraurelio.com	
	* @since 26/04/2016
	*
***/
#include<stdio.h>
int main(){	
	int i=0,j=0,n,voltas=1,preenchimento=0,m[500][500];
	scanf("%d",&n);	
	char sentido = 'd'; //{'d', 'r', 'u', 'l'}; //down - right - up - left
	/**
	  A variavel sentido começa e down porque ele sempre vai inciar em 0x0 e ir até em baixo. Lá no switch ele sabe se ainda pode ir pra baixo, se não pode vai para direita e assim sucessivamente até não haver mais leitura a se fazer.
	*/
	while(preenchimento < (n*n)){
		scanf("%d", &m[i][j]);
		switch(sentido){
			case 'd':
				i++;
				if(i+voltas == n) sentido = 'r';
			break;
			case 'r':
				j++;
				if(j+voltas == n) sentido = 'u';
			break;
			case 'u':
				i--;
				if(i+j == n-1) sentido = 'l';
			break;
			case 'l':
				j--;
				if(j-i == 1){
					sentido = 'd';
					voltas++;
				}
			break;
		}
		preenchimento++;
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d\n", m[i][j]);
		}		
	}	
	return 0;
}