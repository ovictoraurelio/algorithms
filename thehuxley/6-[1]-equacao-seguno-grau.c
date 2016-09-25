/***
	* 
	* @author victoraurelio.com	
	* @since 18/06/2016
	*
*/
#include<stdio.h>
#include<math.h>
int main(){	
	double r1,r2,a,b,c,d;
	scanf("%lf %lf %lf", &a, &b, &c);
	d = (b*b) - (4*a*c);
	if(a == 0)
		printf("NEESG");
	else if(d < 0)
		printf("NRR");
	else{
		d=sqrt(d);
		r1 = (((-1)*b) + d) / (2 * a);
		r2 = (((-1)*b) - d ) / (2 * a);
		printf("%.2lf\n%.2lf\n",r1,r2);
	}	
	return 0;
}