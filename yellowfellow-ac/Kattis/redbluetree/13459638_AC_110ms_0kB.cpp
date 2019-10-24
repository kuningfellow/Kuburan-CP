#include <bits/stdc++.h>
using namespace std;
int par[1005];
int blue[1005];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=0;i<=n;i++){
		par[i]=i;
		blue[i]=0;
	}
	vector<pair<int,pair<int,int> > >lis;
	for (int i=0;i<m;i++){
		char rem[5];
		scanf("%s",rem);
		int a,b;
		cin>>a>>b;
		int mode=0;
		if (rem[0]=='B'){
			mode=1;
		}
		lis.push_back(pair<int,pair<int,int> >(mode,pair<int,int>(a,b)));
	}
	int edgecount=0;
	int bluecount=0;
	for (int i=0;i<m;i++){
		if (lis[i].first==0)continue;
		int X=finpar(lis[i].second.first);
		int Y=finpar(lis[i].second.second);
		if (X!=Y){
			par[X]=Y;
			blue[Y]=1;
			bluecount++;
			edgecount++;
		}
	}
	if (bluecount<k){
		printf ("0\n");
	}
	else{
		for (int i=0;i<m&&(edgecount<n-1||bluecount>k);i++){
			if (lis[i].first==1)continue;
			int X=finpar(lis[i].second.first);
			int Y=finpar(lis[i].second.second);
			if (blue[X]==1&&blue[Y]==1){
				if (X==Y){
					if (bluecount>k){
						bluecount--;
					}
					continue;
				}
				else if (edgecount<n-1){
					par[X]=Y;
					edgecount++;
				}
			}
			else if (blue[X]==1){
				par[Y]=X;
				blue[Y]=1;
				edgecount++;
			}
			else if (blue[Y]==1){
				par[X]=Y;
				blue[X]=1;
				edgecount++;
			}
			else if (X!=Y){
				par[X]=Y;
				edgecount++;
			}
		}
		if (edgecount==n-1&&bluecount==k){
			printf ("1\n");
		}
		else printf ("0\n");
	}
}