#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int par[n*2];
	for (int i=0;i<n*2;i++){
		par[i]=-1;
	}
	priority_queue<pair<int,pair<int,int> > >pq;
	for (int i=0;i<n*2-1;i++){
		for (int j=0;j<i+1;j++){
			int a;
			cin>>a;
			pq.push(pair<int,pair<int,int> >(a,pair<int,int>(i+1,j)));
		}
	}
	while (!pq.empty()){
		if (par[pq.top().second.first]==-1&&par[pq.top().second.second]==-1){
			par[pq.top().second.first]=pq.top().second.second;
			par[pq.top().second.second]=pq.top().second.first;
		}
		pq.pop();
	}
	for (int i=0;i<2*n;i++){
		printf ("%d ",par[i]+1);
	}
}