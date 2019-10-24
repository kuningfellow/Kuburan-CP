#include <bits/stdc++.h>
using namespace std;
struct dat{
	int dis;
	int add;
	bool operator < (struct dat a){
		return dis<a.dis;
	}
};
int abs(int a){
	if (a<0)return -a;
	return a;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n;
		scanf("%d",&n);
		dat br[n];
		for (int i=0;i<n;i++){
			scanf("%d%d",&br[i].dis,&br[i].add);
		}
		sort(br,br+n);
		int ar[n+2][2];
		ar[0][0]=ar[0][1]=0;
		int dead[n+2];
		for (int i=0;i<n+2;i++){
			dead[i]=0;
		}
		for (int i=0;i<n;i++){
			ar[i+1][0]=br[i].dis;
			ar[i+1][1]=br[i].add;
		}
		scanf("%d%d",&ar[n+1][0],&ar[n+1][1]);
		int x=ar[n+1][0]-ar[n+1][1];
		int trace[n+2];
		int possible=0;
		int take=0;
		int pos=n;
		int best=-1;
		int found=1;
		while (x>0&&found){
			best=0;
			found=0;
			int kil=0;
			pos=n;
			while (pos>0){
				if (ar[pos][0]>=x){
					if (dead[pos]==0&&ar[pos][1]>best){
						best=ar[pos][1];
						kil=pos;
						found=1;
					}
				}
				pos--;
			}
			if (found==0)break;
			dead[kil]=1;
			take++;
			x-=best;
		}
		if (x>0)printf ("-1\n");
		else printf ("%d\n",take);
	}
}