#include<bits/stdc++.h>
#define M 1000000007
#define ll long long
using namespace std;

ll fexpo(int p, ll base)
{
	if(p==1) return base;
	if(p==0) return 1;
	if(p%2==1) return ((fexpo(p-1, base)%M)*(base%M))%M;
	ll h=fexpo(p/2, base);
	return ((h%M)*(h%M))%M;
}

ll fac(int n, int r)
{
	ll ret=1;
	for(int a=r+1;a<=n;a++)
	{
		ret=ret*a;
		ret%=M;
	}
	return ret;
}

ll invers(ll n)
{
	return fexpo(M-2, n)%M;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	ll hasil=fac(m, (m-n))%M;
	hasil=(hasil*(invers(fac(n, 0)%M)%M))%M;
	printf("%lld\n", hasil);
}