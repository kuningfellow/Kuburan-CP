#include<iostream>
#include<stdio.h>
using namespace std;
const long long int MOD = 530600414;
int cnt[250000];
long long int cost[250000];
long long int ld[250000];
long long int length[250000];
int main(){
	int tc;
	int kas=1;
	cin>>tc;
	cnt[0]=0;
	cnt[1]=1;
	cnt[2]=0;
	cost[1]=0;
	cost[2]=0;
	ld[1]=0;
	ld[2]=0;
	length[1]=1;
	length[2]=2;
	for (int x=3;x<220000;x++){
		cnt[x]=(cnt[x-2]+cnt[x-1])%MOD;
		long long int r=(((length[x-2]*cnt[x-2])%MOD)-ld[x-2]+MOD)%MOD;
		long long int tmp=(((cnt[x-2]*ld[x-1])%MOD)+(cnt[x-1]*r)%MOD)%MOD;
		length[x]=(length[x-2]+length[x-1])%MOD;
		tmp+=cost[x-2];
		tmp%=MOD;
		tmp+=cost[x-1];
		tmp%=MOD;
		cost[x]=tmp;
		ld[x]=(((ld[x-2]+((cnt[x-1]%MOD)*(length[x-2]%MOD))%MOD)%MOD)+ld[x-1])%MOD;
	}
	while (tc--){
		int n;
		cin>>n;
		printf ("Case #%d: ",kas++);
		cout<<cost[n]<<endl;
	}
}