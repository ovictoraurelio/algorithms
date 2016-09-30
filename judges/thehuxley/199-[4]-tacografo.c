/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
**/
int main(){
    int i,n,distancia=0,tempo,velocidadeMedia;
    scanf("%d",&n);
    for(i=0; i<n; i++){
            scanf("%d",&tempo);
            scanf("%d",&velocidadeMedia);
            distancia+=(tempo*velocidadeMedia);
    }
    printf("%d\n",distancia);
    return 0;
}
