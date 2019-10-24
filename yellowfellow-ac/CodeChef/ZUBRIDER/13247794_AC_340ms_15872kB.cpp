#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc,kas=1;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		k*=n;
		cin>>n;
		int ar[n];
		int br[n];
		for (int i=0;i<n;i++)
			cin>>ar[i];
		for (int i=0;i<n;i++)
			cin>>br[i];
		sort(ar,ar+n);
		sort(br,br+n);
		int ptr=n-1;
		long long int way=1;
		for (int i=0;i<n;i++){
			while (ptr-1>=0 && ar[i]*br[ptr-1]>k){
				ptr--;
			}
			if (ar[i]*br[ptr]<=k){
				way=0;
				break;
			}
			way*=(n-i-ptr);
			way%=1000000007;
		}
		printf ("Case %d: %lld\n",kas++,way);
	}
}