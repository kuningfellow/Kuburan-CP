#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int n,m;
		cin>>n>>m;
		int ar[n];
		for (int i=0;i<n;i++){
			cin>>ar[i];
		}
		int l=0;
		int has=0;
		int sum=0;
		int ans=0;
		for (int i=0;i<n;i++){
			if (ar[i]<m){
				sum=0;
				l=i+1;
				has=0;
				continue;
			}
			if (has==0){
				sum+=ar[i];
				if (ar[i]==m){
					has=1;
					ans=max(ans,sum);
				}
			}
			else{
				if (ar[i]==m){
					while (ar[l]!=m){
						sum-=ar[l];
						l++;
					}
					sum-=ar[l];
					l++;
					sum+=ar[i];
					ans=max(ans,sum);
				}
				else{
					sum+=ar[i];
					ans=max(ans,sum);
				}
			}
		}
		printf ("%d\n",ans);
	}
}