#include<bits/stdc++.h>
#define PB push_back
#define INT(a) scanf("%d",&a)
#define DOUBLE(a) scanf("%lf",&a)
#define GOD(a,b) a b;std::cin>>b
#define MPII(a,b) pair<int,int>(a,b)
using namespace std;
vector<pair<int,int> >lis[50005];
int mark[50005];
int good[50005];
void serc(int x, int p, int d){
	good[x]=1;
	if (d<=0)return;
	for (auto v:lis[x]){
		if (v.first==p)continue;
		serc(v.first,x,d-2*v.second);
	}
}
int dp[50005][2];
int mvc(int x, int p, int mode){
	int ret=100000;
	int temp=0;
	if (dp[x][mode]!=-1)
		return dp[x][mode];
	if (mode==0){
		for (auto v:lis[x]){
			if (v.first==p)continue;
			if (!good[v.first])continue;
			temp+=(mark[v.first]^1)+mvc(v.first,x,1);
		}
		ret=min(ret,temp);
		temp=mark[x]^1;
	}
	for (auto v:lis[x]){
		if (v.first==p)continue;
		if (good[v.first])temp+=mvc(v.first,x,0);
	}
	ret=min(ret,temp);
	return dp[x][mode]=ret;	
}
int main(){
	GOD(int,n);
	GOD(int,t);
	for (int i=0;i<n-1;i++){
		int a,b,c;
		INT(a),INT(b),INT(c);
		lis[a-1].PB(MPII(b-1,c));
		lis[b-1].PB(MPII(a-1,c));
	}
	GOD(int,q);
	for (int i=0;i<q;i++){
		GOD(int,a);
		mark[a-1]=1;
	}
	serc(0,0,t);
	for (int i=0;i<n;i++){
		dp[i][0]=dp[i][1]=-1;
	}
	printf("%d\n",mvc(0,0,0));
}