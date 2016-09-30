/***
	* 
	* @author victoraurelio.com	
	* @since 20/04/2016
	*
***/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,k;
	char game[9][3][3];
	scanf("%d",&n);
	for(i=0; i<n; i++){
		int linhas[3]={0,0,0},colunas[3]={0,0,0},d1=0,d2=0,xWin=0, oWin=0,x=0,o=0,u=0;
		for(j=0; j<3; j++){
			for(k=0; k<3; k++){
				scanf(" %c",&game[i][j][k]);
				linhas[j] += (int) game[i][j][k];
				colunas[k] += (int) game[i][j][k];
				if(j==k)
					d1 += (int) game[i][j][k];
				if(k+j == 2)
					d2 += (int) game[i][j][k];
				switch(game[i][j][k]){
					case 88:
						x++;
					break;
					case 79:
						o++;
					break;
				}
			}
		}
		if(d1 == 264)xWin++;
		if(d2 == 264)xWin++;
		if(d1 == 237)oWin++;
		if(d2 == 237)oWin++;
		for(k=0; k<3; k++){
			if(linhas[k] == 264)xWin++;
			if(colunas[k] == 264)xWin++;
			if(linhas[k] == 237)oWin++;
			if(colunas[k] == 237)oWin++;
		}
		if( (abs(x-o) > 1) || (xWin > 1 || oWin > 1) || (xWin==1 && oWin==1)){
			printf("ILEGAL\n");
		}else if(xWin==1 && oWin==0){
			if(x-o == 1) printf("X_VENCEU\n");
			else printf("ILEGAL\n");
		}else if(xWin==0 && oWin==1){
			if(o-x == 0)printf("O_VENCEU\n");
			else printf("ILEGAL\n");
		}else if(xWin == 0 && oWin==0){
			printf("EM_ANDAMENTO\n");
		}
	}
	return 0;
}