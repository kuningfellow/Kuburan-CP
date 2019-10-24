//UVA 10229 Modular Fibonacci
#include<bits/stdc++.h>
struct mat{
	long long int ar[2][2];
	long long int mod;
	void init(){
		ar[0][0] = ar[1][1] = 1;
		ar[0][1] = ar[1][0] = 0;
	}
	void init2(){
		ar[0][0] = ar[1][0] = ar[0][1] = 1;
		ar[1][1] = 0;
	}
	void operator*(const mat& a){
		long long int temp[2][2];
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				temp[i][j] = 0;
				for (int k = 0; k < 2; k++){
					temp[i][j] += (ar[i][k] * a.ar[k][j]) % mod;
					temp[i][j] %= mod;
				}
			}
		}
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				ar[i][j] = temp[i][j];
			}
		}
	}
};
int main(){
	long long int n, m;
	while ( scanf("%lld%lld", &n, &m) != EOF ){
		mat res;
		mat mul;
		res.init();
		res.mod = (1ll << m);
		mul.init2();
		mul.mod = (1ll << m);
		if ( n == 0 || n == 1 ){
			printf ("%d\n", n % (1ll << m) );
		}
		else{
			n--;
			while ( n > 0 ){
				if ( n % 2 == 1 ){
					res*mul;
				}
				mul * mul;
				n /= 2;
			}
			printf("%lld\n", res.ar[0][0]);
		}
	}
	return 0;
}