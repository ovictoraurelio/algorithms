/***
	* 
	* @author victoraurelio.com
	* @since 24/04/2016
	*
***/
#include <stdio.h>
int multiplicar(int x, int y){	
	if(x == 0 || y == 0){
		return 0;
	}else if(x<0 && y<0 || x>0 && y>0 || x<0){
		y--;
		if(y<0){
			x=abs(x);
			y=abs(y+2);
		}
		return x + multiplicar(x,y);
	}else if(y<0){
		x--;
		return y + multiplicar(x,y);
	}
}
int main(){
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d\n", multiplicar(x,y));
	return 0;
}