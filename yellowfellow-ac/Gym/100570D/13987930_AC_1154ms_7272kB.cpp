#include <bits/stdc++.h>
using namespace std;
map<long long int,int>cor;
vector<pair<int,int> >lis;
int par[400010];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int yes=1;
	int tc;
	int idx=2;
	cin>>tc;
	for (int i=0;i<400010;i++){
		par[i]=i;
	}
	while (tc--){
		long long int a,b;
		cin>>a>>b;
		b=-b;
		if (cor[a]==0){
			cor[a]=idx;
			idx+=2;
		}
		if (cor[b]==0){
			cor[b]=idx;
			idx+=2;
		}
		char rem[5];
		char ram[5];
		scanf("%s",rem);
		scanf("%s",ram);
		if (yes==1){
			if (rem[0]==ram[0]){
				lis.push_back(pair<int,int>(cor[a],cor[b]));
				par[finpar(cor[a])]=finpar(cor[b]);
				lis.push_back(pair<int,int>(cor[a]^1,cor[b]^1));
				par[finpar(cor[a]^1)]=finpar(cor[b]^1);
			}
			else{
				lis.push_back(pair<int,int>(cor[a],cor[b]^1));
				par[finpar(cor[a])]=finpar(cor[b]^1);
				lis.push_back(pair<int,int>(cor[b],cor[a]^1));
				par[finpar(cor[b])]=finpar(cor[a]^1);
			}
		}
		if (finpar(cor[a])==finpar(cor[a]^1)||finpar(cor[b])==finpar(cor[b]^1)){
			yes=0;
		}
		if (yes==1){
			printf ("Yes\n");
		}
		else printf ("No\n");
	}
}