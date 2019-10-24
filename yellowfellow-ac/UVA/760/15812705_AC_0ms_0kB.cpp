//UVA 760 DNA Sequencing
#include<bits/stdc++.h>
using namespace std;

const int N = 1024;
const int logN = 11;

struct sadat{
	int f, s, o;
	bool operator<(const sadat& a){
		if (f != a.f) return f < a.f;
		else if (s != a.s) return s < a.s;
		else return o < a.o;
	}
};
sadat sorar[logN][N];
int sford[logN][N];
int sfar[N];

int getpow(int n){
	int ret = 0;
	while( (1 << ret) < n ){
		ret++;
	}
	return ret;
}
void buildsorar(int p, int n){
	int s = (1 << (p - 1) );
	for (int i = 0; i < n; i++){
		sorar[p][i].f = sford[p - 1][i];
		sorar[p][i].s = sford[p - 1][i + s];
		sorar[p][i].o = i;
	}
	sort(sorar[p], sorar[p] + n);
	sford[p][ sorar[p][0].o ] = 1;
	for (int i = 1; i < n; i++){
		if (sorar[p][i].f != sorar[p][i-1].f || sorar[p][i].s != sorar[p][i-1].s){
			sford[p][ sorar[p][i].o ] = sford[p][ sorar[p][i - 1].o ] + 1;
		}
		else{
			sford[p][ sorar[p][i].o ] = sford[p][ sorar[p][i - 1].o ];
		}
	}
}
void buildsford(const char* str, int l){
	int p = getpow(l);
	int L = (1 << p) * 2;
	for (int i = 0; i < L; i++){
		if (i >= l) sford[0][i] = 0;
		else if (str[i] == '$') sford[0][i] = 1;
		else sford[0][i] = str[i] - 'a' + 2;
	}
	for (int i = 1; i <= p; i++){
		buildsorar(i, l);
	}
	for (int i = 0; i < l; i++){
		sfar[sford[p][i] - 1] = i;
	}
}
int lcp(int p, int a, int b, int A, int B){
	int l = 0;
	for (int i = p; i >= 0; i--){
		int tl = (1 << i);
		if (a + tl <= A && b + tl <= B && sford[i][a] == sford[i][b]){
			l += tl;
			a += tl;
			b += tl;
		}
	}
	return l;
}
void reset(){
	for (int i = 0; i < logN; i++){
		for (int j = 0; j < N; j++){
			sford[i][j] = 0;
		}
	}
}

int main(){
	char rem[605];
	int fir = 1;
	while (scanf("%s", rem) != EOF){
		int l = strlen(rem);
		int A = l;
		rem[l++] = '$';
		scanf("%s", rem + l);
		l = strlen(rem);
		int p = getpow(l);
		int B = l;
		
		reset();
		buildsford(rem, l);
		
		vector<int>ans;
		int L = 0;
		for (int i = 1; i < l; i++){
			int left = sfar[i-1];
			int right = sfar[i];
			if (left > right){
				left ^= right ^= left ^= right;
			}
			if ( left < A && right >= A){
				int tmp = lcp(p, left, right, A, B);
				if (tmp == 0) continue;
				if (tmp > L){
					ans.clear();
					ans.push_back(sfar[i]);
					L = tmp;
				}
				else if (tmp == L){
					int same = 1;
					for (int j = 0; j < L; j++){
						if ( rem[ sfar[i] + j ] != rem[ ans[ ans.size() - 1 ] + j ] ){
							same = 0;
							break;
						}
					}
					if (same)continue;
					ans.push_back(sfar[i]);
				}
			}
		}
		
		if (!fir){
			printf ("\n");
		}
		fir = 0;
		if (ans.size() == 0){
			printf ("No common sequence.\n");
		}
		else{
			for (int i = 0; i < ans.size(); i++){
				for (int j = 0; j < L; j++){
					printf ("%c", rem[ans[i] + j]);
				}
				printf ("\n");
			}
		}
		
	}
}