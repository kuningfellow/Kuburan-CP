#include <bits/stdc++.h>
using namespace std;
vector<int>lis[205];
int col[205];
int n;
int yes=1;
void dfs(int x , int c){
	col[x]=c;
	for (int i=0;i<lis[x].size();i++){
		if (col[lis[x][i]]==col[x]){
			yes=0;
			break;
		}
		if (col[lis[x][i]]==-1){
			dfs(lis[x][i],c^1);
		}
	}
}
int main(){
	while (1<2){
		int k;
		cin>>n;
		if (n==0)break;
		cin>>k;
		for (int i=0;i<n;i++){
			lis[i].clear();
			col[i]=-1;
		}
		int a,b;
		yes=1;
		for (int i=0;i<k;i++){
			cin>>a>>b;
			lis[a].push_back(b);
			lis[b].push_back(a);
		}
		for (int i=0;i<n;i++){
			if (col[i]==-1){
				dfs(i,0);
				if (yes==0)break;
			}
		}
		if (yes==1)printf ("BICOLORABLE.\n");
		else printf ("NOT BICOLORABLE.\n");
	}
}