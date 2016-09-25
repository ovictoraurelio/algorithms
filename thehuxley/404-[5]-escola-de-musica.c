/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
char* ClassificaAluno(float media, int faltas){
    if(media >= 7 && faltas <= 10)
        if(media > 9.5)
            return "APROVADO COM LOUVOR";
        else
            return "APROVADO";
    else if(faltas > 10)
        return "REPROVADO POR FALTAS";
    else
        return "REPROVADO";
}
int main(){
    float media;
    int faltas;
    scanf("%f", &media);
    scanf("%d", &faltas);
    printf("%s",ClassificaAluno(media, faltas));
    return 0;
}
