/***
	*
	* @author victoraurelio.com
	* @since 13/04/17
	*
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int x){ //x always >= 1 guaranted by question..
  if(x == 2 || x == 3) return 1;
  if(x == 1 || (x & 1) == 0) return 0;// x & 1 binary check if number is even or odd
  for(int i=3; i <=(int) sqrt(x); i++){
      if(x%i == 0){
          return 0;
      }
  }
  return 1;
}
int main(){
    int t;
    long int a,b;
    int root;
    int result=0;
    scanf("%d", &t);
    while(t--){
        scanf("%ld%ld", &a,&b);
        for(int i=a; i<=b; i++){
            root = sqrt(i);
            if(root*root == i && isPrime(root)){// more fast that ceil function
                result++;
            }
        }
        printf("%d\n", result);
        result=0;
    }
    return 0;
}
