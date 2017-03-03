/****
    *
    *   @author victoraurelio.com
    *   @since 03/03/2017
    *
**/
#include <bits/stdc++.h>

using namespace std;

list<int> a;
pair<int,int> p,pF;
list<int>::iterator i;
int main(){
	char n;
	while(scanf("%c", &n) != EOF){
		int c=0,b=0;
		if( (n == '\n' || n == 10) && a.size() > 1){
				pF.first=0;pF.second=0;
				for(i=a.begin(); i!=a.end(); i++){
					if(*i == 0){
						if(c == 0) p.first = distance(a.begin(), i);
						p.second = distance(a.begin(), i);
						c++;
					}else{
							if(c>b){
								pF = p;
								b=c;
							}
							c=0;				
					}
				}
				cout << pF.first << " " << pF.second << endl;
				a.clear();
		}else{
			if(n != ' ')
				a.push_back(n - 48);
		}
	}
}
