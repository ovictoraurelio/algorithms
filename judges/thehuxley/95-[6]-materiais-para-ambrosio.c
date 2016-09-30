/***
	* 
	* @author victoraurelio.com	
	* @since 30/05/2016
	*
***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct p{
	char nome[26];
	double preco;
}produto;
int main(){	
	double emCaixa;
	produto produtos[100], tmp;
	int i,j,nProdutos;	
	scanf("%lf", &emCaixa);	
	scanf("%d", &nProdutos);
	for(i=0; i<nProdutos; i++){
		scanf(" %s", produtos[i].nome);
		scanf("%lf", &(produtos[i].preco));
	}
	
	// ORDENANDO PELO MENOR PREÇO
	for(i=0; i<nProdutos; i++){
		for(j=1; j<nProdutos; j++){
			if(produtos[j-1].preco >  produtos[j].preco){
				tmp = produtos[j-1];
				produtos[j-1] = produtos[j];
				produtos[j] = tmp;
			}
		}
	}
	
	// CALCULANDO O QUE É POSSÍVEL COMPRAR.	
	for(i=0; emCaixa - produtos[i].preco > 0.0; i++){
		emCaixa = emCaixa - produtos[i].preco;
	}
	nProdutos =  i;

	//ORDENA OS PRODUTOS POR NOME	
	for(i=0; i<nProdutos; i++){
		for(j=1; j<nProdutos; j++){
			if(strcmp(produtos[j-1].nome, produtos[j].nome) > 0){
				tmp = produtos[j-1];
				produtos[j-1] = produtos[j];
				produtos[j] = tmp;
			}
		}
	}	
	for(i=0; i<nProdutos; i++)
		printf("%s %.2lf\n", produtos[i].nome, produtos[i].preco);
	printf("%.2lf\n", emCaixa);
}