#include <bits/stdc++.h>
using namespace std;
int flow[205][205];
double dist(int x1,int y1, int x2, int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int n;
int vis[205];
int bac[205];
void bfs(){
	for (int i=0;i<n*2+2;i++){
		vis[i]=0;
	}
	queue<int>q;
	q.push(0);
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			for (int j=0;j<n*2+2;j++){
				if (flow[q.front()][j]>0&&vis[j]==0){
					vis[j]=1;
					bac[j]=q.front();
					q.push(j);
				}
			}
			q.pop();
		}
	}
}
int maxflow(){
	int ret=0;
	while (1<2){
		bfs();
		if (vis[n*2+1]==0)break;
		for (int i=0;i<n*2+2;i++){
			vis[i]=0;
		}
		int pos=n*2+1,maxi=(1<<28);
		while (pos!=0){
			maxi=min(maxi,flow[bac[pos]][pos]);
			pos=bac[pos];
		}
		pos=n*2+1;
		while (pos!=0){
			flow[bac[pos]][pos]-=maxi;
			flow[pos][bac[pos]]+=maxi;
			pos=bac[pos];
		}
		ret+=maxi;
	}
	return ret;
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int coun=0;
		double D;
		cin>>n>>D;
		int ar[n][4];
		for (int i=0;i<n;i++){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			ar[i][0]=a;
			ar[i][1]=b;
			ar[i][2]=c;
			ar[i][3]=d;
			coun+=c;
		}
		vector<int>lis;
		for (int k=0;k<n;k++){
			for (int i=0;i<n*2+2;i++){
				for (int j=0;j<n*2+2;j++){
					flow[i][j]=0;
				}
			}
			for (int i=0;i<n;i++){
				flow[0][i+1]=ar[i][2];
				flow[i+1][i+1+n]=ar[i][3];
				if (i==k){
					flow[i+1][n*2+1]=(1<<28);
				}
			}
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (D>=dist(ar[i][0],ar[i][1],ar[j][0],ar[j][1])){
						flow[i+1+n][j+1]=(1<<28);
						flow[j+1+n][i+1]=(1<<28);
					}
				}
			}
			if (maxflow()==coun){
				lis.push_back(k);
			}
		}
		if (lis.empty())printf ("-1\n");
		else{
			for (int i=0;i<lis.size();i++){
				if (i!=0)printf (" ");
				printf ("%d",lis[i]);
			}
			printf ("\n");
		}
	}
}