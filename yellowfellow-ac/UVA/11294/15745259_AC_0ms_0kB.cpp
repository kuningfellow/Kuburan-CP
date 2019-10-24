//UVA 11294 Wedding
#include<bits/stdc++.h>
using namespace std;
int conf[65];
vector<int>lis[2][120];
int vis[120];
stack<int>kstack[2];
int val;
void dfs(int x, int m, int id){
	vis[x]=id;
	for (int i=0;i<lis[m][x].size();i++){
		if (vis[lis[m][x][i]]==0){
			dfs(lis[m][x][i],m,id);
		}
	}
	kstack[m].push(x);
}
void kosaraju(int n){
	for (int i=0;i<n;i++){
		conf[i/2]=-1;
		vis[i]=0;
	}
	for (int i=0;i<n;i++){
		if (vis[i]==0){
			dfs(i,0,1);
		}
	}
	for (int i=0;i<n;i++){
		vis[i]=0;
	}
	int id=1;
	while (!kstack[0].empty()){
		int v=kstack[0].top();
		kstack[0].pop();
		if (vis[v]!=0)continue;
		dfs(v,1,id++);
		while (!kstack[1].empty()){
			int u=kstack[1].top();
			kstack[1].pop();
			if (vis[u]==vis[u^1]){
				val=0;
			}
			if (conf[u/2]==-1){
				conf[u/2]=(u&1)>0?0:1;
			}
		}
	}
}
pair<int,int> parse(){
	char str[50];
	scanf("%s",str);
	int l=strlen(str);
	int sec=0;
	int fir=0;
	for (int i=0;i<l;i++){
		if (str[i]>='0'&&str[i]<='9'){
			fir=fir*10+str[i]-'0';
		}
		else if (str[i]=='w'){
			sec=1;
		}
	}
	return pair<int,int>(fir,sec);
}
int main(){
	while (1<2){
		val=1;
		int n,m;
		cin>>n>>m;
		if (n==0&&m==0)break;
		for (int i=0;i<n*4;i++){
			lis[0][i].clear();
			lis[1][i].clear();
		}
		lis[0][1].push_back(0);
		lis[0][n*2].push_back(n*2+1);
		lis[1][0].push_back(1);
		lis[1][n*2+1].push_back(n*2);
		for (int i=0;i<n;i++){
			lis[0][i*2].push_back(((i+n)*2)^1);
			lis[0][((i+n)*2)].push_back(i*2+1);
			
			lis[1][((i+n)*2)^1].push_back(i*2);
			lis[1][i*2+1].push_back((i+n)*2);
			
			lis[0][((i+n)*2)^1].push_back(i*2);
			lis[0][i*2+1].push_back((i+n)*2);
			
			lis[1][i*2].push_back(((i+n)*2)^1);
			lis[1][((i+n)*2)].push_back(i*2+1);
		}
		for (int i=0;i<m;i++){
			pair<int,int> r=parse();
			int a=(r.first+r.second*n)*2;
			r=parse();
			int b=(r.first+r.second*n)*2;
			lis[0][a].push_back(b^1);
			lis[0][b].push_back(a^1);
			lis[1][b^1].push_back(a);
			lis[1][a^1].push_back(b);
		}
		kosaraju(n*4);
		if (val==0){
			printf ("bad luck\n");
		}
		else{
			vector<int>ans;
			for (int i=0;i<n*4;i+=2){
				if (conf[i/2]==1){
					if (i/2==n)continue;
					ans.push_back(i/2);
				}
			}
			for (int i=0;i<ans.size();i++){
				if (i>0)printf (" ");
				int shift=ans[i]>=n?1:0;
				printf ("%d%c",ans[i]-shift*n,'h'+15*shift);
			}
			printf ("\n");
		}
	}
}