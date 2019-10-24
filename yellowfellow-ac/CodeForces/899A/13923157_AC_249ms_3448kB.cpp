#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int x;
	int a=0;
	int b=0;
	for (int i=0;i<n;i++){
		cin>>x;
		if (x==1)a++;
		else b++;
	}
	int cnt=0;
	int del=min(a,b);
	cnt+=del;
	a-=del;
	cnt+=a/3;
	printf ("%d\n",cnt);
}