/***
	* 
	* @author victoraurelio.com	
	* @since 20/04/2016
	*
*/
#include <stdio.h>
int main(){
	int n[101],i;
	for(i=0; i<101; i++){
		scanf("%d", &n[i]);
	}
	for(i=0; i<100; i++){
		if(n[100] == n[i])
			printf("%d\n",i);
	}
	return 0;
}
