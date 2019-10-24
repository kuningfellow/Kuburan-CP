#include <bits/stdc++.h>
using namespace std;
#define sf second.first
#define ss second.second
pair<int,pair<int,int> >makk(int a, int b, int c){
	return pair<int,pair<int,int> >(a, pair<int,int>(b,c));
}
int cost[1005][1200];
int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> >lis[n];
	for (int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		lis[a-1].push_back(pair<int,int>(b-1,c));
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<=n;j++){
			cost[i][j]=(1<<28);
		}
	}
	priority_queue<pair<int,pair<int,int> > >pq;
	pq.push(makk(0,0,0));
	while (!pq.empty()){
		if (cost[pq.top().sf][pq.top().ss]!=(1<<28)){
			pq.pop();
			continue;
		}
		cost[pq.top().sf][pq.top().ss]=-pq.top().first;
		int x=pq.top().sf;
		int y=pq.top().ss;
		int co=pq.top().first;
		for (int i=0;i<lis[x].size();i++){
			if (y+1<=n&&cost[lis[x][i].first][y+1]==(1<<28)){
				pq.push(makk(co-lis[x][i].second, lis[x][i].first, y+1));
			}
		}
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y++;
		int mini=(1<<28);
		for (int j=0;j<=y;j++){
			mini=min(mini,cost[x][j]);
		}
		if (mini==(1<<28)){
			printf ("=[\n");
		}
		else printf ("=] %d\n",mini);
	}
	
}