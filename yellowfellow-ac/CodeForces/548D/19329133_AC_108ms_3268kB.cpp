#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	int ar[n+1];
	int best[n];
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
		best[i]=0;
	}
	ar[n]=0;
	stack<pair<int,int> >st;
	st.push(pair<int,int>(0,-1));
	int cur=0;
	for (int i=0;i<=n;i++){
		while (!st.empty()&&st.top().first>ar[i]){
			int y=st.top().first;
			st.pop();
			int l=st.top().second+1;
			best[i-l-1]=max(best[i-l-1],y);
		}
		st.push(pair<int,int>(ar[i],i));
	}
	for (int i=n-2;i>=0;i--){
		best[i]=max(best[i],best[i+1]);
	}
	for (int i=0;i<n;i++){
		printf ("%d ",best[i]);
	}
	printf ("\n");
}