//UVA 11512 GATTACA
//Suffix Array with Radix Sort

#include<stdio.h>
#include<string.h>

#define TC int TC=-1;while((TC!=-1||scanf("%d",&TC))&&TC--)

using namespace std;

namespace SA {
	const int N = 2048;
	const int logN = 12;
	int ord[logN][N];
	int arr[N];
	int cnt[N], ref[N][2];
	int getpow(int x) {
		int r = 0;
		while ( (1 << r) < x ) r++;
		return r;
	}
	void reset() {
		for (int i = 0; i < N; i++) {
			cnt[i] = ref[i][0] = ref[i][1] = 0;
		}
		for (int i = 0; i < logN; i++) {
			for (int j = 0; j < N; j++) {
				ord[i][j] = 0;
			}
		}
	}
	void radix(int p, int n) {
		int h = (1 << (p - 1));
		
		for (int i = 0; i <= n; i++) ref[i][0] = ref[i][1] = cnt[i] = 0;
		for (int i = 0; i < n; i++) cnt[ord[p - 1][i + h]]++;
		for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i];
		for (int i = 0; i < n; i++) ref[cnt[ord[p - 1][i + h]]--][0] = i;
			
		for (int i = 0; i <= n; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) cnt[ord[p - 1][i]]++;
		for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i];
		for (int i = n; i > 0; i--) ref[cnt[ord[p - 1][ref[i][0]]]--][1] = ref[i][0];
			
		ord[p][ref[1][1]] = 1;
		for (int i = 2; i <= n; i++) {
			if (ord[p - 1][ref[i][1]] == ord[p - 1][ref[i - 1][1]] && ord[p - 1][ref[i][1] + h] == ord[p - 1][ref[i - 1][1] + h]) 
				ord[p][ref[i][1]] = ord[p][ref[i - 1][1]];
			else
				ord[p][ref[i][1]] = ord[p][ref[i - 1][1]] + 1;
		}
	}
	void build(const char* str, int l) {
		reset();
		int p = getpow(l);
		int L = 1 << (p + 1);
		for (int i = 0; i < L; i++) {
			if (i >= l) ord[0][i] = 0;
			else ord[0][i] = str[i] - 'A' + 1;
		}
		//scale
		for (int i = 0; i < L; i++) cnt[ord[0][i]] = 1;
		for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < L; i++) ord[0][i] = cnt[ord[0][i]];
		
		for (int i = 1; i <= p; i++) {
			radix(i, l);
		}
		for (int i = 0; i < l; i++) {
			arr[ord[p][i] - 1] = i;
		}
	}
	int lcp(int p, int a, int b, int l) {
		int ret = 0;
		for (int i = p; i >= 0; i--) {
			int tl = (1 << i);
			if (a + tl <= l && b + tl <= l && ord[i][a] == ord[i][b]){
				ret += tl;
				a += tl;
				b += tl;
			}
		}
		return ret;
	}
}

int main() {
	TC {
		char str[1001];
		scanf("%s", str);
		int l = strlen(str);
		int p = SA::getpow(l);
		SA::build(str, l);
		
		int idx = -1, best = 0, ans = 2;
		
		for (int i = 1, prev = -1, car = 2; i < l; i++) {
			int tmp = SA::lcp(p, SA::arr[i - 1], SA::arr[i], l);
			if (tmp == prev) car++;
			else car = 2, prev = -1;
			if (tmp > best) best = tmp, idx = i, ans = 2, prev = tmp;
			if (car > ans) ans = car;
			if (prev != -1) prev = tmp;
		}
		
		if (idx == -1) {
			printf("No repetitions found!\n");
		}
		else {
			for (int i = 0; i < best; i++) {
				printf("%c", str[SA::arr[idx] + i]);
			}
			printf(" %d\n", ans);
		}
	}
	return 0;
}