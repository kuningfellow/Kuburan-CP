//UVA 10330 Power Transmission
#include<bits/stdc++.h>
#define REG(x) (x+n)
using namespace std;
int S;
int T;
int ef[203];
int H[203];
int flow[203][203];
int has[203][203];
vector<int>lis[203];
int push(int x){
	int lab=1;
	int val=0;
	for (int i=0;i<lis[x].size();i++){
		if (flow[x][lis[x][i]]>0){
			val=1;
			if (H[x]>H[lis[x][i]]){
				lab=0;
				int del=min(ef[x],flow[x][lis[x][i]]);
				ef[x]-=del;
				ef[lis[x][i]]+=del;
				flow[x][lis[x][i]]-=del;
				flow[lis[x][i]][x]+=del;
			}
		}
	}
	return val&lab;
}
void relabel(int x){
	int mini=(1<<30);
	for (int i=0;i<lis[x].size();i++){
		if (flow[x][lis[x][i]]>0){
			mini=min(mini,H[lis[x][i]]);
		}
	}
	H[x]=mini+1;
}
void maxflow(int n){
	int rep=1;
	int sz=n*2+2;
	for (int i=0;i<=sz;i++){
		H[i]=0;
		ef[i]=0;
	}
	H[S]=sz;
	for (int i=0;i<lis[S].size();i++){
		ef[lis[S][i]]=flow[S][lis[S][i]];
		flow[S][lis[S][i]]-=ef[lis[S][i]];
		flow[lis[S][i]][S]+=ef[lis[S][i]];
	}
	while (rep){
		rep=0;
		for (int i=1;i<sz;i++){
			if (ef[i]==0)continue;
			rep=1;
			if (push(i))
				relabel(i);
		}
	}
}
int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		int sz=n*2+2;
		S=0;
		T=sz;
		for (int i=0;i<=sz;i++){
			lis[i].clear();
			for (int j=0;j<=sz;j++){
				flow[i][j]=0;
				has[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			flow[i][REG(i)]=a;
			lis[i].push_back(REG(i));
			lis[REG(i)].push_back(i);
		}
		int m,s,t;
		scanf("%d",&m);
		for (int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			flow[REG(a)][b]+=c;
			if (has[REG(a)][b]==0){
				lis[REG(a)].push_back(b);
				lis[b].push_back(REG(a));
				has[REG(a)][b]=1;
				has[b][REG(a)]=1;
			}
		}
		scanf("%d%d",&s,&t);
		while (s--){
			int a;
			scanf("%d",&a);
			flow[S][a]+=(1<<30);
			lis[S].push_back(a);
			lis[a].push_back(S);
		}
		while (t--){
			int a;
			scanf("%d",&a);
			flow[REG(a)][T]+=(1<<30);
			lis[REG(a)].push_back(T);
			lis[T].push_back(REG(a));
		}
		maxflow(n);
		printf ("%d\n",ef[T]);
	}
}
