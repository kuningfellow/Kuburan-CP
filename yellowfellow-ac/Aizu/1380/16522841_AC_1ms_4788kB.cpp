#include<bits/stdc++.h>
using namespace std;

long long data[100005],tamb[100005];
long long ans[100005];

int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	long long maxi = -1;
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&data[i]);
		if(maxi < data[i]) maxi = data[i];
		tamb[i] = maxi;
		if(i!=0)data[i]+=data[i-1];
	}
	long long ans = 0;
	for(int i = 0 ; i < n ; i ++){
		ans = (((long long)t+1)-data[i])/tamb[i];
		if(((long long)t+1)-data[i] < 0 ){
			printf("1\n");
			continue;
		}
		ans ++;
		if((((long long)t+1)-data[i])%tamb[i]) ans ++ ;
		printf("%lld\n",ans);
	}
	return 0;
}