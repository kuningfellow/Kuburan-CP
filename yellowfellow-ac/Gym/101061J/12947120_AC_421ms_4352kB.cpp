#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		long long int n,m;
		scanf("%lld%lld",&n,&m);
		long long int cap[n];
		long long int fil[n];
		long long int edit[n];
		for (int i=0;i<n;i++){
			scanf("%lld",&cap[i]);
			fil[i]=0;
			edit[i]=0;
		}
		int x;
		long long int y;
		for (int i=0;i<m;i++){
			scanf("%d%lld",&x,&y);
			edit[x-1]+=y;
		}
		long long int red;
		long long int car=0;
		for (int i=0;i<n;i++){
			red=min(cap[i]-fil[i],edit[i]+car);
			fil[i]+=red;
			edit[i]-=red;
			car+=edit[i];
		}
		printf ("%lld\n",car);
		for (int i=0;i<n;i++){
			printf ("%lld",fil[i]);
			if (i<n-1)printf (" ");
		}
		printf ("\n");
	}
}