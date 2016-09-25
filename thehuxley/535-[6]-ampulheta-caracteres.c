/***
	* 
	* @author victoraurelio.com	
	* @since 17/07/2016
	*
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n=0,i=0,j=0,nLinhas,nColunas,areiaInf, areiaSup,c,k;
    scanf("%d", &k);
    for(c=0; c<k; c++){    	
	    scanf("%d", &n);
	    scanf("%d", &areiaInf);
	    nColunas=n*2;
		nLinhas=nColunas-1;
		areiaSup = n - areiaInf;
		printf("Caso %d:\n",c+1);
		for(i=0; i<=nLinhas; i++){    
			printf("*");	
	        for(j=1; j<nColunas; j++){
	        	if((i==nLinhas || i==0) && j%2==1){
	        		printf("*");
				}else if(i<n && (i+1==j || i+j == nLinhas)){			
						printf("*");
				}else if(i>=n && ( i+j == nColunas || i==j)){			
						printf("*");
				}else {				
					if((i+1<n && n-i<areiaSup)&& (i+j < nLinhas && j-i>1))
						printf(".");
					else if(i<nLinhas && i+areiaInf>=nLinhas && (i+j > nColunas && j-i<0)) 
						printf(".");
					else
						printf(" ");
				}
			}
			printf("*\n");
	    }	    
	}
    return 0;
}