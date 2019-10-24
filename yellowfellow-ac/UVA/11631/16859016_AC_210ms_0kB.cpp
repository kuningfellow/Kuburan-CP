#include <bits/stdc++.h>
int par[200005];
int finpar(int x){
	if (par[x]==x)return x;
	return par[x]=finpar(par[x]);
}
struct dat {
	int a, b, c;
	bool operator<(const dat& p) {
		if (a != p.a) return a < p.a;
		else if (b != p.b) return b < p.b;
		return c < p.c;
	}
};
dat lis[200005];
namespace wygn {
	dat t1[200005];
	dat t2[200005];
	void merg(int l, int r) {
		int pl = l;
		int mid = (l + r) / 2;
		int pr = mid + 1;
		for (int i = l; i <= r; i++) {
			if (pl > mid) t2[i] = t1[pr++];
			else if (pr > r) t2[i] = t1[pl++];
			else if (t1[pl] < t1[pr]) t2[i] = t1[pl++];
			else t2[i] = t1[pr++];
		}
		for (int i = l; i <= r; i++) {
			t1[i] = t2[i];
		}
	}
	void divi(int l, int r) {
		if (l == r) return;
		int mid = (l + r) / 2;
		divi(l, mid);
		divi(mid+1, r);
		merg(l, r);
	}
	void sort(dat* a, int n) {
		for (int i = 0; i < n; i++) {
			t1[i] = a[i];
		}
		divi(0, n-1);
		for (int i = 0; i < n; i++) {
			a[i] = t1[i];
		}
	}
}

int main(){
	while (1<2){
		int n,m;
		scanf("%d%d",&n,&m);
		if (n==0&&m==0)break;
		for (int i=0;i<=n;i++){
			par[i]=i;
		}
		dat dum;
		int red = 0;
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&dum.b,&dum.c,&dum.a);
			red += dum.a;
			lis[i] = dum;
		}
		wygn::sort(lis, m);
		int tot=0;
		int cnt=0;
		for (int i=0;i<m;i++){
			if (finpar(lis[i].b)!=finpar(lis[i].c)){
				tot+=lis[i].a;
				cnt++;
				par[finpar(lis[i].b)]=finpar(lis[i].c);
			}
		}
		printf ("%d\n",red-tot);
	}
}