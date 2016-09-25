/***
	* 
	* @author victoraurelio.com
	* @since 13/05
	*
*/
#include<stdio.h>
#include<stdlib.h>
struct bigNumber{
	char *content;
	int sizeOf;
}typedef bigNumber;
bigNumber *readBigNumber(){
	bigNumber *number = (bigNumber*) malloc(sizeof(bigNumber));
	(*number).content = (char*) calloc(2,sizeof(char));
	char c;
	int i=0;
	do{
		scanf("%c", &(*number).content[i]);
		(*number).content = (char*) realloc ((*number).content ,(i+2)*(sizeof(char)));
	}
	while((*number).content[i++] != '\n');
	(*number).content[i-1] = '\0';
	(*number).sizeOf = i-1;
	return number;
}
void switchNumbers(bigNumber *numberOne, bigNumber *numberTwo){
	bigNumber aux;
	aux.content = (*numberOne).content;
	aux.sizeOf = (*numberOne).sizeOf;
	(*numberOne).content = (*numberTwo).content;
	(*numberOne).sizeOf = (*numberTwo).sizeOf;
	(*numberTwo).content = aux.content;
	(*numberTwo).sizeOf = aux.sizeOf;
}
void sumBigNumber(bigNumber *numberOne, bigNumber *numberTwo){
	int i,j, currentSum = 0;	
	char aux;
	int *result = (int*) malloc((2+(*numberOne).sizeOf + (*numberTwo).sizeOf)  * sizeof(int));
	if((*numberTwo).sizeOf > (*numberOne).sizeOf){
		switchNumbers(numberOne, numberTwo);
	}	
	for(i=(*numberOne).sizeOf - 1, j=(*numberTwo).sizeOf - 1; i>=0 ; i--, j--){			
		(*numberOne).content[i] -= 48;		
		if(j >= 0){
			(*numberTwo).content[j] -= 48;
			currentSum = (*numberOne).content[i] + (*numberTwo).content[j];
		}else{
			currentSum = (*numberOne).content[i];
		}		
		if(currentSum >= 10){
			result[j-1] +=  currentSum/10;
			if (result[j] == 0 )result[j] = currentSum % 10;
			else result[j] += currentSum%10;
		}
		else if (currentSum < 10){
			result[i] += currentSum;
		}
		result[i] = currentSum;			
	}
	for(; j>=0; j--){
		result[j] += (*numberOne).content[j] - 48;		
		if(result[j] >= 10 && j != 0){
			result[j-1] +=  result[j]/10;			
			result[j] = result[j]%10;			
		}
	}
	for(i=(*numberOne).sizeOf - 1; i >= 0; i--){
		if (result[i] >= 10 && i > 0){
			result[i-1] +=  result[i]/10;
			result[i] = result[i]%10;
		}
	}
	for(i=0; i<(*numberOne).sizeOf; i++)
		printf("%d", result[i]);
	printf("\n");
}
int main(){
    bigNumber *numberOne, *numberTwo;
    char *result;
    numberOne = readBigNumber();    
    numberTwo = readBigNumber();
    sumBigNumber(numberOne, numberTwo);
    free(numberOne);
    free(numberTwo);
    return 0;
}

