#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long int ar[5000005];
vector<long long int>lis;
priority_queue<pair<long long int,int> >pq;
int main(){
	int tc;
	scanf("%d",&tc);
	int kas=1;
	while (tc--){
		int n;
		long long int a,b;
		lis.clear();
		while (!pq.empty()){
			pq.pop();
		}
		scanf("%d%lld%lld",&n,&a,&b);
		for (int i=0;i<n;i++){
			scanf("%lld\n",&ar[i]);
		}
		sort(ar,ar+n);
		for (int i=0;i<n;i++){
			if (i<2){
				lis.push_back(ar[i]);
			}
			else if (i>n-3){
				lis.push_back(ar[i]);
			}
			else{
				if (ar[i]<0){
					pq.push(pair<long long int,int>(ar[i],0));
				}
				else{
					pq.push(pair<long long int,int>(-ar[i],1));
				}
			}
		}
		int add=0;
		while (add<4&&pq.size()>0){
			long long int eval=pq.top().first;
			if (pq.top().second==1){
				eval*=-1;
			}
			pq.pop();
			lis.push_back(eval);
			add++;
		}
		long long int ans=-(1ll<<60);
		for (int i=0;i<lis.size();i++){
			for (int j=0;j<lis.size();j++){
				if (i==j)continue;
				ans=max(ans,a*lis[i]*lis[i]+b*lis[j]);
			}
		}
		printf ("Case #%d: %lld\n",kas++,ans);
	}
}