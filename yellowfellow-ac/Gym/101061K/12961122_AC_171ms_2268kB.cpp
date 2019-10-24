#include <bits/stdc++.h>
using namespace std;
int haus[105][105];
vector<int>boyhaus[105];
vector<int>boygun[105];
int flow[210][210];
int vis[210];
int sta=0;
int endd=209;
void inivis(){
	for (int i=0;i<210;i++){
		vis[i]=-1;
	}
}
void finpath(){
	queue<int>q;
	q.push(sta);
	int s;
	while (!q.empty()){
		s=q.size();
		for (int i=0;i<s;i++){
			for (int j=0;j<210;j++){
				if (vis[j]==-1&&flow[q.front()][j]>0){
					vis[j]=q.front();
					q.push(j);
				}
			}
			if (vis[endd]!=-1)break;
			q.pop();
		}
		if (vis[endd]!=-1)break;
	}
}
int maxflow(){
	int ret=0;
	while (1<2){
		inivis();
		finpath();
		vector<int>path;
		path.clear();
		int cut=(1<<30);
		if (vis[endd]!=-1){
			int x=endd;
			path.push_back(x);
			while (x!=sta){
				x=vis[x];
				cut=min(cut,flow[x][path[path.size()-1]]);
				path.push_back(x);
			}
		}
		else break;
		ret+=cut;
		for (int i=path.size()-1;i>0;i--){
			flow[path[i]][path[i-1]]-=cut;
			flow[path[i-1]][path[i]]+=cut;
		}
	}
	return ret;
}
void rezero(){
	for (int i=0;i<105;i++){
		for (int j=0;j<105;j++){
			haus[i][j]=0;
		}
		boyhaus[i].clear();
		boygun[i].clear();
	}
	for (int i=0;i<210;i++){
		for (int j=0;j<210;j++){
			flow[i][j]=0;
		}
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n,m,w;
		scanf("%d%d%d",&n,&m,&w);
		rezero();
		int a,b;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			for (int j=0;j<a;j++){
				scanf("%d",&b);
				boyhaus[i].push_back(b);
			}
		}
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			for (int j=0;j<a;j++){
				scanf("%d",&b);
				boygun[i].push_back(b);
			}
		}
		for (int i=0;i<m;i++){
			scanf("%d",&a);
			for (int j=0;j<a;j++){
				scanf("%d",&b);
				haus[i+1][b]=1;
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<boyhaus[i].size();j++){
				for (int k=0;k<boygun[i].size();k++){
					if (haus[ boyhaus[i][j] ][ boygun[i][k] ]==1 ){
						flow[i+1][boyhaus[i][j]+100]=1;
						break;
					}
				}
			}
		}
		for (int i=0;i<n;i++){
			flow[sta][i+1]=1;
		}
		for (int i=0;i<m;i++){
			flow[101+i][endd]=1;
		}
		printf ("%d\n",maxflow());
	}
}