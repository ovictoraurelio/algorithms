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
	printf("%d\n",x>y?1:0);
	printf("%d\n",x==y?1:0);
	printf("%d\n",x<y?1:0);
	printf("%d\n",x!=y?1:0);
	printf("%d\n",x>=y?1:0);
	printf("%d\n",x<=y?1:0);
	return 0;
}