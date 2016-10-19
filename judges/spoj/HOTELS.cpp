/***
	*
	* @author victoraurelio.com
	* @since 01/10/16
	*
*/
#include <bits/stdc++.h>

using namespace std;
long long int n, m, l=0, r=0, maax=0, soma=0;
int hotels[3000000];

int main(){
	scanf("%lld%lld", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &hotels[i]);
	}
	
	//slinding window
	while(r<n){
		if(soma + hotels[r] <= m){
			soma += hotels[r];
			if(soma > maax) maax = soma;
			r++;
		}else{
			soma -= hotels[l];
			l++;
		}
	}	

	printf("%lld\n", maax);
	return 0;
}