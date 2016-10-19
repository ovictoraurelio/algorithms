/***
	*
	* @author victoraurelio.com
	* @since 01/10/16
	*
*/
#include <bits/stdc++.h>

using namespace std;
int n, m, w,i,weight[1000000],maax=0,c=0;;
int main(){
	scanf("%d", &n);
	while(n--){
		maax=0,c=0;
		scanf("%d%d", &m, &w);
		for(i=0; i<m; i++) scanf("%d", &weight[i]);		
		sort(weight, weight + m);
		i=0; while(i < m && (w -= weight[i++]) >= 0){ c++; weight[i-1] = 0;} 
		printf("%d\n", c);
		for(i=i; i<m; i++)weight[i]=0;
	}
	return 0;
}