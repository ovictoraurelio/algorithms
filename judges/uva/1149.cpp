/***
	*
	* @author victoraurelio.com
	* @since 24/10/16
	*
*/
#include <bits/stdc++.h>

using namespace std;

int c,itens[100000],binLength, nItens;

int sw(int itens[]){
	int count=0;
	for(int r=nItens-1,l=0; r>=l; r--){
		if(r != l && itens[l] + itens[r] <= binLength){
			l++; // I can put item on right and on left..
		}
		count++;
	}
	return count;
}

int main(){
	scanf("%d", &c);
	while(c--){
		scanf("%d%d", &nItens, &binLength);
		for(int i=0; i<nItens; i++) scanf("%d", &itens[i]);	
		sort(itens, itens + nItens);//itens in order..
		printf("%d\n",sw(itens));
		if(c>0)printf("\n");
	}	
	return 0;
}