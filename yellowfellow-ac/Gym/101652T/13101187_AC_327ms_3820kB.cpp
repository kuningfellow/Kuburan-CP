#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > >lis[1005];
int vis[1005];
int s,en;
int dfs(int x, int l, int r){
	if (l>r)return 0;
	vis[x]=1;
	if (x==en){
		return 1;
	}
	int ret=0;
	for (int i=0;i<lis[x].size();i++){
		if (vis[lis[x][i].first]==0&&lis[x][i].second.first<=l&&lis[x][i].second.second>=r){
			ret=max(ret,dfs(lis[x][i].first,l,r));
		}
	}
	return ret;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	cin>>s>>en;
	int a,b,c,d;
	vector<int>border;
	map<int,int>use;
	for (int i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		lis[a].push_back(pair<int,pair<int,int> >(b,pair<int,int>(c,d)));
		if (use[c]==0){
			border.push_back(c);
			use[c]=1;
		}
		if (use[d]==0){
			border.push_back(d);
			use[d]=1;
		}
	}
	use.clear();
	sort(border.begin(),border.end());
	for (int i=0;i<1005;i++){
		vis[i]=0;
	}
	int sum=dfs(s,border[0],border[0]);
	for (int i=0;i<border.size()-1;i++){
		for (int j=0;j<1005;j++){
			vis[j]=0;
		}
		sum+=(border[i+1]-border[i]-1)*dfs(s,border[i]+1,border[i+1]-1);
		for (int j=0;j<1005;j++){
			vis[j]=0;
		}
		sum+=dfs(s,border[i+1],border[i+1]);
	}
	printf ("%d\n",sum);
}