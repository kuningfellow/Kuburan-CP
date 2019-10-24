#include<bits/stdc++.h>
using namespace std;
	
int l,k;

//0 hitam 1 putih

long long memo[3][105];

long long dp(int leng, int now){
	if(leng == 0 && now == 1) return 1;
	if(leng == 0 ) return 0;
	if(memo[now][leng]!=-1) return memo[now][leng];
	long long has = 0 ;
	if(leng != l && now == 1) has = 1; 
	has += dp(leng -1 , now^1);
	if(now == 0 && leng >= k) {
		has += dp(leng-k,now^1);
	}
	return memo[now][leng] = has ;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d%d",&l,&k);
	printf("%lld\n",dp(l,0));
	return 0;
}