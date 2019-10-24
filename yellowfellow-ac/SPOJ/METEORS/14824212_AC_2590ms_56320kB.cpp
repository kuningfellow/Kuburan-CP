#include<bits/stdc++.h>
using namespace std;
struct query{
	int l,r;
	double n;
};
typedef struct query query;
double BIT[300005];
double rec[300005];
int L[300005];
int R[300005];
vector<int>par[300005];
vector<int>lis[300005];
vector<query>Q;
int m;
void update(int x, double v){
	while (x<=m){
		BIT[x]+=v;
		x+=-x&x;
	}
}
double getsum(int x){
	double ret=0;
	while (x>0){
		ret+=BIT[x];
		x-=-x&x;
	}
	return ret;
}
int main(){
	int n,q;
	query shove;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		par[a-1].push_back(i+1);
	}
	for (int i=0;i<n;i++){
		scanf("%lf",&rec[i]);
	}
	scanf("%d",&q);
	for (int i=0;i<n;i++){
		L[i]=0;
		R[i]=q;
	}
	for (int i=0;i<q;i++){
		scanf("%d%d%lf",&shove.l,&shove.r,&shove.n);
		Q.push_back(shove);
	}
	while (1<2){
		int stop=1;
		for (int i=0;i<=m;i++){
			BIT[i]=0;
		}
		for (int i=0;i<n;i++){
			if (L[i]!=R[i]){
				lis[(L[i]+R[i])/2].push_back(i);
				stop=0;
			}
		}
		for (int i=0;i<q;i++){
			if (Q[i].l<=Q[i].r){
				update(Q[i].l,Q[i].n);
				update(Q[i].r+1,-Q[i].n);
			}
			else{
				update(Q[i].l,Q[i].n);
				update(1,Q[i].n);
				update(Q[i].r+1,-Q[i].n);
			}
			for (int j=lis[i].size()-1;j>=0;j--){
				double tmp=0;
				for (int k=0;k<par[lis[i][j]].size();k++){
					tmp+=getsum(par[lis[i][j]][k]);
				}
				if (tmp>=rec[lis[i][j]]){
					R[lis[i][j]]=i;
				}
				else{
					L[lis[i][j]]=i+1;
				}
				lis[i].pop_back();
			}
		}
		if (stop)break;
	}
	for (int i=0;i<n;i++){
		if (R[i]<q)printf ("%d\n",R[i]+1);
		else printf ("NIE\n");
	}
}