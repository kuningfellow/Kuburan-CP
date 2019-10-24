#include <bits/stdc++.h>
using namespace std;
vector<int>con[205],nlist[205],comp[205],dag;
int num[205],low[205],take[205],vis[205],color[205];
int lv,phase;
stack<int>st;
int yes;
void tarjan(int x){
	vis[x]=1;
	num[x]=low[x]=lv++;
	st.push(x);
	for (int i=0;i<con[x].size();i++){
		if (num[con[x][i]]==-1)tarjan(con[x][i]);
		if (vis[con[x][i]]==1)low[x]=min(low[x],low[con[x][i]]);
	}
	if (num[x]==low[x]){
		phase++;
		dag.push_back(x);
		while (1<2){
			int v=st.top();
			st.pop();
			vis[v]=0;
			low[v]=x;
			if (take[v^1]==phase)yes=0;
			take[v]=phase;
			if (v==x)break;
		}
	}
}
void ngraph(int n){
	for (int i=0;i<n*2;i++){
		take[i]=0;
		color[i]=-1;
	}
	for (int i=0;i<n*2;i++){
		int a=low[i];
		comp[a].push_back(i);
		for (int j=0;j<con[i].size();j++){
			int b=low[con[i][j]];
			if (a==b)continue;
			nlist[b].push_back(a);
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
				int tog=0;
				if (p%2==1){
					tog=1;
					p^=1;
				}
				if (color[p]!=-1&&color[p]^tog==0){
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
			for (int j=0;j<nlist[v].size();j++){
				take[nlist[v][j]]--;
				if (take[nlist[v][j]]==0){
					q.push(pair<int,int>(nlist[v][j],col));
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
	vector<pair<int,int> >lis;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if (a>b){
			int temp=a;
			a=b;
			b=temp;
		}
		lis.push_back(pair<int,int>(a,b));
	}
	for (int i=0;i<m*2;i++){
		num[i]=-1;
	}
	for (int i=0;i<m-1;i++){
		for (int j=i;j<m;j++){
			int intersect=0;
			if (lis[i].first<lis[j].first&&lis[j].first<lis[i].second&&lis[j].first<lis[i].second&&lis[i].second<lis[j].second)intersect=1;
			if (lis[j].first<lis[i].first&&lis[i].first<lis[j].second&&lis[i].first<lis[j].second&&lis[j].second<lis[i].second)intersect=1;
			if (intersect){
				int a=i*2;
				int b=j*2;
				con[a].push_back(b^1);
				con[b].push_back(a^1);
				con[a^1].push_back(b);
				con[b^1].push_back(a);
			}
		}
	}
	for (int i=0;i<m*2;i++){
		if (num[i]==-1){
			tarjan(i);
		}
	}
	if (yes==0){
		printf ("Impossible\n");
		return 0;
	}
	ngraph(m);
	bfs();
	for (int i=0;i<m;i++){
		if (color[i*2]==1){
			printf ("i");
		}
		else printf ("o");
	}
	printf ("\n");
}