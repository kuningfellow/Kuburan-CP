#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc,kas=1;
	scanf("%d",&tc);
	while(tc--){
		int n,k;
		scanf("%d%d",&n,&k);
		k*=n;
		scanf("%d",&n);
		int ar[n];
		int br[n];
		for (int i=0;i<n;i++)
			scanf("%d",&ar[i]);
		for (int i=0;i<n;i++)
			scanf("%d",&br[i]);
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