#include <bits/stdc++.h>
using namespace std;
struct pnt{
	long long int x;
	long long int y;
};
struct pilih{
	int l1;
	int r1;
	int l2;
	int r2;
};
pnt point[100005];
int vis[100005];
int aline(int a, int b, int c){
	if ((point[b].x-point[a].x)*(point[c].y-point[a].y)==(point[c].x-point[a].x)*(point[b].y-point[a].y)){
		return 1;
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	if (n<5){
		printf ("YES\n");
		return 0;
	}
	vector<int>picks;
	for (int i=0;i<n;i++){
		scanf("%lld%lld",&point[i].x,&point[i].y);
		if (picks.size()<4){
			int same=0;
			if (picks.size()>1){
				for (int j=0;j<picks.size()-1;j++){
					for (int k=j+1;k<picks.size();k++){
						if (aline(picks[j],picks[k],i)){
							same=1;
							break;
						}
					}
					if (same)break;
				}
			}
			if (same==0){
				picks.push_back(i);
				vis[i]=1;
			}
		}
	}
	vector<pilih>checks;
	vector<int>val;
	pilih aha;
	for (int i=0;i<picks.size();i++){
		for (int j=0;j<picks.size();j++){
			if (i==j)continue;
			for (int k=0;k<picks.size();k++){
				for (int l=0;l<picks.size();l++){
					if (k==l)continue;
					aha.l1=picks[i];
					aha.r1=picks[j];
					aha.l2=picks[k];
					aha.r2=picks[l];
					checks.push_back(aha);
					val.push_back(1);
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<checks.size();j++){
			if (val[j]==0||i==checks[j].l1||i==checks[j].r1||i==checks[j].l2||i==checks[j].r2)continue;
			if (!aline(checks[j].l1,checks[j].r1,i)&&!aline(checks[j].l2,checks[j].r2,i)){
				val[j]=0;
			}
		}
	}
	int yes=0;
	for (int i=0;i<val.size();i++){
		if (val[i]==1){
			yes=1;
			break;
		}
	}
	if (yes)printf ("YES\n");
	else printf ("NO\n");
}