/***
	*
	* @author victoraurelio.com
	* @since 27/05/2016 ->
	*
***/
#include<stdio.h>
#include<stdlib.h>
typedef struct produto{
	int codigo;
	char descricao[80];
	double valor;
}produto;
produto* buscarProdutoPorCodigo(produto *produtos, int quantidadeTotalDeProdutos, int codigo){
	int i;
	for(i=0; i < quantidadeTotalDeProdutos; i++)
		if(produtos[i].codigo == codigo)
			return &produtos[i];
	return NULL;
}
int main(){
	produto *produtos, *produtoBuscado;
	int quantidadeTotalDeProdutos,codigoProdutoDesejado,quantidadeProdutoDesejada,i;
	double valorTotal=0.0;
	scanf("%d", &quantidadeTotalDeProdutos);
	produtos = (produto*) malloc(sizeof(produto) * quantidadeTotalDeProdutos);
	for(i=0; i<quantidadeTotalDeProdutos; i++){
		scanf("%d", &produtos[i].codigo);
		scanf(" %[^\n]", produtos[i].descricao);
		scanf(" %lf", &produtos[i].valor);
	}
	while((scanf("%d", &codigoProdutoDesejado) > 0 && (codigoProdutoDesejado != 0)) ){
		if(scanf("%d", &quantidadeProdutoDesejada) > 0 && (quantidadeProdutoDesejada > 0)){
			produtoBuscado = buscarProdutoPorCodigo(produtos, quantidadeTotalDeProdutos, codigoProdutoDesejado);
			if(produtoBuscado != NULL){
				valorTotal += produtoBuscado->valor * quantidadeProdutoDesejada;
			}
		}
	}
	printf("%.2lf\n",valorTotal);
	return 0;
}