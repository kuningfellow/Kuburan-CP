#include<bits/stdc++.h>
using namespace std;
int par[100005];
int L[100005];
int R[100005];
int found[100005];
vector<int>temp[100005];
vector<pair<int,int> >edge;
vector<pair<int,int> >query;
vector<int>cor;
vector<int>car;
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n,m;
		scanf("%d%d",&n,&m);
		edge.clear();
		query.clear();
		cor.clear();
		car.clear();
		for (int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if (a==1){
				edge.push_back(pair<int,int>(b-1,c-1));
				cor.push_back(i+1);
			}
			else{
				query.push_back(pair<int,int>(b-1,c-1));
				car.push_back(i+1);
			}
		}
		int siz=query.size();
		int tim=edge.size();
		for (int i=0;i<siz;i++){
			found[i]=-1;
			L[i]=0;
			R[i]=tim-1;
		}
		while (1<2){
			int stop=1;
			for (int i=0;i<n;i++){
				par[i]=i;
			}
			for (int i=0;i<tim;i++){
				temp[i].clear();
			}
			for (int i=0;i<siz;i++){
				if (L[i]<=R[i]){
					temp[(L[i]+R[i])/2].push_back(i);
					stop=0;
				}
			}
			for (int i=0;i<tim;i++){
				par[finpar(edge[i].first)]=finpar(edge[i].second);
				for (int j=0;j<temp[i].size();j++){
					if (car[temp[i][j]]<cor[i]){
						R[temp[i][j]]=i-1;
					}
					else if (finpar(query[temp[i][j]].first)==finpar(query[temp[i][j]].second)){
						R[temp[i][j]]=i-1;
						found[temp[i][j]]=cor[i];
					}
					else{
						L[temp[i][j]]=i+1;
					}
				}
			}
			if (stop)break;
		}
		for (int i=0;i<siz;i++){
			if (query[i].first==query[i].second)printf ("0");
			else printf ("%d\n",found[i]);
		}
	}
}