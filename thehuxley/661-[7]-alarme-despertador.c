/***
	* 
	* @author victoraurelio.com	
	* @since 17/07/2016
	*
*/
#include <stdio.h>
int main(){
	int start[2],end[2],result;
	while(scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]) > 0 && (start[0] != 0 || start[1] || 0  && end[0] || 0 && end[1] != 0)){
		if((start[0] * 60) + start[1] < (end[0] * 60) + start[1]){
			result = ((start[0] * 60) + start[1]) - ((end[0] * 60) + end[1]);
		}else{
			result = 1440 - ((start[0] * 60) + start[1]);
			result += ((end[0] * 60) + end[1]);
		}
		printf("%d\n", result < 0 ? -result : result);
	}	
	return 0;
}