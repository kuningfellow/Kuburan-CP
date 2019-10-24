#include <bits/stdc++.h>
using namespace std;
int x,y,p;
int flow[2000][2000];
int vis[2000];
int siz=0;
int source, sink;
int conv(char a){
	if (a=='.')
		return 1;
	if (a=='@')
		return (1<<28);
	if (a=='#')
		return (1<<28);
	if (a=='*')
		return 1;
	if (a=='~')
		return 0;
}
int ford(int c, int mini){
	vis[c]=1;
	if (c==sink){
		return mini;
	}
	for (int i=0;i<siz;i++){
		if (flow[c][i]>0&&vis[i]==0){
			int ret=ford(i,min(mini,flow[c][i]));
			flow[c][i]-=ret;
			flow[i][c]+=ret;
			if (ret!=0)
				return ret;
		}
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	while (scanf("%d%d%d",&x,&y,&p)!=EOF){
		char rem[x][y+1];
		for (int i=0;i<x;i++){
			scanf("%s",rem[i]);
		}
		for (int i=0;i<2000;i++){
			for (int j=0;j<2000;j++){
				flow[i][j]=0;
			}
		}
		source=0;
		siz=x*y;
		sink=siz*2+1;
		for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				int a=i+x*j+1;
				int b=a+siz;
				flow[a][b]=conv(rem[i][j]);
				if (rem[i][j]=='#'){
					flow[b][sink]=p;
				}
				if (rem[i][j]=='*'){
					flow[source][a]=1;
				}
				int c;
				if (i+1<x){
					c=i+1+x*j+1;
					flow[b][c]=(1<<28);
				}
				if (i-1>=0){
					c=i-1+x*j+1;
					flow[b][c]=(1<<28);
				}
				if (j+1<y){
					c=i+x*(j+1)+1;
					flow[b][c]=(1<<28);
				}
				if (j-1>=0){
					c=i+x*(j-1)+1;
					flow[b][c]=(1<<28);
				}
			}
		}
		siz=sink+1;
		int sum=0;
		int temp;
		while (1<2){
			for (int i=0;i<2000;i++){
				vis[i]=0;
			}
			temp=ford(source,(1<<28));
			if (temp==0)break;
			sum+=temp;
		}
		printf ("%d\n",sum);
	}
}