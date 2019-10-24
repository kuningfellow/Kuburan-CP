#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int ar[5];
		for (int i=0;i<5;i++){
			cin>>ar[i];
		}
		sort(ar,ar+5);
		printf ("%d\n",ar[4]*ar[3]);
	}
}