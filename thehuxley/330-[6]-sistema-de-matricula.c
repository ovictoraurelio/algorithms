/***
	* 
	* @author victoraurelio.com	
	* @since 30/05/2016
	*
***/
#include<stdio.h>
#include<stdlib.h>
typedef struct a{
    char *id;
    char *nome;
    int idade;
    int sexo;
    double notaEnem;
}Aluno;
typedef struct b{
    char *id;
    char *titulo;
    int quantidadeAlunosMatriculados;
    Aluno *alunosMatriculados;
}Disciplina;
 
char* lerString();
void lerAluno(Aluno *aluno);
void lerDisciplina(Disciplina *disciplina);
Aluno* buscarAlunoPorCodigo(Aluno *alunos, char *codigo, int *tamanho);
Disciplina* buscarDisciplinaPorCodigo(Disciplina *disciplinas, char *codigo, int *tamanho);
void lerMatricula(Disciplina *disciplinas, int *tamanhoDisciplinas, Aluno *alunos, int *tamanhoAlunos);
double calcularMediaIdadeAlunosPorMediaEnem(Aluno *alunos, double mediaEnem, int *tamanho);
int contarAlunoPorSexo(Aluno *alunos, int sexo, int *tamanho);
void ordernarDisciplinasPorNome(Disciplina *disciplinas, int *tamanho);
void ordernarAlunosPorNome(Aluno *alunos, int *tamanho);
void imprimirDetalhesDasDisciplinas(Disciplina *disciplinas, int *tamanhoDisciplinas, Aluno *alunos, int *tamanhoAlunos);
int main(){
    int quantidadeDeAlunos, quantidadeDeDisciplinas, quantidadeDeMatriculas;
    int i,j;
    Aluno *alunos;
    Disciplina *disciplinas;
    // ->>> LER ALUNOS
    scanf("%d", &quantidadeDeAlunos);
    alunos = (Aluno*) malloc(sizeof(Aluno) * quantidadeDeAlunos);
    for(i=0; i<quantidadeDeAlunos; i++)
        lerAluno(&alunos[i]);
    // ->>> LER DISCIPLINAS
    scanf("%d", &quantidadeDeDisciplinas);
    disciplinas = (Disciplina*) malloc(sizeof(Disciplina) * quantidadeDeDisciplinas);
    for(i=0; i<quantidadeDeDisciplinas; i++)
        lerDisciplina(&disciplinas[i]);
    // ->>> LER MATRÍCULAS
    scanf("%d", &quantidadeDeMatriculas);  
    for(i=0; i<quantidadeDeMatriculas; i++)
        lerMatricula(disciplinas, &quantidadeDeDisciplinas, alunos, &quantidadeDeAlunos);
    // ->>> EXIBIR INFORMAÇÕES
    //Quantidade de alunos do sexo masculino;
    printf("%d\n",contarAlunoPorSexo(alunos, 1, &quantidadeDeAlunos));
    //Quantidade de alunos do sexo feminino;
    printf("%d\n",contarAlunoPorSexo(alunos, 0, &quantidadeDeAlunos));
    //Média das idades dos alunos, formatado com duas casas decimais;
    printf("%.2lf\n",calcularMediaIdadeAlunosPorMediaEnem(alunos, 0, &quantidadeDeAlunos));
    //Média das idades dos alunos que tiraram nota maior que 7.5 no enem, formatado com duas casas decimais;
    printf("%.2lf\n",calcularMediaIdadeAlunosPorMediaEnem(alunos, 7.5, &quantidadeDeAlunos));
    //Para cada disciplina, ordenadas em ordem alfabética, imprimir o nome da disciplina,
    //a quantidade de alunos matriculados nela e os nomes dos alunos que se matricularam nela,
    //também em ordem alfabética, sendo um por linha. Se não houverem alunos matriculados,
    //simplesmente não imprima nenhum aluno.
    ordernarDisciplinasPorNome(disciplinas, &quantidadeDeDisciplinas); 
    imprimirDetalhesDasDisciplinas(disciplinas, &quantidadeDeDisciplinas, alunos, &quantidadeDeAlunos);
    return 0;
}
char *lerString(){
    char *str = (char*) malloc(sizeof(char));
    char c;
    int i=0;
    do{
        scanf("%c", &c);       
        if(c!=10){
            str[i] = c;
            i++;
            str = (char*) realloc(str, sizeof(char) * (i+2));
            if(str == NULL){
                exit(1);
            }
        }
    }while(c != 10 || i==0);
    str[i] = '\0';
    return str;
}
void lerAluno(Aluno *aluno){   
    aluno->id = lerString();
    aluno->nome = lerString();
    scanf("%d", &aluno->idade);
    scanf("%d", &aluno->sexo);
    scanf("%lf", &aluno->notaEnem);
}
void lerDisciplina(Disciplina *disciplina){
    disciplina->id = lerString();
    disciplina->titulo = lerString();  
    disciplina->quantidadeAlunosMatriculados=0;
    disciplina->alunosMatriculados = NULL;
}
void lerMatricula(Disciplina *disciplinas, int *tamanhoDisciplinas, Aluno *alunos, int *tamanhoAlunos){
    char codigoDisciplina[20], codigoAluno[30];
    Aluno *alunoDesejaMatricular;
    Disciplina *disciplinaOfertada;
    scanf(" %s",codigoAluno);
    scanf(" %s",codigoDisciplina);
    disciplinaOfertada = buscarDisciplinaPorCodigo(disciplinas, codigoDisciplina, tamanhoDisciplinas); 
    alunoDesejaMatricular = buscarAlunoPorCodigo(alunos, codigoAluno, tamanhoAlunos);  
    if(disciplinaOfertada != NULL && alunoDesejaMatricular != NULL){
        if(disciplinaOfertada->alunosMatriculados != NULL){                    
            int tamanhoAlunosMatriculados = sizeof(Aluno) * (++(disciplinaOfertada->quantidadeAlunosMatriculados));
            disciplinaOfertada->alunosMatriculados = realloc(disciplinaOfertada->alunosMatriculados,tamanhoAlunosMatriculados);
            disciplinaOfertada->alunosMatriculados[(tamanhoAlunosMatriculados/sizeof(Aluno)) - 1 ] = (*alunoDesejaMatricular);         
        }else{
            disciplinaOfertada->alunosMatriculados = malloc(sizeof(Aluno) * (++(disciplinaOfertada->quantidadeAlunosMatriculados)));
            (*disciplinaOfertada->alunosMatriculados) = (*alunoDesejaMatricular);
        }
    }
}
Aluno* buscarAlunoPorCodigo(Aluno *alunos, char *codigo, int *tamanho){
    int i;
    for(i=0; i<*tamanho; i++)
        if(strcmp(alunos[i].id,codigo) == 0)
            return &alunos[i]; 
    return NULL;
}
Disciplina* buscarDisciplinaPorCodigo(Disciplina *disciplinas, char *codigo, int *tamanho){
    int i; 
    for(i=0; i<*tamanho; i++)
        if(strcmp(disciplinas[i].id,codigo) == 0)
            return &disciplinas[i];    
    return NULL;
}
void ordernarAlunosPorNome(Aluno *alunos, int *tamanho){
    int i,j;
    Aluno tmp;
    for (i = 1; i < *tamanho; i++) {
        for (j = 1; j < *tamanho; j++) {
            if(strcmp(alunos[j-1].nome, alunos[j].nome) > 0) {
            tmp = alunos[j-1];
            alunos[j-1] = alunos[j];
            alunos[j] = tmp;
         }
      }
   }
}
void ordernarDisciplinasPorNome(Disciplina *disciplinas, int *tamanho){
    int i,j;
    Disciplina tmp;
    for (i = 1; i < *tamanho; i++) {
        for (j = 1; j < *tamanho; j++) {
            if(strcmp(disciplinas[j-1].titulo, disciplinas[j].titulo) > 0) {
            tmp = disciplinas[j-1];
            disciplinas[j-1] = disciplinas[j];
            disciplinas[j] = tmp;
         }
      }
   }
}
int contarAlunoPorSexo(Aluno *alunos, int sexo, int *tamanho){
    int i, count=0;
    for(i=0; i<*tamanho; i++)
        if(alunos[i].sexo == sexo)
            count++;
    return count;
}
double calcularMediaIdadeAlunosPorMediaEnem(Aluno *alunos, double mediaEnem, int *tamanho){
    int i,count=0;
    double mediaIdade=0;
    for(i=0; i<*tamanho; i++)
        if(alunos[i].notaEnem >= mediaEnem){
            mediaIdade+=alunos[i].idade;
            count=count+1;
        }
    return mediaIdade/count;
}
void imprimirDetalhesDasDisciplinas(Disciplina *disciplinas, int *tamanhoDisciplinas, Aluno *alunos, int *tamanhoAlunos){
    int i,j;   
    for(i=0; i<*tamanhoDisciplinas; i++){
        printf("%s\n", disciplinas[i].titulo);
        printf("%d\n", disciplinas[i].quantidadeAlunosMatriculados);
        if(disciplinas[i].quantidadeAlunosMatriculados > 0){
            ordernarAlunosPorNome(disciplinas[i].alunosMatriculados, &(disciplinas[i].quantidadeAlunosMatriculados));
            for(j=0; j<disciplinas[i].quantidadeAlunosMatriculados; j++)
                printf("%s\n", disciplinas[i].alunosMatriculados[j].nome);
        }
    }
}