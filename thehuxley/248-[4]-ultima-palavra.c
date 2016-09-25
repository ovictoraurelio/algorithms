/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
#include<stdio.h>
#include<string.h>
int main(){
	char str[400],lastWord[400];
	int i,c=0;
	gets(str);
	for(i=strlen(str)-1; i>=0; i--){
		if(str[i]==' ')
			break;
		lastWord[c]=str[i];
		c++;
	}
	for(i=c-1; i>=0; i--){
		printf("%c",lastWord[i]);
	}
	printf("\n");

	return 0;
}
