/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
*/
#include <stdio.h>
int main(){
	int n1,n2,i,j,naoEhPrimo=1;
	scanf("%d", &n1);
	scanf("%d", &n2);	
	for(i=(n2>n1)?n2:n1; i>=((n2<n1)?n2:n1); i--){
		if(i==1)naoEhPrimo=1;
		for (j=2; j<i; j++){
    		if (i%j==0)
      			naoEhPrimo=1;      		
      	}      	
      	if(!naoEhPrimo){      		
      		printf("%d\n",i);
      	}      	
      	naoEhPrimo=0;
	}
	return 0;
}