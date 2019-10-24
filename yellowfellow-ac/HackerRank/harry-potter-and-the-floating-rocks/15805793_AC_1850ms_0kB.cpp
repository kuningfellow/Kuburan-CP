#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	if (a == 0)return b;
	if (b == 0)return a;
	int ret = 1;
	while (ret > 0){
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = abs(a - c);
		int y = abs(b - d);
		printf ("%d\n", gcd(x, y) - 1);
	}
}