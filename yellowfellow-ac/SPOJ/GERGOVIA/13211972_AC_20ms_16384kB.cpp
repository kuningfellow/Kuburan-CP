#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		long long int ar[n];
		for (int i=0;i<n;i++){
			scanf("%lld",&ar[i]);
		}
		long long int cost=0;
		long long int car=0;
		for (int i=0;i<n;i++){
			cost+=max(car,-car);
			ar[i]+=car;
			car=ar[i];
		}
		printf ("%lld\n",cost);
	}
}