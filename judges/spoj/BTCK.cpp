/***
	*
	* @author victoraurelio.com
	* @since 13/11/16
	*
*/
#include <bits/stdc++.h>

using namespace std;

int i,tc,v[10],n[10],k;
long long int r=0;
bool success=false;

bool solve(){
	r=0;
	for(i=0; i<10; i++){
    	if(r + (n[i] * v[i]) <= k){
    		r += (n[i] * v[i]);
    	}else{
    		return false;
    	}
    }
    success = true;
	return true;
}
int main(){
	scanf("%d", &tc);	
	while(tc--){
		for(i=0; i<10; i++) v[i] = i;
		for(i=0; i<10; i++) scanf("%d", &n[i]);
		scanf("%d", &k);
		
		while( !solve() && next_permutation(v,v+10));

		if(success == true){
			printf("%d", v[0]);
			for(i=1; i<10; i++)printf(" %d",v[i]);
            printf("\n");
		}else{
			printf("-1\n");
		}		
		success = false;		
	}
	return 0;
}