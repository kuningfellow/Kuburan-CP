#include <bits/stdc++.h>
using namespace std;
long long int mat[2][2];
long long int base[2][2];
long long int temp[2][2];
void mult(){
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			temp[i][j]=0;
			for (int k=0;k<2;k++){
				temp[i][j]+=(base[i][k]*mat[k][j]%1000000007)%1000000007;
				temp[i][j]%=1000000007;
			}
		}
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			base[i][j]=temp[i][j];
		}
	}
}
void powe(){
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			temp[i][j]=0;
			for (int k=0;k<2;k++){
				temp[i][j]+=(mat[i][k]*mat[k][j]%1000000007)%1000000007;
				temp[i][j]%=1000000007;
			}
		}
	}
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			mat[i][j]=temp[i][j];
		}
	}
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int m,n;
		scanf("%lld",&m);
		char rem[10000];
		scanf("%s",rem);
		long long int tem=strlen(rem);
		long long int mul=1;
		while (tem>0){
			tem--;
			mul*=10;
			mul%=1000000007;
		}
		n=0;
		for (int i=0;i<strlen(rem);i++){
			n*=10;
			n+=rem[i]-'0';
			n%=1000000007;
		}
		mat[0][0]=mul;
		mat[0][1]=1;
		mat[1][0]=0;
		mat[1][1]=1;
		base[0][0]=base[1][1]=1;
		base[1][0]=base[0][1]=0;
		m--;
		while (m>0){
			if (m%2==1){
				mult();
			}
			powe();
			m/=2;
		}
		printf ("%lld\n",( ( (base[0][0]+base[0][1])%1000000007) * n )%1000000007 );
	}
}