#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<LL,int>cor;
LL ar[100005];
LL maxi[100005];
LL mini[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&ar[i]);
	}
	maxi[0]=(1ll<<63);
	mini[n-1]=(-1)^(1ll<<63);
	for(int i=1;i<n;i++){
		maxi[i]=max(maxi[i-1],ar[i-1]);
	}
	for (int i=n-2;i>=0;i--){
		mini[i]=min(mini[i+1],ar[i+1]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if (mini[i]>ar[i]&&maxi[i]<ar[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
}