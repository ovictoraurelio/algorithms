/***
 	* @author victoraurelio.com/
	* since 09-04-2016
***/
#include<stdio.h>
int main(){
	int n,i,r=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		if(n%i==0 && i%3==0)
			r++;		
	if(r==0)printf("O numero nao possui divisores multiplos de 3!\n");
	else printf("%d", r);
	return 0;
}
