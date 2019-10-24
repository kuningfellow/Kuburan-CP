#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long LL;
const double PI = acos(-1)*10000000;
int main()
{	
	int tc;
	scanf("%d", &tc);
	for(int ntc=0;ntc<tc;ntc++)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		double ans=82831850;
		ans+=(a-2)*PI+(b-1)*20000000;
		printf ("%.6f\n",ans/1e7);
		// printf("%lld.%lld\n", ans/(LL)1e7, ans%(LL)1e6);
	}
	return 0;
}