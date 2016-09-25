/***
	*
	* @author victoraurelio.com
	* @since 15/05
	*
***/
#include <stdio.h>
#include <stdlib.h>
int vstrlen(char *str){
	int i;
	for(i=0; str[i]!='\0'; i++);
	return i;
}
int aWordThatComesAfterTheOtherInAlphabeticalOrder(char *word1, char *word2){
	int i;
	int maxStrLengthCmp = vstrlen(word1) > vstrlen(word2) ? vstrlen(word2) : vstrlen(word1);	
	for(i=0; i<maxStrLengthCmp; i++){	
		if(word1[i] > word2[i])
			return 1;
		else if(word1[i] < word2[i])
			return 0;
	}
	return 0;
}
void addToListInOrder(char **list, char *name, int listSize){
	int i;	
	char *aux;
	list[listSize] = name;	
	for(i=listSize; i>=0; i--){
		if(i-1 >= 0){
			if(aWordThatComesAfterTheOtherInAlphabeticalOrder(list[i-1], list[i])){				
				aux = list[i];
				list[i] = list[i-1];
				list[i-1] = aux;
			}else{
				break;
			}
		}
	}
}
int main(){
    char *fromKeyboard = (char *) malloc(sizeof(char) * 20);
    char **ordenedList;
    int i,n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    ordenedList = (char**) malloc(sizeof(char*) * n);
    for(i=0; i<n; i++){
    	//memset(fromKeyboard, '\0', 20);
    	scanf(" %[^\n]", fromKeyboard);    	
    	addToListInOrder(ordenedList, fromKeyboard, i);    	
    	fromKeyboard = (char *) malloc(sizeof(char) * 20); //alocating space to a new word. The last space is aponted!!!
    }
    printf("%s\n", ordenedList[k-1]);
    return 0;
}
