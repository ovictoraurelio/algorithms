/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
***/
#include <stdio.h>
int main(){
	int a,b,c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);	
	if(c>b){
		b=b+c;
		c=b-c;
		b=b-c;
	}
	if(b>a){
		b=a+b;
		a=b-a;
		b=b-a;
	}
	if(c>b){
		b=b+c;
		c=b-c;
		b=b-c;	
	}
	printf("%d\n%d\n%d\n", a,b,c);
	return 0;
}