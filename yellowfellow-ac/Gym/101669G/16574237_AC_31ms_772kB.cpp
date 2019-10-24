#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	priority_queue<pair<double,pair<long long,long long> > >pq;
	long long d=0;
	long long sisad=0;
	long long v=0;
	for(int i=0;i<n;i++){
		long long a,t;
		scanf("%lld %lld",&a,&t);
		d+=a*t*t+v*t*2;
		v+=a*t;
		pq.push(make_pair((double)a,make_pair(a,t)));	
	}
	long long dd=0;
	long long sisadd=0;
	long long vv=0;
	while(!pq.empty()){
		long long a,t;
		a=pq.top().second.first;
		t=pq.top().second.second;
		pq.pop();
		dd+=a*t*t+vv*t*2;
		vv+=a*t;
	}
	double ans=dd-d;
	ans/=2;
	printf("%.1lf\n",ans);
}