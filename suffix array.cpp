namespace SA {
	const int N = 1024;
	const int logN = 11;
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
			else if (str[i] == '$') ord[0][i] = 1;
			else ord[0][i] = str[i] - 'a' + 2;
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
	int lcp(int p, int a, int b, int A, int B) {
		//A string 1 length
		//B string 1 + 2 length (total length)
		int l = 0;
		for (int i = p; i >= 0; i--) {
			int tl = (1 << i);
			if (a + tl <= A && b + tl <= B && ord[i][a] == ord[i][b]){
				l += tl;
				a += tl;
				b += tl;
			}
		}
		return l;
	}
};
