#include <bits/stdc++.h>
using namespace std;
int par[30005];
int ppl[30005];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
void add(int x, int y){
	if (finpar(x)!=finpar(y)){
		ppl[finpar(x)]+=ppl[finpar(y)];
		ppl[finpar(y)]=0;
		par[finpar(y)]=finpar(x);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	while (1<2){
		int n,m;
		cin>>n>>m;
		if (n==0&&m==0)break;
		for (int i=0;i<n;i++){
			par[i]=i;
			ppl[i]=1;
		}
		for (int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b;
			for (int i=0;i<a-1;i++){
				cin>>c;
				add(b,c);
			}
		}
		printf ("%d\n",ppl[finpar(0)]);
	}
}