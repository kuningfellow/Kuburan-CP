#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
vector<int>con[4005];
int low[4005];
int num[4005];
int vis[4005];
int check[4005];
int gc;
int yes;
stack<int>st;
int phase;
int n;
void tarjan(int x){
	num[x]=low[x]=gc++;
	vis[x]=1;
	st.push(x);
	for (int i=0;i<con[x].size();i++){
		if (num[con[x][i]]==-1){
			tarjan(con[x][i]);
		}
		if (vis[con[x][i]]==1){
			low[x]=min(low[x],low[con[x][i]]);
		}
	}
	if (low[x]==num[x]){
		phase++;
		while (1<2){
			int v=st.top();
			st.pop();
			check[v]=phase;
			if (v>=n&&check[v-n]==phase){
				yes=0;
			}
			else if (v<n&&check[v+n]==phase){
				yes=0;
			}
			vis[v]=0;
			if(v==x) break;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	scanf("%d",&tc);
	int kas=1;
	while (tc--){
		phase=0;
		yes=1;
		gc=0;
		int m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<4005;i++){
			con[i].clear();
			vis[i]=0;
			check[i]=0;
			low[i]=-1;
			num[i]=-1;
		}
		for (int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			con[a].push_back(b+n);
			con[a+n].push_back(b);
			con[b].push_back(a+n);
			con[b+n].push_back(a);
		}
		for (int i=0;i<n*2;i++){
			if (num[i]==-1){
				tarjan(i);
			}
		}
		if (kas>1)printf ("\n");
		printf ("Scenario #%d:\n",kas++);
		if (yes==0){
			printf ("Suspicious bugs found!\n");
		}
		else printf ("No suspicious bugs found!\n");
	}
}