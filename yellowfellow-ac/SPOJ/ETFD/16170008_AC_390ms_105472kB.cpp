#include<bits/stdc++.h>
#define PB push_back
using namespace std;

const int N = 1e6;
vector<int> primes;
int num[1005];
int tot[N + 5],dep[N + 5];

int pref[21][N + 5];

void pre() {
	for(int i = 2;i <= 1000;i++) {
		if(num[i] == 0){
			primes.PB(i);
			for(int j = i * i;j <= 1000;j+=i) num[j] = i;
		}
	}
	tot[1] = 1;
	dep[1] = 0;
	pref[0][1] = 1;
	for(int i = 2;i <= N;i++) {
		int r = i;
		int c = i;
		for(int j = 0;j < primes.size();j++) {
			int x = primes[j];
			if(x * x > r) break;
			if(r % x == 0) {
				while(r % x == 0) r/=x;
				c = c / x * (x - 1);	
			}
		}
		if(r != 1) c = c / r * (r - 1);
		tot[i] = c;
		dep[i] = dep[c] + 1;
		for(int j = 0;j <= 20;j++) pref[j][i] = pref[j][i-1];
		if(dep[i] <= 20) pref[dep[i]][i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	pre();
	int tc;
	cin>>tc;
	while(tc--) {
		int l,r,v;
		cin>>l>>r>>v;
		cout<<pref[v][r] - pref[v][l-1]<<'\n';
	}
}