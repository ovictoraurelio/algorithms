/***
   *
   * @author victoraurelio.com
   * @since 28/05/2016
   *
***/
#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	int id;
	int medalhas[3]; // 0 é ouro, 1 é prata e 2 é bronze
}selecao;
void setSelecao(selecao *selecao, int id, int ouro, int prata, int bronze){
	selecao->id=id;
	selecao->medalhas[0]=ouro;
	selecao->medalhas[1]=prata;
	selecao->medalhas[2]=bronze;
}
void swap(selecao *a, selecao *b){
	selecao c;
	setSelecao(&c, a->id, a->medalhas[0], a->medalhas[1], a->medalhas[2]);
	setSelecao(a, b->id, b->medalhas[0], b->medalhas[1], b->medalhas[2]);
	setSelecao(b, c.id, c.medalhas[0], c.medalhas[1], c.medalhas[2]);	
}
void ordernarSelecoes(selecao *lista, int tamanho){
	int i,j,k;
	for(i=0; i<tamanho; i++){
		for(k=i+1; k<tamanho; k++)
			for(j=0; j<3; j++){
				if(lista[i].medalhas[j] > lista[k].medalhas[j])
					break;
				else if(lista[i].medalhas[j] < lista[k].medalhas[j]){
					swap(&lista[i], &lista[k]);
					break;
				}else if(j==2){
					if(lista[i].id > lista[k].id)
						swap(&lista[i], &lista[k]);
				}
			}
	}
}
int main(){
	int quantidadeSelecoes, quantidadeModalidades;
	int i, codigoOuro, codigoPrata, codigoBronze;
	selecao *selecoes;
	scanf("%d %d", &quantidadeSelecoes, &quantidadeModalidades);
	selecoes = (selecao*) malloc(sizeof(selecao) * quantidadeSelecoes);
	for(i=0; i<quantidadeSelecoes; i++){
		setSelecao(&selecoes[i],i+1,0,0,0);
	}
	for(i=0; i<quantidadeModalidades; i++){
		scanf("%d %d %d", &codigoOuro, &codigoPrata, &codigoBronze);
		selecoes[codigoOuro-1].medalhas[0]++;		
		selecoes[codigoPrata-1].medalhas[1]++;		
		selecoes[codigoBronze-1].medalhas[2]++;		
	}
	ordernarSelecoes(selecoes, quantidadeSelecoes);
	for(i=0; i<quantidadeSelecoes; i++){
		printf("%d\n",selecoes[i].id);		
	}
}
