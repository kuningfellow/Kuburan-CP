#include <bits/stdc++.h>
using namespace std;
int flow[105][105];
int vis[105];
int sta,ende;
int n;
void bfs(){
	for (int i=0;i<n;i++){
		vis[i]=-1;
	}
	queue<int>q;
	q.push(sta);
	int done=1;
	while (!q.empty()&&done){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			for (int j=0;j<n;j++){
				if (vis[j]==-1&&flow[q.front()][j]>0){
					vis[j]=q.front();
					q.push(j);
					if (j==ende){
						done=0;
						break;
					}
				}
			}
			q.pop();
			if (done==0)break;
		}
		if (done==0)break;
	}
	while (!q.empty()){
		q.pop();
	}
}
int max_flow(){
	int ret=0;
	while (1<2){
		bfs();
		if (vis[ende]==-1){
			break;
		}
		int maxi=(1<<28);
		int pos=ende;
		while (pos!=sta){
			maxi=min(maxi,flow[vis[pos]][pos]);
			pos=vis[pos];
		}
		pos=ende;
		while (pos!=sta){
			flow[vis[pos]][pos]-=maxi;
			flow[pos][vis[pos]]+=maxi;
			pos=vis[pos];
		}
		ret+=maxi;
	}
	return ret;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int kas=1;
	while (1<2){
		cin>>n;
		if (n==0)break;
		int ed;
		cin>>sta>>ende>>ed;
		sta--;
		ende--;
		int a,b,c;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				flow[i][j]=0;
			}
		}
		for (int i=0;i<ed;i++){
			cin>>a>>b>>c;
			a--;
			b--;
			flow[a][b]+=c;
			flow[b][a]+=c;
		}
		printf ("Network %d\nThe bandwidth is %d.\n\n",kas++,max_flow());
	}
}