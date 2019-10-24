#include<bits/stdc++.h>
using namespace std;

int mem[1005];
int par[1005];
int edges[1005];
bool visit[1005];
bool exist[1005][1005];
int fp(int c)
{
	if(par[c]!=c) return par[c]=fp(par[c]);
	return par[c];
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=n;a++)
	{
		par[a]=a;
		mem[a]=1;
		edges[a]=0;
	}
	for(int a=0;a<k;a++)
	{
		int inp;
		scanf("%d", &inp);
		visit[inp]=1;
	}
	for(int a=0;a<m;a++)
	{
		int L, R;
		scanf("%d%d", &L, &R);
		exist[L][R]=1;
		exist[R][L]=1;
		int p1=fp(L), p2=fp(R);
		if(p1==p2)
		{
			edges[p1]++;
		}
		else
		if(visit[p1])
		{
			par[p2]=p1;
			int p=fp(L);
			mem[p]=mem[p2]+mem[p1];
		}
		else if(visit[p2])
		{
			par[p1]=p2;
			int p=fp(L);
			mem[p]=mem[p2]+mem[p1];
		}
		else if(p1!=p2)
		{
			par[p2]=p1;
			int p=fp(L);
			mem[p]=mem[p2]+mem[p1];
		}
	}
	int ix=0, maxi=0, minedge=1e9;
	for(int a=1;a<=n;a++)
	{
		if(!visit[a]) continue;
		int p=fp(a);
		if(mem[p] > maxi)
		{
			maxi=mem[p];
			ix=p;
		}
	}
	int hasil=0;
	for(int a=1;a<=n;a++)
	{
		int p2=fp(a);
		if(p2!=ix && visit[p2]) continue;
		par[p2]=ix;
		for(int b=1;b<=n;b++)
		{
			if(a==b) continue;
			int p=fp(b);
			if(p!=ix && visit[p]) continue;
			par[p]=ix;
			if(!exist[a][b])
			{
				hasil++;
				exist[a][b]=1;
				exist[b][a]=1;
			}
		}
	}
	for(int a=1;a<=n;a++)
	{
		int p2=fp(a);
		if(p2==ix) continue;
		for(int b=1;b<=n;b++)
		{
			if(a==b) continue;
			int p=fp(b);
			if(p==ix) continue;
			if(p!=p2) continue;
			if(!exist[a][b])
			{
				// cout<<a<<" "<<b<<endl;
				hasil++;
				exist[a][b]=1;
				exist[b][a]=1;
			}
		}
	}
	printf("%d\n", hasil);
	return 0;
}