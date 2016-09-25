/***
	* 
	* @author victoraurelio.com	
	* @since 22/04/2016
	*
*/
#include <stdio.h>
int main(){
	int x=0,y=0,emOrdem=1;
	while(1){
		scanf("%d", &x);
		if(x!=0){
			if(y>x)
				emOrdem=0;
			y=x;
		}else{
			break;
		}
	}
	printf("%s\n", emOrdem?"EM ORDEM":"FORA DE ORDEM");
	return 0;
}