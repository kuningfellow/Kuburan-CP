#include <bits/stdc++.h>
using namespace std;
int main(){
	map<int,int>del;
	priority_queue<int>pq;
	int n,a,b;
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",&a);
		if (a==1){
			scanf("%d",&b);
			pq.push(-b);
			del[-b]=1;
		}
		else if (a==2){
			scanf("%d",&b);
			del[-b]=0;
		}
		else{
			while (!pq.empty()&&del[pq.top()]==0){
				pq.pop();
			}
			printf ("%d\n",-pq.top());
		}
	}
}