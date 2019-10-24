#include<bits/stdc++.h>
using namespace std;
int cost[26][26];
char rem[1000005];
int main(){
	for (int i=0;i<26;i++){
		for (int j=0;j<26;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	for (int i=0;i<26;i++){
		for (int j=0;j<26;j++){
			for (int k=0;k<26;k++){
				cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
			}
		}
	}
	for (int i=0;i<26;i++){
		cost[i][i]=0;
	}
	scanf("%s",rem);
	int l=strlen(rem);
	int mid=l/2;
	long long int ans=0;
	for (int i=0;i<mid;i++){
		long long int temp=(-1)^(1ll<<63);
		if (rem[i]==rem[l-1-i])continue;
		for (int j=0;j<26;j++){
			temp =min(temp, (long long)cost[rem[i]-'a'][j]+cost[rem[l-1-i]-'a'][j]);
		}
		ans+=temp;
	}
	printf ("%lld\n",ans);
}