//UVA 10779 Collectors Problem
#include<bits/stdc++.h>
#define STI(x) (x+n)
#define SINK (n+m+1)
#define SIZ (n+m+1)
using namespace std;
int flow[37][37];
int has[37][37];
vector<int>lis[37];
int lab[37];
int ef[37];
int n;
int m;

// int bac[37];
// void bfs(){
// 	for (int i=1;i<=SIZ;i++){
// 		bac[i]=-1;
// 	}
// 	queue<int>q;
// 	q.push(1);
// 	bac[1]=0;
// 	while (!q.empty()){
// 		int siz=q.size();
// 		for (int i=0;i<siz;i++){
// 			int v=q.front();
// 			q.pop();
// 			for (int j=0;j<lis[v].size();j++){
// 				if (flow[v][lis[v][j]]>0&&bac[lis[v][j]]==-1){
// 					bac[lis[v][j]]=v;
// 					q.push(lis[v][j]);
// 				}
// 			}
// 		}
// 	}
// }
// int maxflow(){
// 	int ret=0;
// 	while (1<2){
// 		bfs();
// 		if (bac[SINK]==-1){
// 			break;
// 		}
// 		int x=SINK;
// 		int red=(1<<30);
// 		vector<int>trace;
// 		while (x!=1){
// 			red=min(red,flow[bac[x]][x]);
// 			trace.push_back(x);
// 			x=bac[x];
// 		}
// 		trace.push_back(1);
// 		for (int i=1;i<trace.size();i++){
// 			flow[trace[i]][trace[i-1]]-=red;
// 			flow[trace[i-1]][trace[i]]+=red;
// 		}
// 		ret+=red;
// 	}
// 	return ret;
// }

int push(int x){
	int ret=1;
	int val=0;
	for (int i=0;i<lis[x].size();i++){
		if (flow[x][lis[x][i]]>0){
			if (lab[lis[x][i]]<lab[x]){
				int del=min(ef[x],flow[x][lis[x][i]]);
				flow[x][lis[x][i]]-=del;
				flow[lis[x][i]][x]+=del;
				ef[x]-=del;
				ef[lis[x][i]]+=del;
				ret=0;
			}
			val=1;
		}
	}
	return ret&val;
}
void relabel(int x){
	int mini=(1<<30);
	for (int i=0;i<lis[x].size();i++){
		if (flow[x][lis[x][i]]>0){
			mini=min(mini,lab[lis[x][i]]);
		}
	}
	lab[x]=mini+1;
}
int maxflow(){
	for (int i=1;i<=SIZ;i++){
		lab[i]=0;
		ef[i]=0;
	}
	for (int i=0;i<lis[1].size();i++){
		ef[lis[1][i]]=flow[1][lis[1][i]];
		flow[lis[1][i]][1]=flow[1][lis[1][i]];
		flow[1][lis[1][i]]=0;
	}
	lab[1]=SIZ;
	int rep=1;
	while (rep){
		rep=0;
		for (int i=2;i<SIZ;i++){
			if (ef[i]==0)continue;
			rep=1;
			if (push(i))
				relabel(i);
		}
	}
	return ef[SINK];
}

int main(){
	int kas=1;
	int tc;
	cin>>tc;
	while (tc--){
		cin>>n>>m;
		for (int i=0;i<=SIZ;i++){
			for (int j=0;j<=SIZ;j++){
				flow[i][j]=0;
				has[i][j]=0;
			}
			lis[i].clear();
		}
		for (int i=1;i<=m;i++){
			lis[STI(i)].push_back(SINK);
			lis[SINK].push_back(STI(i));
			flow[STI(i)][SINK]=1;
		}
		for (int i=1;i<=n;i++){
			int c;
			cin>>c;
			for (int j=0;j<c;j++){
				int a;
				cin>>a;
				flow[i][STI(a)]++;
				if (has[i][STI(a)]==0){
					if (i!=1)
						flow[i][STI(a)]--;
					lis[i].push_back(STI(a));
					lis[STI(a)].push_back(i);
					has[i][STI(a)]=1;
					has[STI(a)][i]=1;
				}
			}
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				if (has[STI(i)][j]==0){
					lis[STI(i)].push_back(j);
					lis[j].push_back(STI(i));
					has[STI(i)][j]=1;
					has[j][STI(i)]=1;
					flow[STI(i)][j]=1;
				}
			}
		}
		printf ("Case #%d: %d\n",kas++,maxflow());
	}
}