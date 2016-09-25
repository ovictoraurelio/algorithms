/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
*/
#include <stdio.h>
int main(){
	int n,i,naoEhPrimo;
	scanf("%d", &n);
	naoEhPrimo = (n<2?1:0);
	for(i=2; i<n; i++) 
		if (n % i == 0) 
  			naoEhPrimo = 1; 

  	if(naoEhPrimo)
  		printf("NAO\n");
  	else 
  		printf("SIM\n");
		
	return 0;
}