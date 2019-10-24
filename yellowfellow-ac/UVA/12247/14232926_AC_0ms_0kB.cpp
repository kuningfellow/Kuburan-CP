//UVA 12247 Jollo
#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int ar[3];
		int br[2];
		int vis[53];
		for (int i=0;i<53;i++)
			vis[i]=0;
		int sum=0;
		for (int i=0;i<3;i++){
			cin>>ar[i];
			sum+=ar[i];
			vis[ar[i]]=1;
		}
		for (int i=0;i<2;i++){
			cin>>br[i];
			sum+=br[i];
			vis[br[i]]=1;
		}
		if (sum==0)break;
		int best=-1;
		for (int i=1;i<=52;i++){
			if (vis[i]==1)continue;
			int check=0;
			check=max(check,(ar[0]>br[0])+(ar[1]>br[1])+(ar[2]>i));
			check=max(check,(ar[0]>br[0])+(ar[1]>i)+(ar[2]>br[1]));
			check=max(check,(ar[0]>br[1])+(ar[1]>br[0])+(ar[2]>i));
			check=max(check,(ar[0]>br[1])+(ar[1]>i)+(ar[2]>br[0]));
			check=max(check,(ar[0]>i)+(ar[1]>br[0])+(ar[2]>br[1]));
			check=max(check,(ar[0]>i)+(ar[1]>br[1])+(ar[2]>br[0]));
			if (check<2){
				best=i;
				break;
			}
		}
		printf ("%d\n",best);
	}
}