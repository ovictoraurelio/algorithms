/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
void showArray(int array[5],char nome[6]){
    int i;
    for(i=0; i<5; i++)
        printf("%s[%d] = %d\n",nome,i,array[i]);
}
int main(){
    int par[5],impar[5];
    int n,i,cpar=0,cimpar=0;
    for(i=0; i<15; i++){
        scanf("%d", &n);
        if(n%2==0){
            par[cpar]=n;
            cpar++;
            if(cpar==5){
                showArray(par,"par");
                cpar=0;
            }
        }else{
            impar[cimpar]=n;
            cimpar++;
            if(cimpar==5){
                showArray(impar,"impar");
                cimpar=0;
            }
        }
    }
    for(i=0; i<cimpar; i++)
        printf("impar[%d] = %d\n",i,impar[i]);
    for(i=0; i<cpar; i++)
        printf("par[%d] = %d\n",i,par[i]);

    return 0;
}
