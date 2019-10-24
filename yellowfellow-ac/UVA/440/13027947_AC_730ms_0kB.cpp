#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		int bes=0;
		int ans;
		int cor[155];
		for (int i=1;;i++){
			int j=0;
			for (int k=0;k<155;k++){
				cor[k]=0;
			}
			cor[0]=1;
			int cnt=0;
			while (cor[1]==0){
				cnt++;
				int tem=i;
				while (tem>0){
					j++;
					j%=n;
					if (cor[j]==0){
						tem--;
					}
				}
				cor[j]=1;
			}
			if (cnt>bes){
				bes=cnt;
				ans=i;
				if (bes==n-1)break;
			}
		}
		printf ("%d\n",ans);
	}
}