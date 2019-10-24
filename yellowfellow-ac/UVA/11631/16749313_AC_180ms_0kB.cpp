#include <bits/stdc++.h>
using namespace std;
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
dat tmp1[200005];
dat tmp2[200005];
void comb(int l, int r) {
	int mid = (l + r) / 2;
	int pl = l;
	int pr = mid + 1;
	int i = l;
	for (int i = l; i <= r; i++) {
		if (pl == mid + 1) {
			tmp2[i] = tmp1[pr++];
		}
		else if (pr == r + 1) {
			tmp2[i] = tmp1[pl++];
		}
		else if (tmp1[pl] < tmp1[pr]) {
			tmp2[i] = tmp1[pl++];
		}
		else {
			tmp2[i] = tmp1[pr++];
		}
	}
	for (int i = l; i <= r; i++) {
		tmp1[i] = tmp2[i];
	}
}
void msort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	msort(l, mid);
	msort(mid+1, r);
	comb(l, r);
}
	
void wsort(vector<dat>& a) {
	int L = a.size();
	for (int i = 0; i < L; i++) {
		tmp1[i] = a[i];
	}
	a.clear();
	msort(0, L-1);
	for (int i = 0; i < L; i++) {
		a.push_back(tmp1[i]);
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
		vector<dat>lis;
		dat dum;
		int red=0;
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&dum.b,&dum.c,&dum.a);
			red+=dum.a;
			lis.push_back(dum);
		}
		sort(lis.begin(), lis.end());
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