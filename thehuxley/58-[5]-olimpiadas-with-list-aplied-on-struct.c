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
	int medalhasOuro;
	int medalhasPrata;
	int medalhasBronze;
	struct s *proxima;
}selecao;
void setSelecao(selecao *selecao, int id, int ouro, int prata, int bronze){
	selecao->id=id;
	selecao->medalhasOuro=ouro;
	selecao->medalhasPrata=prata;
	selecao->medalhasBronze=bronze;
	selecao->proxima = NULL;
}
selecao *buscarSelecaoPorCodigo(selecao *selecoes, int tamanho, int codigo){
	int i;
	for(i=0; i<tamanho; i++)
		if(selecoes[i].id == codigo)
			return &selecoes[i];
	return NULL;
}
int ordernarSelecao(selecao *anterior, selecao *proxima, int a, int b){
	if(a>b){
		printf("A selecao %d tem mais medalha que a selecao %d\n", anterior->id, proxima->id);
		anterior->proxima = proxima;
		return 1;
	}else if(a==b){
		return 0;
	}else{
		printf("else selecao %d tem mais medalha que a selecao %d\n", proxima->id, anterior->id);		
		proxima->proxima = anterior;		
		anterior = proxima;		
		anterior->proxima->proxima = NULL;
		return 1;
	}
}
selecao *ordernarSelecoes(selecao *lista, int tamanho){
	int i;
	selecao *ordenados = &lista[0];
	for(i=0; i<tamanho+1; i++){		
		printf("Eu vou comprar: %d && %d\n", ordenados->id, lista[i].id);
		if(ordenados != NULL && &lista[i] != NULL){
			if(ordernarSelecao(ordenados, &lista[i], ordenados->medalhasOuro,lista[i].medalhasOuro)){			
			}else if(ordernarSelecao(ordenados, &lista[i], ordenados->medalhasPrata,lista[i].medalhasPrata)){			
			}else if(ordernarSelecao(ordenados, &lista[i], ordenados->medalhasBronze,lista[i].medalhasBronze)){			
			}else{
				ordernarSelecao(ordenados, &lista[i], lista[i].id,ordenados->id);
			}
		}
	}
	return ordenados;
}
int main(){
	int quantidadeSelecoes, quantidadeModalidades;
	int i, codigoOuro, codigoPrata, codigoBronze;
	selecao *selecoes, *selecoesOrdenadas, *tmp;
	scanf("%d %d", &quantidadeSelecoes, &quantidadeModalidades);
	selecoes = (selecao*) malloc(sizeof(selecao) * quantidadeSelecoes);
	for(i=0; i<quantidadeSelecoes; i++){
		setSelecao(&selecoes[i],i+1,0,0,0);
	}
	for(i=0; i<quantidadeModalidades; i++){
		scanf("%d %d %d", &codigoOuro, &codigoPrata, &codigoBronze);
		tmp = buscarSelecaoPorCodigo(selecoes, quantidadeSelecoes, codigoOuro);
		tmp->medalhasOuro++;
		tmp = buscarSelecaoPorCodigo(selecoes, quantidadeSelecoes, codigoPrata);
		tmp->medalhasPrata++;
		tmp = buscarSelecaoPorCodigo(selecoes, quantidadeSelecoes, codigoBronze);
		tmp->medalhasBronze++;		
	}
	selecoesOrdenadas = ordernarSelecoes(selecoes, i);	
	while(selecoesOrdenadas != NULL){
		printf("%d\n",selecoesOrdenadas->id);
		selecoesOrdenadas = selecoesOrdenadas->proxima;
	}
}
