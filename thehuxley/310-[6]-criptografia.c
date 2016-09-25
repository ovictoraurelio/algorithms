/***
	* 
	* @author victoraurelio.com	
	* @since 20/04/2016
	*
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,size;
	scanf("%d",&n);	
	for(i=0; i<n; i++){
		char str[102];
		scanf(" %[^\n]", str);
		size = strlen(str);		
		for(j=0; j<size; j++){
			if((str[j] > 64 && str[j] < 91) ||  (str[j] > 96 &str[j] < 123)){
				str[j] = str[j] + 3;
			}
		}
		for(j=0; j<size/2; j++){
			str[j] = str[size-(j+1)] + str[j];
			str[size-(j+1)] = str[j] - str[size-(j+1)];
			str[j] = str[j] - str[size-(j+1)];
		}		
		for(j=size/2; j<size; j++){
			str[j] = str[j] - 1;
		}
		printf("%s\n", str);
	}
	return 0;
}