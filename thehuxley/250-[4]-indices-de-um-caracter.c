/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
#include<stdio.h>
#include<string.h>
int main(){
	char str[50],c;int i;
	gets(str);
	scanf("%c",&c);
	for(i=0; i<strlen(str); i++){
		if( str[i] == c)
			printf("%d\n",i);
	}
	printf("-1\n");
	return 0;
}
