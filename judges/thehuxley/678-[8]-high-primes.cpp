/***
	*
	* @author victoraurelio.com
	* @since 13/04/17
	*
*/
#include <bits/stdc++.h>
#define realLimit 1000000000000
#define LIMIT 1000001
#define ROOT 1000
using namespace std;


//define my limit of prime to check as 10 ^ 6 (square root of 10^12)
bool primes[LIMIT];
int c[LIMIT];

int crivoErastotenes(){ //x always >= 1 guaranted by question..
    int p;
    primes[0]=primes[1]=primes[1000000]=true;
    for(int i=2; i<ROOT; i++){
        if(primes[i] == false){// if not prime so (i² + k*i) also
            if(i*i < LIMIT){
                p = i*i;
                for(int j=p; j < LIMIT; j += i){
                    primes[j] = true;
                }
            }
        }
    }
}

int main(){
    int t,l,h;
    long int a,b;
    int result = 0;
    scanf("%d", &t);

    crivoErastotenes();

    for(int i=1; i<LIMIT; i++){
        c[i] = c[i-1];
        if(primes[i] == false){
          c[i]+=1;
        }
    }

    while(t--){
        scanf("%ld%ld", &a,&b);
        if( a == b){
            l = (int)( sqrt(a ) );//lower
            printf("%d\n", c[l] - c[l-1]);
        }else{
            l = (floor)( sqrt(a ));//lower
            h = (ceil) ( sqrt(b ));//higher
            printf("%d\n", c[h] - c[l]);
        }
        result=0;
    }
    return 0;
}