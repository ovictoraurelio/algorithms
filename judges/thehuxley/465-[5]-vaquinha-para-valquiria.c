/***
	*
 	* @author victoraurelio.com/
 	* since 09-04-2016
 	*
***/
#include<stdio.h>
int main(){
	float donation=0.0,total=0.00;
	int i = 0;	
	while(1){
		scanf("%f",&donation);
		if(donation >= 0.0){
			total +=donation;
			i++;
		}else{
			printf("%.2f\n%.2f\n", total, (i==0?0:(total/i)));
			break;
		}
	}	
	return 0;
}