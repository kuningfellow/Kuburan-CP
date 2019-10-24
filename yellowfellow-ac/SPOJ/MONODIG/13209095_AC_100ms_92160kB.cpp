#include <bits/stdc++.h>
using namespace std;
int res[10][32005];
vector<int>lis[10][9];
void upd(int s, int temp, int i){
	if (temp>=0&&temp<32005){
		lis[s][i].push_back(temp);
		res[s][temp]=min(res[s][temp],i);
	}
}
int main(){
	for (int i=0;i<10;i++){
		for (int j=0;j<32005;j++){
			res[i][j]=9;
		}
	}
	for (int s=1;s<10;s++){
		int num=s;
		for (int i=1;i<=8;i++){
			lis[s][i].push_back(num);
			num=num*10+s;
		}
	}
	for (int s=1;s<10;s++){
		res[s][s]=1;
		for (int i=2;i<=8;i++){
			for (int j=1;j<=i/2;j++){
				for (int k=0;k<lis[s][j].size();k++){
					for (int l=0;l<lis[s][i-j].size();l++){
						int temp=lis[s][j][k]+lis[s][i-j][l];
						upd(s,temp,i);
						
						temp=lis[s][j][k]-lis[s][i-j][l];
						upd(s,temp,i);
						
						temp=lis[s][i-j][l]-lis[s][j][k];
						upd(s,temp,i);
						
						temp=lis[s][j][k]*lis[s][i-j][l];
						upd(s,temp,i);
							
						if (lis[s][i-j][l]!=0&&lis[s][j][k]%lis[s][i-j][l]==0){
							temp=lis[s][j][k]/lis[s][i-j][l];
							upd(s,temp,i);
						}
						if (lis[s][j][k]!=0&&lis[s][i-j][l]%lis[s][j][k]==0){
							temp=lis[s][i-j][l]/lis[s][j][k];
							upd(s,temp,i);
						}
					}
				}
			}
		}
	}
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n;
		scanf("%d",&n);
		int q,a;
		scanf("%d",&q);
		for (int i=0;i<q;i++){
			scanf("%d",&a);
			if (res[n][a]==9){
				printf ("NO\n");
			}
			else printf ("%d\n",res[n][a]);
		}
	}
}