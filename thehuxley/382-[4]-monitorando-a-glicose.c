/***
	*
	* @author victoraurelio.com/
 	* since 09-04-2016
 	*
***/
#include<stdio.h>
int main(){
	int n=1,media=-1,i;
	for(i=-1; n!=0; i++){	
		scanf("%d",&n);
		media+=n;
	}
	if(media/i < 110){
		printf("Glicose Normal");
	}else if(media/i >= 200){
		printf("Glicose Muito Alta");
	}else {
		printf("Glicose Alterada");
	}	
	return 0;
}
