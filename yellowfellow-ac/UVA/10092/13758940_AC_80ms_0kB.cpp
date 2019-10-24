#include <bits/stdc++.h>
using namespace std;
int flow[1100][1100];
int vis[1100];
int nk,np;
vector<int>picks[20];
int ford(int x, int maxi){
	vis[x]=1;
	if (x==nk+np+1){
		return maxi;
	}
	for (int i=0;i<nk+np+2;i++){
		if (vis[i]==0&&flow[x][i]>0){
			int ret=ford(i,min(maxi,flow[x][i]));
			if (ret>0){
				flow[x][i]-=ret;
				flow[i][x]+=ret;
				return ret;
			}
		}
	}
	return 0;
}
int main(){
	while (1<2){
		scanf("%d%d",&nk,&np);
		if (nk==0&&np==0)break;
		int sum=0;
		for (int i=0;i<nk+np+2;i++){
			for (int j=0;j<nk+np+2;j++){
				flow[i][j]=0;
			}
		}
		int sink=np+nk+1;
		for (int i=0;i<nk;i++){
			int a;
			cin>>a;
			flow[np+i+1][sink]=a;
			sum+=a;
		}
		for (int i=0;i<np;i++){
			int a;
			cin>>a;
			flow[0][i+1]=1;
			for (int j=0;j<a;j++){
				int b;
				cin>>b;
				flow[i+1][b+np]=1;
			}
		}
		int ans=0;
		while (1<2){
			for (int i=0;i<nk+np+2;i++){
				vis[i]=0;
			}
			int temp=ford(0,(1<<28));
			if (temp==0)break;
			ans+=temp;
		}
		if (ans!=sum){
			printf ("0\n");
		}
		else{
			printf ("1\n");
			for (int i=np+1;i<np+nk+1;i++){
				for (int j=1;j<=np;j++){
					if (flow[i][j]==1){
						printf ("%d ",j);
					}
				}
				printf ("\n");
			}
		}
	}		
}