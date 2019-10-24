#include <bits/stdc++.h>
using namespace std;
long long int flow[205][205];
int n;
int bt[205];
int vis[205];
void bfs(){
	queue<int>q;
	q.push(0);
	for (int i=0;i<n*2+2;i++){
		vis[i]=0;
		bt[i]=-1;
	}
	vis[0]=1;
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			for (int j=0;j<n*2+2;j++){
				if (flow[q.front()][j]>0&&vis[j]==0){
					bt[j]=q.front();
					vis[j]=1;
					q.push(j);
				}
			}
			
			q.pop();
		}
	}
}
long long int mf(){
	long long int ret=0;
	while (1<2){
		bfs();
		if (vis[n*2+1]==0){
			break;
		}
		long long int maxi=((1ll)<<60);
		int pos=n*2+1;
		while (pos!=0){
			maxi=min(maxi,flow[bt[pos]][pos]);
			pos=bt[pos];
		}
		ret+=maxi;
		pos=n*2+1;
		while (pos!=0){
			flow[bt[pos]][pos]-=maxi;
			flow[pos][bt[pos]]+=maxi;
			pos=bt[pos];
		}
	}
	return ret;
}
int main(){
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<n*2+2;i++){
			for (int j=0;j<n*2+2;j++){
				flow[i][j]=0;
			}
		}
		for (int i=0;i<n;i++){
			long long int a;
			cin>>a;
			flow[1+i][1+i+n]=a;
		}
		int q,c0;
		cin>>q;
		for (int i=0;i<q;i++){
			int a,b;
			long long int c;
			cin>>a>>b>>c;
			flow[a+n][b]+=c;
		}
		cin>>q>>c0;
		for (int i=0;i<q;i++){
			int a;
			cin>>a;
			flow[0][a]=((1ll)<<60);
		}
		for (int i=0;i<c0;i++){
			int a;
			cin>>a;
			flow[a+n][n*2+1]=((1ll)<<60);
		}
		printf ("%lld\n",mf());
	}
}