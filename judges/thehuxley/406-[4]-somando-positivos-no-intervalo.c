/***
	*
 	* @author victoraurelio.com/
 	* since 09-04-2016
 	*
***/
#include<stdio.h>
int main(){
	int a,b,r=0,i;
	scanf("%d %d",&a,&b);
	for(i=(a<b?a:b); i<=(a>b?a:b); i++){			
		if(i>0)
			r+=i;
	}
	printf("%d\n",r);
	return 0;
}
