/***
    * 
    * @author victoraurelio.com    
    * @since 17/07/2016
    *
*/
#include <stdio.h>
#include <math.h>
 
int list[10000000]={0,0,1,1},n;
 
int flip() {
    if (list[n]==1) list[n]=0;
    else list[n]=1;
    return 0;
}
 
int clean(int n, int limit) {
    int k,l=n*n,i;
    for (i=2,k=l;k<=limit;i++,k=i*l) list[k]=0;
    return 0;
}
 
int main() {
    int i,x,y;
    int d_limit,limit;
    float f_limit;
 
    //FILE *f = fopen("out.txt","w");
 
    scanf("%f",&f_limit);
    d_limit=(int)(sqrt(f_limit)); limit=(int)(f_limit);
 
    for (i=5;i<=limit;i++) list[i]=0;
 
    for (x=1;x<=d_limit;x++) {
        for (y=1;y<=d_limit;y++) {
            n=4*(x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) flip();
 
            n=3*(x*x)+(y*y);
            if (n <= limit && n % 12 == 7) flip();
 
            n=3*(x*x)-(y*y);
            if (x>y && n <= limit && n % 12 == 11) flip();
        }
    }
 
    for (n=5;n<=d_limit;n++) {
        if (list[n]) clean(n,limit);
    }
 
    for (i=2;i<=limit;i++){
        if (list[i]) printf("%d\n",i);
    }
 
    return 0;
}