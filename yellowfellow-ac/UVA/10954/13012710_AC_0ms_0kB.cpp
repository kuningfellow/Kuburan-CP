#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		priority_queue<int>q;
		int a;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			q.push(-a);
		}
		int rem,ram;
		int cost=0;
		while (q.size()>1){
			rem=q.top();
			q.pop();
			ram=q.top();
			q.pop();
			cost+=-(ram+rem);
			q.push(ram+rem);
		}
		printf ("%d\n",cost);
	}
}