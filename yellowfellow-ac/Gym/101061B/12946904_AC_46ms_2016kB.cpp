#include <bits/stdc++.h>
using namespace std;
long long int mat[3][3];
long long int temp[3][3];
long long int res[3][3];
void mul(){
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			temp[i][j]=0;
			for (int k=0;k<3;k++){
				temp[i][j]+=(res[i][k]*mat[k][j])%1000000007;
				temp[i][j]%=1000000007;
			}
		}
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			res[i][j]=temp[i][j];
		}
	}
}
void pang(){
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			temp[i][j]=0;
			for (int k=0;k<3;k++){
				temp[i][j]+=(mat[i][k]*mat[k][j])%1000000007;
				temp[i][j]%=1000000007;
			}
		}
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			mat[i][j]=temp[i][j];
		}
	}
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		mat[0][0]=1;
		mat[0][1]=4;
		mat[0][2]=7;
		mat[1][0]=2;
		mat[1][1]=5;
		mat[1][2]=8;
		mat[2][0]=3;
		mat[2][1]=6;
		mat[2][2]=9;
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				res[i][j]=0;
			}
		}
		res[0][0]=res[1][1]=res[2][2]=1;
		n--;
		while (n>0){
			if (n%2==1){
				mul();
			}
			pang();
			n/=2;
		}
		long long int ans=0;
		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				ans+=res[i][j];
				ans%=1000000007;
			}
		}
		printf ("%lld\n",ans);
	}
}