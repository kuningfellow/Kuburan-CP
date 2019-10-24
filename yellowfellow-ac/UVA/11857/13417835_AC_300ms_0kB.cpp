#include <bits/stdc++.h>
using namespace std;
int par[1000005];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
struct dat{
	int cost;
	int a;
	int b;
	bool operator < (dat other){
		return cost<=other.cost;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	while (1<2){
		int n,m;
		scanf("%d%d",&n,&m);
		if (n==0&&m==0)break;
		for (int i=0;i<n;i++){
			par[i]=i;
		}
		int a,b,c;
		struct dat data[m];
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			data[i].cost=c;
			data[i].a=a;
			data[i].b=b;
		}
		int maxi=0;
		int cnt=0;
		sort(data,data+m);
		for (int i=0;i<m;i++){
			if (finpar(data[i].a)!=finpar(data[i].b)){
				maxi=data[i].cost;
				cnt++;
				par[finpar(data[i].a)]=finpar(data[i].b);
			}
			if (cnt==n-1)break;
		}
		if (cnt!=n-1)printf ("IMPOSSIBLE\n");
		else printf ("%d\n",maxi);
	}
}