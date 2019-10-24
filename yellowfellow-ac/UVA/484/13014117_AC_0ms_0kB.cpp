#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	map<int,int>ma;
	queue<int>ord;
	while (scanf("%d",&n)!=EOF){
		if (ma[n]==0){
			ord.push(n);
		}
		ma[n]++;
	}
	while (!ord.empty()){
		printf ("%d %d\n",ord.front(),ma[ord.front()]);
		ord.pop();
	}
}