#include <bits/stdc++.h>
using namespace std;
int k;
int take[26];
int trace[35];
int n;
void rec(int x){
	if (k==0){
		return;
	}
	if (x==n){
		for (int i=0;i<n;i++){
			printf ("%c",trace[i]+'A');
		}
		printf ("\n");
		k--;
		return;
	}
	for (int i=0;i<n;i++){
		if (take[i]==0){
			take[i]=1;
			trace[x]=i;
			rec(x+1);
			take[i]=0;
			if (k==0)break;
		}
	}
	return;
}
int main(){
	int tc,kas=1;
	cin>>tc;
	while (tc--){
		cin>>n>>k;
		printf ("Case %d:\n",kas++);
		rec(0);
	}
}