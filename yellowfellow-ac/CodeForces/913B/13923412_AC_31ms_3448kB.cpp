#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	int ar[n];
	int br[n];
	int cr[n];
	for (int i=0;i<n;i++){
		ar[i]=0;
		cr[i]=0;
	}
	int a;
	for (int i=0;i<n;i++){
		cin>>a;
		ar[a-1]++;
		br[i+1]=a-1;
	}
	for (int i=1;i<n;i++){
		if (ar[i]==0){
			cr[br[i]]++;
		}
	}
	int yes=1;
	for (int i=0;i<n;i++){
		if (ar[i]!=0&&cr[i]<3){
			yes=0;
			break;
		}
	}
	if (yes==1){
		printf ("Yes\n");
	}
	else printf ("No\n");
}