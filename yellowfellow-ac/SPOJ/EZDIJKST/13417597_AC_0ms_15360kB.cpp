#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int v,k;
		scanf("%d%d",&v,&k);
		int cost[v];
		int visit[v];
		vector<pair<int,int> >adj[v];
		for (int i=0;i<v;i++){
			cost[i]=(1<<29);
			visit[i]=0;
		}
		for (int i=0;i<k;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--;
			b--;
			adj[a].push_back(pair<int,int>(b,c));
		}
		int s,e;
		scanf("%d%d",&s,&e);
		s--;
		e--;
		cost[s]=0;
		priority_queue<pair<int,int> >pq;
		pq.push(pair<int,int>(0,s));
		while (!pq.empty()){
			while (!pq.empty()&&visit[pq.top().second]==1){
				pq.pop();
			}
			if (!pq.empty()){
				int p=pq.top().second;
				pq.pop();
				visit[p]=1;
				for (int i=0;i<adj[p].size();i++){
					cost[adj[p][i].first]=min(cost[adj[p][i].first],cost[p]+adj[p][i].second);
					if (visit[adj[p][i].first]==0){
						pq.push(pair<int,int>(-cost[adj[p][i].first],adj[p][i].first));
					}
				}
			}
		}
		if (visit[e]==0){
			printf ("NO\n");
		}
		else printf ("%d\n",cost[e]);
	}
}