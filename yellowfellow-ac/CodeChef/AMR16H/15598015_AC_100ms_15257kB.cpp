#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int ans=0;
		long long int temp=0;
		int n;
		cin>>n;
		priority_queue<int>pq;
		for (int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			pq.push(a);
		}
		int maxi=pq.top();
		pq.pop();
		while (!pq.empty()){
			temp+=pq.top();
			pq.pop();
			ans+=temp;
		}
		temp+=maxi;
		ans+=temp;
		printf ("%lld\n",ans);
	}
}