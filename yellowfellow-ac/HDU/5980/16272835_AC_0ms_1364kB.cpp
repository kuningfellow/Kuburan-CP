#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M=(ll)(1<<8);

int main(){
	int n, res=0; ll a;
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&a);
		while(a)res+=(a%M==97),a>>=8;
	}
	printf("%d\n",res);
}