#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL MOD = 1e9;
const int N = 2e5;
struct mat{
	LL arr[2][2];
}po[N + 5], mate;

int rev[2 * N + 5];
int arr[2 * N + 5];
mat ST[4 * N + 5];

mat mul(mat A,mat B) {
	mat C;
	for(int i = 0;i < 2;i++) {
		for(int j = 0;j < 2;j++) {
			C.arr[i][j] = 0;
			for(int k = 0;k < 2;k++) {
				C.arr[i][j] = (C.arr[i][j] + A.arr[i][k] * B.arr[k][j]) % MOD;
			}
		}
	}
	return C;
}

mat add(mat A,mat B) {
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) A.arr[i][j] = (A.arr[i][j] + B.arr[i][j]) % MOD;
	return A;
}

void build(int idx,int l,int r) {
	if(l == r) {
		ST[idx].arr[0][0] = ST[idx].arr[1][1] = arr[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(2 * idx,l,mid);
	build(2 * idx + 1,mid + 1,r);
	int gap = mid + 1 - l;
	ST[idx] = add(ST[2 * idx], mul(po[gap],ST[2 * idx + 1]));
}

void update(int idx,int l,int r,int tar,LL v) {
	if(tar < l || r < tar) return ;
	if(tar == l && l == r) {
		ST[idx].arr[0][0] = ST[idx].arr[1][1] = v;
		return ;
	}
	int mid = (l + r) / 2;
	if(tar <= mid) update(2 * idx,l,mid,tar,v);
	else update(2 * idx + 1,mid + 1,r,tar,v);
	int gap = mid + 1 - l;
	ST[idx] = add(ST[2 * idx], mul(po[gap],ST[2 * idx + 1]));
}

mat query(int idx,int l,int r,int le,int ri) {
	if(ri < l || r < le) {
		return mate;
	}
	if(le <= l && r <= ri) {
		int gap = (l - le);
		if(gap == 0) return ST[idx];
		return mul(po[gap],ST[idx]);
	}
	int mid = (l + r) / 2;
	if(mid < le) return query(2 * idx + 1,mid + 1,r,le,ri);
	else if(ri < mid + 1) return query(2 * idx,l,mid,le,ri);
	return add(query(2 * idx,l,mid,le,ri), query(2 * idx + 1,mid + 1,r,le,ri));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	for(int i = 0;i < 2;i++) {
		for(int j = 0;j < 2;j++) {
			po[0].arr[i][j] = (i == j);
		}
	}
	for(int i = 0;i < 2;i++) {
		for(int j = 0;j < 2;j++) {
			mate.arr[i][j] = 0;
		}
	}
	mat tmp;
	for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) tmp.arr[i][j] = 1;
	tmp.arr[1][1] = 0;
	for(int i = 1;i <= N;i++) {
		po[i] = mul(po[i-1],tmp);
	}
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>arr[i];
	build(1,1,n);
	while(m--) {
		int t;
		LL x,v;
		cin>>t>>x>>v;
		if(t == 1) {
			update(1,1,n,x,v);
		}
		else {
			LL res = query(1,1,n,x,v).arr[0][0];
			cout<<res<<'\n';
		}
	}
}