#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int>pq;
	int n,k;
	cin>>n>>k;
	int a,b;
	for (int i=0;i<n;i++){
		cin>>a;
		pq.push(-a);
	}
	int ye=0;
	int c=0;
	while (1<2){
		if (-pq.top()>=k){
			ye=1;
			break;
		}
		if (pq.size()<2)break;
		a=pq.top();
		pq.pop();
		b=2*pq.top();
		pq.pop();
		pq.push(a+b);
		c++;
	}
	int ans=c;
	if (ye==0)ans=-1;
	printf ("%d\n",ans);
}