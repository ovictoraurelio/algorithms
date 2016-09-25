/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
***/
#include <stdio.h>
int main(){
	int n,i,j,naoEhPrimo=0;
	scanf("%d", &n);
	for(i=1; i<n; i++){		
		for (j=2; j<n; j++) 
    		if (n % i == 0) 
      			naoEhPrimo = 1; 
      	if(!naoEhPrimo){
      		printf("%d\n", n);
      	}
	}
	return 0;
}