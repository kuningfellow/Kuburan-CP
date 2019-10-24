#include<stdio.h>
#define R(x) for(int i = 1; i <= x; i++)
#define TC int TC; scanf("%d", &TC); while(TC--)

int par[100005];
int finpar(int a) {
	return par[a]==a?a:par[a]=finpar(par[a]);
}

int main() {
	TC {
		int n, m, q, a;
		scanf("%d %d %d", &n, &m, &q);
		R(n) par[i] = i;
		R(m) scanf("%d %d", &n, &a), par[finpar(n)]=finpar(a);
		R(q) scanf("%d %d", &n, &m), printf("%d", finpar(n) == finpar(m));
		printf("\n");
	}
	return 0;
}