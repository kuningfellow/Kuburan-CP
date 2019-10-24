#include <bits/stdc++.h>
using namespace std;
int par[2005];
int from[2005];
int vis[2005];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
vector<int>con[2005];
void dfs(int x){
	vis[x]=1;
	for (int i=0;i<con[x].size();i++){
		if (vis[con[x][i]]==0){
			from[con[x][i]]=x;
			dfs(con[x][i]);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<2005;i++){
		par[i]=i;
		con[i].clear();
		vis[i]=0;
	}
	vector<pair<long long int,pair<int,int> > >lis;
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++){
			long long int c;
			scanf("%lld",&c);
			lis.push_back(pair<long long int,pair<int,int> >(c,pair<int,int>(i,j)));
			lis.push_back(pair<long long int,pair<int,int> >(c,pair<int,int>(j,i)));
		}
	}
	sort(lis.begin(),lis.end());
	long long int tot=0;
	for (int i=lis.size()-1;i>=0;i--){
		if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
			par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
			tot+=lis[i].first;
			con[lis[i].second.first].push_back(lis[i].second.second);
			con[lis[i].second.second].push_back(lis[i].second.first);
		}
	}
	printf ("%lld\n",tot);
	dfs(0);
	for (int i=1;i<n;i++){
		printf ("%d\n",from[i]+1);
	}
}