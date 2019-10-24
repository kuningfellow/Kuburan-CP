//UVA 1121 Subsequence
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int ar[N];
int main(){
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF){
		int ans=n+1;
		int l=0;
		int sum=0;
		for (int i=0;i<n;i++){
			scanf("%d",ar+i);
			sum+=*(ar+i);
			while(sum-ar[l]>=m)sum-=ar[l++];
			if (sum>=m)ans=min(ans,i-l+1);
		}
		if (ans>n)printf ("0\n");
		else printf ("%d\n",ans);
	}
}