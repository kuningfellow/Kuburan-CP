#include<bits/stdc++.h>
#define GOD(x) int x;scanf("%d",&x);
using namespace std;
int main(){
	GOD(n);
	GOD(k);
	priority_queue<int>pq;
	for (int i=0;i<n;i++){
		GOD(a);
		pq.push(a);
	}
	int mini=(1<<30);
	while (k>0&&!pq.empty()){
		mini=min(mini,pq.top());
		pq.pop();
		k--;
	}
	if (k==0){
		printf ("%d %d\n",mini,mini);
	}
	else printf ("-1\n");
}