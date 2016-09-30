/****
    *
    *   @author victoraurelio.com
    *   @since 02/05
    *
***/
void toUpperCase(char str[100]){
    int i;
    for(i=0; str[i]!='\0'; i++)
        if(str[i] > 96 && str[i] < 123)
            str[i]-=32;
}
int main(){
    char str[100];
    scanf(" %[^\n]", str);
    toUpperCase(str);
    printf("%s\n",str);
    return 0;
}
