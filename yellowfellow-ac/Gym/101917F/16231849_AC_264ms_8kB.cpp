#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	int ret = 1;
	while (ret > 0) {
		ret = a % b;
		a = b;
		b = ret;
	}
	return a;
}
int main(){
	int tc;
	cin >> tc;
	while (tc--) {
		char rem[50];
		scanf("%s", rem);
		int b = 0;
		int l = strlen(rem);
		if (l < 2) {
			rem[1] = '.';
			rem[2] = '\0';
		}
		l = strlen(rem);
		for (int i = 2; i < 6; i++) {
			if (i >= l) {
				rem[i+1] = '\0';
				rem[i] = '0';
			}
		}
		for (int i = 0; i < 6; i++) {
			if (rem[i] != '.') {
				b = b*10 + rem[i] - '0';
			}
		}
		cout << 10000/gcd(b, 10000) << endl;
	}
	return 0;
}