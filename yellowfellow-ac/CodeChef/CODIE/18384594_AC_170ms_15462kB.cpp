//resubmit dari nyamuk stile
#include<bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int mat[105][105];
long long int res[105][105];
long long int tmp[105][105];
void powe(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			tmp[i][j]=0;
			for (int k=0;k<n;k++){
				tmp[i][j]+=(mat[i][k]*mat[k][j])%MOD;
				tmp[i][j]%=MOD;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			mat[i][j]=tmp[i][j];
		}
	}
}
void mule(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			tmp[i][j]=0;
			for (int k=0;k<n;k++){
				tmp[i][j]+=(mat[i][k]*res[k][j])%MOD;
				tmp[i][j]%=MOD;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			res[i][j]=tmp[i][j];
		}
	}
}
int main(){
	long long int m;
	long long int im;
	int n;
	int a,b;
	cin>>m>>n>>a>>b;
	im=m-2;
	int sta=n/2;
	int low=n+sta;
	n*=2;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i<n/2){
				if (i+1>=j&&i-1<=j&&j<n/2){
					mat[i][j]=1;
				}
				else{
					mat[i][j]=0;
				}
			}
			else{
				int ii=i-n/2;
				int jj=j;
				if (j>=n/2){
					jj-=n/2;
				}
				if (ii+1>=jj&&ii-1<=jj&&jj<n/2){
					mat[i][j]=1;
				}
				else{
					mat[i][j]=0;
				}
			}
		}
	}
	for (int i=n/2;i<n;i++){
		for (int j=0;j<n/2;j++){
			int h=n-i;
			if (h<=a||h>=b){
				mat[i][j]=0;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j){
				res[i][j]=1;
			}
		}
	}
	m-=2;
	while (m>0){
		if (m%2==1){
			mule(n);
		}
		powe(n);
		m/=2;
	}
	long long int ans=res[low][sta];
	if (low-1>=n/2){
		ans+=res[low-1][sta];
		ans%=MOD;
	}
	if (low+1<n){
		ans+=res[low+1][sta];
		ans%=MOD;
	}
	m=MOD-2;
	long long int bot=1;
	while (m>0){
		if (m%2==1){
			bot*=im;
			bot%=MOD;
		}
		im*=im;
		im%=MOD;
		m/=2;
	}
	printf ("%lld\n",(ans*bot)%MOD);
}