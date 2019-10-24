#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n,m;
		cin>>n>>m;
		if (n==0&&m==0)break;
		int en=n%2>0;
		int em=m%2>0;
		int pack1=max( ((n/2)*(m/2)+(n/2+en)*(m/2+em)) , (m/2)*(n/2)+((m/2+em)*(n/2+en)) );
		int pack2=max( (n*(m/3+(m%3>0))), (m*(n/3+(n%3>0))) );
		int pack3=0;
		if (n==2){
			pack3=2*(m/4*2+(min(m%4,2)));
		}
		if (m==2){
			pack3=2*(n/4*2+(min(n%4,2)));
		}
		int ans=max(pack1,pack2);
		ans=max(ans,pack3);
		printf ("%d knights may be placed on a %d row %d column board.\n",ans,n,m);
	}
}