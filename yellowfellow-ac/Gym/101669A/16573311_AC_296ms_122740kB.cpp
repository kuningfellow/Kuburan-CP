#include<bits/stdc++.h>
using namespace std;
int n,k;
int data[27];
string need,raw;
#define MOD 1000000007

int memo[301][100001];

int dp(int ka,int en){
	if(ka == k ) return 1;
	if(en >= n ) return 0;
	if(memo[ka][en] !=-1 ) return memo[ka][en]%MOD;
	int has = 0;
	if(need[ka] == raw[en]) has += dp(ka+1,en+1LL+data[need[ka]-'A']) %MOD;
	has %= MOD;
	has += dp(ka,en+1)%MOD;
	has %= MOD;
	return memo[ka][en]=has%MOD;
}

int main(){
	scanf("%d%d",&k,&n);
	for(int i = 0 ; i < 26 ; i++){
		scanf("%d",&data[i]);
		data[i] %= MOD;
	}
	memset(memo,-1,sizeof(memo));
	cin>>need>>raw;
	printf("%d\n",dp(0,0));
	return 0;	
}

/*
2 10
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 0 0 0
 AB
ABBBBABBBB
*/