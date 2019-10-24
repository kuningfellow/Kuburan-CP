#include <bits/stdc++.h>
using namespace std;
vector<int>con[150];
int num[150],low[150],vis[150],take[150];
int lv,phase,yes;
stack<int>st;
int tarjan(int x){
	vis[x]=1;
	num[x]=low[x]=lv++;
	st.push(x);
	for (int i=0;i<con[x].size();i++){
		if (num[con[x][i]]==-1)tarjan(con[x][i]);
		if (vis[con[x][i]]==1)low[x]=min(low[x],low[con[x][i]]);
	}
	if (num[x]==low[x]){
		phase++;
		while (1<2){
			int v=st.top();
			st.pop();
			if (take[v^1]==phase)yes=0;
			take[v]=phase;
			vis[v]=0;
			if (x==v)break;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tc;
	cin>>tc;
	while (tc--){
		int n,m,q;
		cin>>n>>m>>q;
		phase=0;
		lv=0;
		yes=1;
		for (int i=0;i<(n+m)*2;i++){
			num[i]=-1;
			vis[i]=0;
			con[i].clear();
			take[i]=0;
		}
		for (int i=0;i<q;i++){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			a=(a-1)*2;
			b=(b-1+n)*2;
			c=(c-1)*2;
			d=(d-1+n)*2;
			if (a==c&&b==d)continue;
			if (a==c){
				if (b>d)a^=1;
				con[a^1].push_back(a);
			}
			else if (b==d){
				if (a>c)b^=1;
				con[b^1].push_back(b);
			}
			else{
				if (a>c){
					b^=1;
					d^=1;
				}
				if (b>d){
					a^=1;
					c^=1;
				}
				con[a^1].push_back(c);
				con[c^1].push_back(a);
				con[a^1].push_back(b);
				con[b^1].push_back(a);
				con[c^1].push_back(d);
				con[d^1].push_back(c);
				con[b^1].push_back(d);
				con[d^1].push_back(b);
			}
		}
		for (int i=0;i<(n+m)*2;i++){
			if (num[i]==-1){
				tarjan(i);
			}
		}
		if (yes==1)printf ("Yes\n");
		else printf ("No\n");
	}
}