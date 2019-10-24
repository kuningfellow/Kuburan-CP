#include <bits/stdc++.h>
using namespace std;
int ar[5000];
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n,v;
	cin>>n>>v;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		ar[a]+=b;
	}
	int take=0;
	for (int i=1;i<=3001;i++){
		int ve=v;
		if (i>1){
			if (ar[i-1]>0){
				int tmp=min(ve,ar[i-1]);
				ar[i-1]-=tmp;
				ve-=tmp;
			}
		}
		if (ar[i]>0){
			int tmp=min(ve,ar[i]);
			ar[i]-=tmp;
			ve-=tmp;
		}
		take+=v-ve;
	}
	printf ("%d\n",take);
}