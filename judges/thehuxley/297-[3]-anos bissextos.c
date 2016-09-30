/***
	*
 	* @author victoraurelio.com/
 	* since 09-04-2016
 	*
***/
#include<stdio.h>
int main(){
	int yearOne,yearTwo,i,exist=0;
	scanf("%d %d", &yearOne, &yearTwo);
	for(i=yearOne; i<=yearTwo; i++)
		if(i%4 == 0){
			printf("%d\n",i);
			exist = 1;
		}
	if(!exist){
		printf("-1\n");
	}
	return 0;
}
