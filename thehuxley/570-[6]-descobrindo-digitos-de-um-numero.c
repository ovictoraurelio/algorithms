/***
	* 
	* @author victoraurelio.com	
	* @since 24/04/2016
	*
*/
#include <stdio.h>
int main(){
	int n,a,b,c;
	scanf("%d",&n);
	a = n/100;
	b = n/10 - a *10;
	c = n - a*100 - b*10;
	printf("%d %d %d\n", a,b,c);
	return 0;
}