#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int res;
void serc(long long int x, int a, int b){
	if (a>=15||b>=15)return;
	if (x>=n&&a==b){
		res=min(res,x);
		return;
	}
	serc((long long)x*10+4,a+1,b);
	serc((long long)x*10+7,a,b+1);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	res=(1ll<<62);
	serc(0,0,0);
	printf ("%lld\n",res);
}