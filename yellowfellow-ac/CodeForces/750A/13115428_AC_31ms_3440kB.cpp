#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ans;
	int c=0;
	for (int i=0;i<=n;i++){
		if (i*5+c<=240-k){
			ans=i;
		}
		c+=i*5;
	}
	printf ("%d\n",ans);
}