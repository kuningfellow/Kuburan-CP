//UVA 1223 Editor
#include<bits/stdc++.h>
using namespace std;
const int N = 16384;
const int pN = 14;
pair<pair<int,int>,int>sfar[N];
int sford[pN][N];
int suffix[N];
int getpow(int x){
	int ret = 0;
	while ( (1<<ret) < x )ret++;
	return ret;
}
void sort(int p, int n){
	for (int i = 0; i < n; i++) {
		sfar[i].first.first = sford[p-1][i];
		sfar[i].first.second = sford[p-1][i+(1<<(p-1))];
		sfar[i].second = i;
	}
	sort(sfar,sfar+n);
	sford[p][sfar[0].second] = 1;
	for (int i = 1; i < n; i++) {
		if (sfar[i-1].first.first != sfar[i].first.first ||
			sfar[i-1].first.second != sfar[i].first.second){
			sford[p][sfar[i].second] = 1 + sford[p][sfar[i-1].second];
		}
		else{
			sford[p][sfar[i].second] = sford[p][sfar[i-1].second];
		}
	}
}
void buildsf(const char* str, int l){
	int p = getpow(l);
	int L = (1<<p)*2;
	for (int i = 0; i < L; i++) {
		if (i < l) sford[0][i] = str[i]-'0';
		else sford[0][i] = 0;
	}
	for (int i = 1; i <= p; i++) {
		sort(i, l);
	}
	for (int i = 0; i < l; i++) {
		suffix[sford[p][i]-1] = i;
	}
}
int lcp(int a, int b, int p){
	int l = 0;
	for (int i = p; i >= 0; i--) {
		int ret = (1<<i);
		if (sford[i][a] == sford[i][b]){
			l += ret;
			a += ret;
			b += ret;
		}
	}
	return l;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		char str[5005];
		scanf("%s", str);
		int l = strlen(str);
		int p = getpow(l);
		buildsf(str, l);
		int ans = 0;
		for (int i = 1; i < l; i++) {
			ans = max(ans, lcp(suffix[i-1], suffix[i], p));
		}
		printf("%d\n", ans);
	}
}
