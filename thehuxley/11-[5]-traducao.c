/***
	* @author victoraurelio.com
	* @since 06/05/2016 -> 10/05/2016
	*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vstrlen(char *str){
	int i;
	for(i=0; str[i] != '\0'; i++);
	return i;
}
int vstrcmp(char *str, char *cmp){
	int i;
	if(vstrlen(str) == vstrlen(cmp))
		for(i=0; i<vstrlen(str); i++)
			if(str[i] != cmp[i])
				return 0;
	else 
		return 0;
	return 1;
}
void empurrarParaEsquerda(char *str){//função para ignorar o '-> ' ... vide scanf de substituir[i][1]
	int i;
	for(i=0; i<vstrlen(str); i++){
		str[i] = str[i+3];
	}
	str[i+1]='\0';
}
void vsubsStr(char *frase, char *str, int strSize, char *subs){
	char *before = frase, *after = str + strSize;
	int i=0, cpy = vstrlen(frase) - (vstrlen(after) + strSize);
	char frase2[1000];
	strncpy(frase2, before, cpy);
	frase2[cpy]='\0';
	strcat(frase2, subs);
	strcat(frase2, after);
	strncpy(frase, frase2, vstrlen(frase2));
	frase[vstrlen(frase2)]='\0';
}
void substituirPalavrasNaFrase(char frase[100][1000], char busca[100][2][100],int n,int m){
	int i,j=0;
	char *palavraAsubstituir;	
	for(i=0; i<m; i++){//para cada frase
		for(j=0; j<n; j++){//para cada palavra a ser substituida
			palavraAsubstituir = frase[i];//dizendo que deve começar a procurar do inicio...			
			while(1){
				if(!(palavraAsubstituir = strstr(palavraAsubstituir, busca[j][0])))
					break;
				vsubsStr(frase[i], palavraAsubstituir, vstrlen(busca[j][0]), busca[j][1]);
				palavraAsubstituir++;
			}
		}
	}
}
int main(){
	int n,m,i;
	char substituir[100][2][100], frase[100][1000];
	while(1){
		scanf("%d %d", &n, &m);
		if(n==0 && m==0) break;		
		for(i=0; i<n; i++){
			scanf(" %[^ ->]", substituir[i][0]);
			scanf(" %[^\n]", substituir[i][1]);
			empurrarParaEsquerda(substituir[i][1]);
		}
		for(i=0; i<m; i++){
			scanf(" %[^\n]", frase[i]);			
		}
		substituirPalavrasNaFrase(frase, substituir,n,m);
		for(i=0; i<m; i++){
			printf("%s\n", frase[i]);
		}
	}	
}