/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
***/
#include <stdio.h>
int main(){
	int n[5][2],i,j,max=0,maxNum=0;
	for(i=0; i<5; i++){
		scanf("%d", &n[i][0]);
		n[i][1]=0;
		for (j=1; j<=n[i][0]; j++){
    		if (n[i][0]%j==0)
      			n[i][1]+=j;
      	}      	
      	if(n[i][1] >= max){
      		maxNum = n[i][0];
      		max = n[i][1];
      	}

	}
	printf("%d\n", maxNum);
	return 0;
}