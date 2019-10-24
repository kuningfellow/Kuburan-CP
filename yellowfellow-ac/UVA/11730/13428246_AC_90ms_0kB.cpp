#include <bits/stdc++.h>
using namespace std;
bool isprime[5005];
void sieve(){
	for (int i=2;i<5005;i++){
		for (int j=i*2;j<5005;j+=i){
			isprime[j]=1;
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	sieve();
	int kas=1;
	while (1<2){
		int n,m;
		cin>>n>>m;
		if (n==0&&m==0)break;
		int cap=max(n,m);
		int vis[cap+1];
		int cost[cap+1];
		for (int i=0;i<=cap;i++){
			vis[i]=0;
			cost[i]=(1<<27);
		}
		cost[n]=0;
		queue<int>q;
		q.push(n);
		while (!q.empty()){
			int siz=q.size();
			for (int j=0;j<siz;j++){
				int p=q.front();
				q.pop();
				vis[p]=1;
				for (int i=2;i<p;i++){
					if (p+i<=m&&isprime[i]==0&&p%i==0&&vis[p+i]==0){
						cost[p+i]=min(cost[p+i],cost[p]+1);
						q.push(p+i);
					}
				}
			}
		}
		printf ("Case %d: ",kas++);
		if (vis[m]==0){
			printf ("-1\n");
		}
		else printf ("%d\n",cost[m]);
	}
}