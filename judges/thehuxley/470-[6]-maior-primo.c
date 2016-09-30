/***
	* 
	* @author victoraurelio.com	
	* @since 24/04/2016
	*
*/
#include <stdio.h>
int main(){
	int n,i,primo=1,max=0;
	while(1){
		scanf("%d", &n);
		if(n != 404){
			primo = (n<2?0:1);
			for (i=2; i<n; i++) 
				if (n % i == 0) 
		  			primo = 0; 

		   	if(primo == 1 && n>max)
		   		max = n;
		}else{
			break;
		}
	}
	if(max!=0)
		printf("%d\n", max);
	else
		printf("SEM PRIMOS\n");
	return 0;
}