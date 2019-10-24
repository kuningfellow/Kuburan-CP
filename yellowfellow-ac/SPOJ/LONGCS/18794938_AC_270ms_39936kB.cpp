#include<stdio.h>
#include<string.h>
#include<queue>

#define TC int TC=-1;while((TC!=-1||scanf("%d",&TC))&&TC--)

using namespace std;

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int max(int a, int b) {
	return -min(-a, -b);
}

namespace SA {
	const int N = 1 << 18;
	const int logN = 19;
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
			else ord[0][i] = str[i] - 'a' + 1;
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
	int lcp(int p, int a, int b) {
		int ret = 0;
		for (int i = p; i >= 0; i--) {
			int tl = (1 << i);
			if (ord[i][a] == ord[i][b]){
				ret += tl;
				a += tl;
				b += tl;
			}
		}
		return ret;
	}
}

char str[1 << 18];
int mark[1 << 18];
int loc[10];
int cnt[10];
priority_queue<pair<int,int> > pq;

int main() {
	TC {
		int k;
		scanf("%d", &k);
		int l = 0;
		for (int i = 0; i < k; i++) {
			scanf("%s", str + l);
			l = strlen(str);
			str[l++] = '$';
			str[l] = '\0';
		}
		for (int i = 0, car = 0; i < l; i++) {
			if (str[i] == '$') {
				loc[car] = i;
				car++;
				mark[i] = -1;
			}
			else {
				mark[i] = car;
			}
		}
		SA::build(str, l);
		int P = SA::getpow(l);
		
		int ans = 0;
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < k; i++) {
			cnt[i] = 0;
		}
		
		for (int i = 0, le = 0; i < l; i++) {
			if (mark[SA::arr[i]] != -1) {
				cnt[mark[SA::arr[i]]]++;
				pq.push(pair<int,int>(SA::arr[i] - loc[mark[SA::arr[i]]], i));
			} else continue;
			while (le < i && mark[SA::arr[le]] == -1) le++;
			while (le < i && mark[SA::arr[le]] != -1 && cnt[mark[SA::arr[le]]] > 1) cnt[mark[SA::arr[le++]]]--;
			while (!pq.empty() && pq.top().second < le) pq.pop();
			int good = 1;
			for (int j = 0; j < k && good; j++) {
				if (cnt[j] == 0) good = 0;
			}
			if (!good) continue;
			ans = max(ans, min(-pq.top().first, SA::lcp(P, SA::arr[le], SA::arr[i])));
		}
		printf("%d\n", ans);
	}
	return 0;
}