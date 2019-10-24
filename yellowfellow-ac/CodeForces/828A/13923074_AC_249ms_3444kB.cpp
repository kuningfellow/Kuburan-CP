#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,a,b;
	cin>>n>>a>>b;
	int x;
	int cnt=0;
	int ones=0;
	for (int i=0;i<n;i++){
		cin>>x;
		if (x==1){
			if (a>0){
				a--;
			}
			else if (b>0){
				b--;
				ones++;
			}
			else if (ones>0){
				ones--;
			}
			else{
				cnt++;
			}
		}
		else{
			if (b>0){
				b--;
			}
			else{
				cnt+=2;
			}
		}
	}
	printf ("%d\n",cnt);
}