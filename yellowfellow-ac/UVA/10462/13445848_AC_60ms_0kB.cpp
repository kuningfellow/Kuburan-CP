#include <bits/stdc++.h>
using namespace std;
int par[105];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc,kas=1;;
	cin>>tc;
	while (tc--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,pair<int,int> > >lis;
		for (int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			lis.push_back(pair<int,pair<int,int> >(c,pair<int,int>(a,b)));
		}
		sort(lis.begin(),lis.end());
		int fir=0;
		int sec=(1<<28);
		vector<int>take;
		for (int i=0;i<=n;i++){
			par[i]=i;
		}
		int con=0;
		for (int i=0;i<m;i++){
			if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
				par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
				fir+=lis[i].first;
				take.push_back(i);
				con++;
			}
		}
		printf ("Case #%d : ",kas++);
		if (con!=n-1){
			printf ("No way\n");
			continue;
		}
		for (int j=0;j<take.size();j++){
			for (int i=0;i<=n;i++){
				par[i]=i;
			}
			int temp=0;
			con=0;
			for (int i=0;i<m;i++){
				if (i==take[j])continue;
				if (finpar(lis[i].second.first)!=finpar(lis[i].second.second)){
					par[finpar(lis[i].second.first)]=finpar(lis[i].second.second);
					temp+=lis[i].first;
					con++;
				}
			}
			int val=1;
			int sav=-1;
			if (con!=n-1){
				val=0;
			}
			// for (int i=1;i<=n;i++){
			// 	if (sav==-1){
			// 		sav=finpar(i);
			// 	}
			// 	else if (sav!=finpar(i)){
			// 		val=0;
			// 		break;
			// 	}
			// }
			if (val==1){
				sec=min(sec,temp);
			}
		}
		if (fir==(1<<28)&&sec==(1<<28)){
			printf ("No way\n");
		}
		else if (sec==(1<<28)){
			printf ("No second way\n");
		}
		else printf ("%d\n",sec);
	}
}