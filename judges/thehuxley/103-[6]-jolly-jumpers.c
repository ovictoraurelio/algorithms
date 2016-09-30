/****
    *
    *   @author victoraurelio.com
    *   @since 24/05/16
    *
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main () {
	int vet[3200], jolly[3200];
	int number, i, isJolly = 0, diff;
	while(scanf("%d", &number) > 0){
		for(i=0; i<number; i++){
			scanf("%d", &vet[i]);
			jolly[i] = 0;
		}
		for(i=1; i<number; i++){
			diff = abs(vet[i] - vet[i-1]);
			if(diff < number && diff >= 1 && jolly[diff] != 1) {
				jolly[diff] = 1;
				isJolly++;
			}
		}
		if(isJolly == number-1) {
			printf("Jolly\n");
		}else{
			printf("Not jolly\n");
		}			
		isJolly = 0;
	}
	return 0;
}