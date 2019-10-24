#include <bits/stdc++.h>
using namespace std;
int dprod[1000005];
int dp2[1000005][10];
int prod(int a){
	if (a<10)return dprod[a]=a;
	if (dprod[a]!=-1){
		return dprod[a];
	}
	int ret=1;
	int sav=a;
	while (a>0){
		if (a%10!=0){
			ret*=(a%10);
		}
		a/=10;
	}
	dprod[sav]=prod(ret);
}
int main(){
	for (int i=0;i<1000005;i++){
		dprod[i]=-1;
	}
	for (int i=1;i<1000005;i++){
		prod(i);
	}
	dp2[1][1]=1;
	for (int i=2;i<1000005;i++){
		for (int j=0;j<10;j++){
			dp2[i][j]=dp2[i-1][j];
		}
		dp2[i][dprod[i]]++;
	}
	int tc;
	cin>>tc;
	while (tc--){
		int a,b,k;
		cin>>a>>b>>k;
		if (a>b){
			int temp=a;
			a=b;
			b=temp;
		}
		printf ("%d\n",dp2[b][k]-dp2[a-1][k]);
	}
}