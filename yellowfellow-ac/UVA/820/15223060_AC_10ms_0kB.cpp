//UVA 820 Internet Bandwidth
//push relable algorithm
#include<bits/stdc++.h>
using namespace std;
int flow[105][105];
int height[105];
int excess[105];
vector<int>lis[105];
int S,T;
void init(int n){
	height[S]=n;
	for (int i=0;i<lis[S].size();i++){
		if (flow[S][lis[S][i]]>0){
			int delta=flow[S][lis[S][i]];
			excess[lis[S][i]]+=delta;
			flow[S][lis[S][i]]-=delta;
			flow[lis[S][i]][S]+=delta;
		}
	}
}
int push(int a){
	int needrelabel=1;
	for (int i=0;i<lis[a].size();i++){
		if (flow[a][lis[a][i]]>0){
			if (height[a]<=height[lis[a][i]])continue;
			needrelabel=0;
			int delta=min(excess[a],flow[a][lis[a][i]]);
			excess[a]-=delta;
			flow[a][lis[a][i]]-=delta;
			excess[lis[a][i]]+=delta;
			flow[lis[a][i]][a]+=delta;
		}
	}
	return needrelabel;
}
void relabel(int a){
	int mini=height[a];
	for (int i=0;i<lis[a].size();i++){
		if (flow[a][lis[a][i]]>0){
			mini=min(mini,height[lis[a][i]]);
		}
	}
	height[a]=mini+1;
}
void maxflow(int n){
	while (1<2){
		int rep=0;
		for (int i=1;i<=n;i++){
			if (i==S||i==T)continue;
			if (excess[i]==0)continue;
			rep=1;
			if (push(i))relabel(i);
		}
		if (rep==0)break;
	}
}
int main(){
	int kas=1;
	while (1<2){
		int n,e;
		scanf("%d",&n);
		if (n==0)break;
		for (int i=1;i<=n;i++){
			lis[i].clear();
			height[i]=0;
			excess[i]=0;
			for (int j=1;j<=n;j++)
				flow[i][j]=0;
		}
		scanf("%d%d%d",&S,&T,&e);
		for (int i=0;i<e;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			lis[a].push_back(b);
			lis[b].push_back(a);
			flow[a][b]+=c;
			flow[b][a]+=c;
		}
		init(n);
		maxflow(n);
		printf ("Network %d\nThe bandwidth is %d.\n\n",kas++,excess[T]);
	}
}