/***
	*
	* @author victoraurelio.com
	* @since 06/05/2016 -> 10/05/2016
	*
*/
void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void inverter(int *array, int inicio, int final){
	int i;
	for(i=inicio; i<=(inicio+final)/2; i++){		
		swap(array+i, array+(inicio+final-i));
	}
}
void rotacionar(int *array, int tamanho, int quantidadeDeDeslocamentos){
	// inverto a primeira até o deslocamento.
	inverter(array, 0, quantidadeDeDeslocamentos-1);	
	// inverto do deslocamento até o fim.
	inverter(array, quantidadeDeDeslocamentos, tamanho-1);	
	// inverto do inicio ao final ;)
	inverter(array, 0, tamanho-1);	
}
int main(){
	int n,i,k,qtdDeslocamentos;
	int array[100000];
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d", array+i);	
	scanf("%d",&qtdDeslocamentos);
	//caso o numero de deslocamentos seja maior do que N, queremos o resto...
	qtdDeslocamentos = qtdDeslocamentos > n ? qtdDeslocamentos % n : qtdDeslocamentos;
	rotacionar(array,n,qtdDeslocamentos);
	for(i=0; i<n; i++)
		printf("%d\n",*(array+i));
	return 0;
}