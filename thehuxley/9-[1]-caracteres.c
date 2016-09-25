/***
    *
    *   @author victoraurelio.com/
    *   @since 17-03-2016
    *
***/
int main(){
	char caracteres[1000];
	int n,i;
	while(1){
        scanf("%d", &n);
        if(n==0)break;
        scanf("%s",&caracteres);
        for(i=n-1; i>=0; i--)
            printf("%c",caracteres[i]);
        printf("\n");
	}
	return 1;
}
