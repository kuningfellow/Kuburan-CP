#include <bits/stdc++.h>
using namespace std;
int par[30];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
vector<pair<int,pair<int,int> > >lis;
int main(){
	int tc;
	int kas=1;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		lis.clear();
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				int a;
				scanf("%d",&a);
				if (j!=n-1)getchar();
				lis.push_back(pair<int,pair<int,int> >(a,pair<int,int>(i,j)));
			}
		}
		vector<pair<int,pair<int,int> > >sav;
		sort(lis.begin(),lis.end());
		for (int i=0;i<n;i++){
			par[i]=i;
		}
		for (int i=0;i<lis.size();i++){
			if (lis[i].first==0)continue;
			if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
				par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
				sav.push_back(pair<int,pair<int,int> >(lis[i].first,pair<int,int>(lis[i].second.first,lis[i].second.second)));
			}
		}
		printf ("Case %d:\n",kas++);
		for (int i=0;i<sav.size();i++){
			printf ("%c-%c %d\n",sav[i].second.first+'A',sav[i].second.second+'A',sav[i].first);
		}
	}
}