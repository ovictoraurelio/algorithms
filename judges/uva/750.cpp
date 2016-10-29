/***
	*
	* @author victoraurelio.com
	* @since 28/10/16
	*
*/
#include <bits/stdc++.h>
#define COLUMNS 8
#define ROWS 8
using namespace std;

int n,ld[16], rd[16], col[COLUMNS], c,x,y,rows[ROWS];


void marcar(int l,int i,int v){
	ld[l+i] = rd[l-i+7] = col[i] = v;
}

void backtrack(int l){	
	if(l==8){
		printf("%2d     ", ++c);
		//cout << "" << ++c << "     ";
		for(int i=0; i<8; i++){
			cout << " " << (rows[i]+1);
		}
		cout << endl;		
	}else{	
		if(l==y){			
			backtrack(l+1);
		}else{
			for(int i=0;i<COLUMNS;i++){
				if(col[i] == 0 && ld[l+i] == 0 && rd[l-i+7] == 0){
					//solution.push_back(make_pair(l, i));
					rows[l]=i;
					marcar(l,i,1);								
					
					backtrack(l + 1);

					marcar(l,i,0);
					//solution.pop_back();
				}
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	while(n--){	
		c=0;	
		scanf("%d%d", &x, &y);

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");	

		y-=1;x-=1;
		marcar(y,x,1);		
		rows[y]=x;
		backtrack(0);		
		marcar(y,x,0);		

		if(n>0)printf("\n");		
	}
	return 0;
}