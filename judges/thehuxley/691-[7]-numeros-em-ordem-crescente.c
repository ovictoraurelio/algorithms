/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
*/
#include <stdio.h>
int main(){
	int x,y;
	scanf("%d", &x);
	scanf("%d", &y);
	if(y>x){
		x=x+y;
		y=x-y;
		x=x-y;
	}
	printf("%d %d\n",x,y);
	return 0;
}