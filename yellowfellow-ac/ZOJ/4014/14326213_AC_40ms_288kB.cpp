#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n,m,a,b;
		int c;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		int step=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				scanf("%d",&c);
				if (c<a||c>b){
					step++;
				}
			}
		}
		if (a>b)printf ("No Solution\n");
		else printf ("%d\n",step);
	}
}