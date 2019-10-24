#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
ll datas[25];
int n, globmini, m, output;
vector<int> S;
bool checker(ll pass)
{
	int ret=0;
	for(int a=1;a<=m;a++)
	{
		if((pass & ((ll)1 << a)) > 0) ret++;
	}
	if(ret >=m) return 1;
	return 0;
}
int getres(int now)
{
	int ret=0;
	for(int a=1;a<=n;a++)
	{
		if((now & (1 << a)) > 0)
		{
			ret++;
		}
	}
	if(globmini > ret)
	{
		globmini=ret;
		output=now;
	}
	return ret;
}

void solve(int mask, ll passed, int ix)
{
	if(passed==(((ll)1 << (m+1))-1))
	{
		getres(mask);
		return;
	}
	int ret=100000;
	for(int z=ix;z<=n;z++)
	{
		if((mask & (1 << z)) > 0) continue;
		int nm=(mask | (1 << z));
		ll np=(passed | datas[z]);
		solve(nm, np, z);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	globmini=100000;
	for(int a=1;a<=n;a++)
	{
		int data;
		scanf("%d", &data);
		for(int b=0;b<data;b++)
		{
			int inp;
			scanf("%d", &inp);
			datas[a]=(datas[a] | ((ll)1 << inp));
		}
	}
	solve(1, 1, 1);
	printf("%d\n", globmini);
	bool check=0;
	for(int a=1;a<=n;a++)
	{
		if((output & (1 << a)) > 0)
		{
			if(check) printf(" ");
			printf("%d", a);
			check=1;
		}
	}
	printf("\n");
}