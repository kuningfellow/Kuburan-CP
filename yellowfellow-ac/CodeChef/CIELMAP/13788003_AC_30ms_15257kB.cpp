#include <bits/stdc++.h>
using namespace std;
int fin(int x1, int y1, int x2, int y2, int x3, int y3){
	int Ax=x2-x1;
	int Ay=y2-y1;
	int Bx=x3-x1;
	int By=y3-y1;
	int cross=Ax*By-Ay*Bx;
	if (cross==0)return 0;
	if (cross>0)return 1;
	return -1;
}
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	scanf("%d",&tc);
	while (tc--){
		int n;
		scanf("%d",&n);
		int ar[n][2];
		for (int i=0;i<n;i++){
			scanf("%d%d",&ar[i][0],&ar[i][1]);
		}
		if (n==4){
			double maxi=0;
			double temp;
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					if (i==j)continue;
					int lcnt=0;
					int rcnt=0;
					for (int k=0;k<n;k++){
						if (k==i)continue;
						if (k==j){
							temp=sqrt((ar[i][0]-ar[k][0])*(ar[i][0]-ar[k][0])+(ar[i][1]-ar[k][1])*(ar[i][1]-ar[k][1]));
						}
						else{
							int side=fin(ar[i][0],ar[i][1],ar[j][0],ar[j][1],ar[k][0],ar[k][1]);
							if (side==1)lcnt++;
							if (side==-1)rcnt++;
						}
					}
					if (lcnt>1||rcnt>1){
						maxi=max(maxi,temp);
					}
				}
			}
			printf ("%.10f\n",maxi);
		}
		else{
			double maxi=0;
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					if (i==j)continue;
					maxi=max(maxi,sqrt((ar[i][0]-ar[j][0])*(ar[i][0]-ar[j][0])+(ar[i][1]-ar[j][1])*(ar[i][1]-ar[j][1])));
				}
			}
			printf ("%.10f\n",maxi);
		}
	}
}