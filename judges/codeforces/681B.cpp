/***
	*
	* @author victoraurelio.com
	* @since 27/09/16
	*
*/
#include <bits/stdc++.h>

using namespace std;
int n, near=0, a=1234567,b=123456,c=1234;
int solvingProblem(){
	for(int i=0; i<1000; i++)
		for(int j=0; j<1000; j++){
			near = n - ((i*a) + (j*b));
			if(near >= 0 && near % c == 0) return 1;
		}
	return 0;
}
int main(){
	scanf("%d", &n);
	printf("%s\n", solvingProblem() ? "YES" : "NO");
	return 0;
}