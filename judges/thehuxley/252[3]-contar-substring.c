/***
	*
	* @author victoraurelio.com
	* @since 01/06/2017
	*
*/
#include<stdio.h>
#include<string.h>

int main(){
	char string[200], sub[200];
	int n,i,j=0,size,nRepeticoes=0;

	scanf(" %[^\n]", string);
	scanf(" %[^\n]", sub);

	n = strlen(string);
	size = strlen(sub);

	for(i=0; i<=n; i++){
		for(j=0; sub[j] != '\0' && string[i+j] == sub[j]; j++);

		if(j == size){
			nRepeticoes++;
		}
		j=0;
	}

	printf("%d\n", nRepeticoes);

	return 0;
}