/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
#include <stdio.h>
#include <stdlib.h>
int vstrlen(char *str){
	int i;
	for(i=0; str[i] != '\0'; i++);
	return i;
}
void toUpperCase(char *str){
    int i;
    for(i=0; str[i]!='\0'; i++)
        if(str[i] > 96 && str[i] < 123)
            str[i]-=32;
}
int vstrcmp(char *str, char *str2){
	int i;	
	if(str == NULL){		
		return 0;			
	}else if(vstrlen(str) != vstrlen(str2)){
		return 0;
	}else{
		for(i=0; i<vstrlen(str); i++){			
			if(str[i] != str2[i])
				return 0;
		}
	}
	return 1;
}
char *vstrcat(char *destination, char *concat){
	char *string = (char*) malloc(vstrlen(destination) + vstrlen(concat) + 1);
	char *res = string;
	for (; *destination ; *string++ = *destination++);
	for (; *concat ; *string++ = *concat++);
	*string = '\0';
	return res;  
}
void scanfWithBlankSpace(char *str){
	char c;
	while(c != 10){
		scanf("%c", &c);
		if(c!=10){
			*str = c;
			str++;
		}
	}
	*str = '\0';
}
int main(){
	int i,sizeMemoryOfText=1;
	char *fromKeyboard = (char*) malloc(sizeof(char) * 76);
	char *text  = (char*) calloc('\0',sizeof(char));	
	for(i=0; 1; i++){		
		scanfWithBlankSpace(fromKeyboard);		
		if(vstrcmp(fromKeyboard, "the end!")){
			break;
		}else{
			toUpperCase(fromKeyboard);			
			sizeMemoryOfText += (sizeof(char) * vstrlen(fromKeyboard));
			text = (char*) realloc(text, sizeMemoryOfText);
			if(vstrlen(text) > 0){
				text = vstrcat(text, "\n");
				text = vstrcat(text,fromKeyboard);
			}else{
				text = vstrcat(text,fromKeyboard);
			}
		}
	}
	printf("%s", text);
	free(fromKeyboard);
	free(text);
	return 0;
}
