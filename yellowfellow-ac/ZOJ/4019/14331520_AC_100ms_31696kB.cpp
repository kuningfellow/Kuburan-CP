#include <bits/stdc++.h>
using namespace std;
long long int memo[2005][2005];
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int k1,k2,c;
		cin>>k1>>k2>>c;
		int n,m;
		cin>>n>>m;
		long long int ar[n+1],br[m+1];
		ar[0]=0;
		br[0]=0;
		for (int i=1;i<=n;i++){
			cin>>ar[i];
		}
		for (int i=1;i<=m;i++){
			cin>>br[i];
		}
		sort(ar,ar+n+1);
		sort(br,br+m+1);
		long long int a=0;
		long long int maxi=0;
		for (int i=0;i<=n;i++){
			a+=ar[i];
			long long int b=0;
			for (int j=0;j<=m;j++){
				b+=br[j];
				long long int rem=0;
				if (c-a-b>=0&&j>0){
					rem=k2*(c-a-b)+memo[i][j-1];
				}
				long long int ram=0;
				if (c-a-b>=0&&i>0){
					ram=k1*(c-a-b)+memo[i-1][j];
				}
				memo[i][j]=max(rem,ram);
				maxi=max(maxi,memo[i][j]);
			}
		}
		printf ("%lld\n",maxi);
	}
}