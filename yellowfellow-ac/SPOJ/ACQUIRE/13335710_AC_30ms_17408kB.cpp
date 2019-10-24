#include <bits/stdc++.h>
using namespace std;
struct dat{
	long long int w;
	long long int h;
	bool operator < (dat a){
		if (w!=a.w)return w>a.w;
		if (w==a.w)return h>a.h;
	}
};
typedef struct dat dat;
long long int dp[50005];
vector<dat>tlis;
vector<dat>lis;
vector<int>mark;
int main(){
	int n;
	scanf("%d",&n);
	long long int a,b;
	dat tdat;
	for (int i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		tdat.w=a;
		tdat.h=b;
		tlis.push_back(tdat);
		mark.push_back(0);
	}
	sort(tlis.begin(),tlis.end());
	tdat.w=0;
	tdat.h=0;
	lis.push_back(tdat);
	int pw=-1,ph=-1;
	for (int i=0;i<n;i++){
		if (pw>=tlis[i].w && ph>=tlis[i].h){
			continue;
		}
		pw=tlis[i].w;
		ph=tlis[i].h;
		mark[i]=1;
	}
	for (int i=n-1;i>=0;i--){
		if (mark[i]==1){
			lis.push_back(tlis[i]);
		}
	}
	dp[0]=0;
	int ptr=0;
	n=lis.size();
	vector<int>stak;
	for (int i=1;i<n;i++){
		while (stak.size()>1){
			int l1=stak[stak.size()-1];
			stak.pop_back();
			int l2=stak[stak.size()-1];
			double x1=(double)(dp[l1-1]-dp[i-1])/(lis[i].h-lis[l1].h);
			double x2=(double)(dp[l2-1]-dp[i-1])/(lis[i].h-lis[l2].h);
			if (x1>x2){
				stak.push_back(l1);
				break;
			}
		}
		stak.push_back(i);
		dp[i]=(lis[stak[ptr]].h)*(lis[i].w)+dp[stak[ptr]-1];
		while (ptr+1<stak.size()&&dp[i]>lis[stak[ptr+1]].h*lis[i].w+dp[stak[ptr+1]-1]){
			ptr++;
			dp[i]=(lis[stak[ptr]].h)*(lis[i].w)+dp[stak[ptr]-1];
		}
	}
	printf ("%lld\n",dp[n-1]);
}