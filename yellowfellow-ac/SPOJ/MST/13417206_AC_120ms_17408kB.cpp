#include <bits/stdc++.h>
using namespace std;
int par[10005];
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
	int n,m;
	cin>>n>>m;
	for (int i=0;i<=n;i++){
		par[i]=i;
	}
	struct dat edge[m];
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[i].cost=c;
		edge[i].a=a;
		edge[i].b=b;
	}
	long long int tot=0;
	sort(edge,edge+m);
	for (int i=0;i<m;i++){
		if (finpar(edge[i].a)!=finpar(edge[i].b)){
			tot+=edge[i].cost;
			par[finpar(edge[i].a)]=finpar(edge[i].b);
		}
	}
	printf ("%lld\n",tot);
}