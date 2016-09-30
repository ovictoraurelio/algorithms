/****
    *
    *   @author victoraurelio.com
    *   @since 02/05/2016
    *
**/
float velkmh(float velocidadeInicial, float aceleracao, int tempo){
    return (velocidadeInicial + (aceleracao * tempo)) * 3.6;
}
int main(){
    float v0, a, t, automovelMenorVelocidade=-1;
    int i;
    for(i=0; i<3; i++){
        scanf("%f", &v0);
        scanf("%f", &a);
        scanf("%f", &t);
        //printf("\n%.1f\n", velkmh(v0,a,t));
        if(automovelMenorVelocidade > velkmh(v0,a,t) || i==0)
            automovelMenorVelocidade = velkmh(v0,a,t);

    }
    printf("%.1f",automovelMenorVelocidade);
    return 0;
}
