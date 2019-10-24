#include <bits/stdc++.h>
using namespace std;
vector<int>con[205],ncon[205],comp[205],dag;
int num[205],low[205],vis[205],take[205];
int color[205];
int lv,phase,yes;
stack<int>st;
void tarjan(int x){
	vis[x]=1;
	num[x]=low[x]=lv++;
	st.push(x);
	for (int i=0;i<con[x].size();i++){
		if (num[con[x][i]]==-1)tarjan(con[x][i]);
		if (vis[con[x][i]]==1)low[x]=min(low[x],low[con[x][i]]);
	}
	if (low[x]==num[x]){
		phase++;
		dag.push_back(x);
		while (1<2){
			int v=st.top();
			st.pop();
			low[v]=x;
			if (take[v^1]==phase)yes=0;
			take[v]=phase;
			if (v==x)break;
		}
	}
}
void ngraph(int n){
	for (int i=0;i<n*2;i++){
		color[i]=-1;
		take[i]=0;
	}
	for (int i=0;i<n*2;i++){
		int a=low[i];
		int b;
		comp[a].push_back(i);
		for (int j=0;j<con[i].size();j++){
			b=low[con[i][j]];
			if (a==b)continue;
			ncon[b].push_back(a);
			take[a]++;
		}
	}
}
void bfs(){
	queue<pair<int,int> >q;
	for (int i=0;i<dag.size();i++){
		if (take[dag[i]]==0){
			q.push(pair<int,int>(dag[i],1));
		}
	}
	while (!q.empty()){
		int siz=q.size();
		for (int i=0;i<siz;i++){
			int v=q.front().first;
			int col=q.front().second;
			q.pop();
			for (int j=0;j<comp[v].size();j++){
				int p=comp[v][j];
				if (p%2==1)p^=1;
				if (color[p]!=-1&&color[p]!=col){
					col=0;
				}
			}
			for (int j=0;j<comp[v].size();j++){
				int p=comp[v][j];
				int tog=0;
				if (p%2==1){
					tog=1;
					p^=1;
				}
				if (color[p]==-1){
					color[p]=col^tog;
				}
			}
			for (int j=0;j<ncon[v].size();j++){
				take[ncon[v][j]]--;
				if (take[ncon[v][j]]==0){
					q.push(pair<int,int>(ncon[v][j],col));
				}
			}
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	yes=1;
	for (int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a=(a-1)*2;
		b=(b-1)*2;
		if (c==0){
			con[a].push_back(b^1);
			con[b].push_back(a^1);
			con[a^1].push_back(b);
			con[b^1].push_back(a);
		}
		else{
			con[b].push_back(a);
			con[a^1].push_back(b^1);
			con[a].push_back(b);
			con[b^1].push_back(a^1);
		}
	}
	for (int i=0;i<n*2;i++){
		num[i]=-1;
		vis[i]=0;
	}
	for (int i=0;i<n*2;i++){
		if (num[i]==-1){
			tarjan(i);
		}
	}
	if (yes==0){
		printf ("Impossible\n");
		return 0;
	}
	ngraph(n);
	bfs();
	vector<int>print;
	for (int i=0;i<n;i++){
		if (color[i*2]==1){
			print.push_back(i);
		}
	}
	printf ("%d\n",print.size());
	for (int i=0;i<print.size();i++){
		if (i!=0)printf (" ");
		printf ("%d",print[i]+1);
	}
	printf ("\n");
}