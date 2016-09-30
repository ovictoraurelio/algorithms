/***
	* 
	* @author victoraurelio.com/
 	* since 09-04-2016
 	*
 ***/
 #include<stdio.h>
int main(){
	int a,b,n,i,exist=0;
	scanf("%d %d %d", &n, &a, &b);
	for(i=a; i<=b; i++)
		if(i%n == 0){		
			printf("%d\n",i);
			exist = 1;
		}
	if(!exist){
		printf("INEXISTENTE\n");
	}
}
