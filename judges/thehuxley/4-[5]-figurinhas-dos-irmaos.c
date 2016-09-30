/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
***/
#include <stdio.h>
int existeIgual(int v[10000], int x, int t){
	int i;
	for(i=0; i<t; i++){		
		if(v[i] == x){			
			return 1;
		}
	}
	return 0;	
}
int main(){
	int i,n,somaMaria=0,somaJoao=0,somaSeries[2]={0,0},series[10000];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &series[i]);
		if(series[i]%2==0){
			somaJoao++;
			if(!existeIgual(series, series[i], i))
				somaSeries[1]+=series[i];
		}else{
			somaMaria++;
			if(!existeIgual(series, series[i], i))
				somaSeries[0]+=series[i];
		}		
	}
	printf("%d\n%d\n%d\n",somaJoao,somaMaria, (somaSeries[0]>somaSeries[1]?somaSeries[0]:somaSeries[1]));
	return 0;
}