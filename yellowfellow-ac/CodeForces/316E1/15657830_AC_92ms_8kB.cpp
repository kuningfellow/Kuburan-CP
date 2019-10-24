#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 1e5;
const int INF = 1e9;
const ll mod = 1e9;

ll arr[110],fibo[110];

void prework(){
	fibo[0]=fibo[1]=1;
	for(int i=2;i<=100;i++) fibo[i]=(fibo[i-1]+fibo[i-2])%mod;
}

int main(){
	prework();
	
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
	ll lf,rg;
	while(m--){
		scanf("%d %lld %lld",&q,&lf,&rg);
		if(q==1){
			lf--;
			arr[lf]=rg;
		}
		else{
			lf--; rg--;
			ll sum=0;
			for(int i=0;i<=(rg-lf);i++){
				sum = (sum + (fibo[i]*arr[lf+i]))%mod;
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}