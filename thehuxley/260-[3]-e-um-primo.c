/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
***/
#include <stdio.h>
int main(){
	int n,i,primo=1;
	while(1){
		scanf("%d", &n);
		if(n != -1){
			primo = (n<2?0:1);
			for (i=2; i<n; i++) 
				if (n % i == 0) 
		  			primo = 0; 

		   	printf("%d\n", primo);
		}else{
			break;
		}
	}
	return 0;
}