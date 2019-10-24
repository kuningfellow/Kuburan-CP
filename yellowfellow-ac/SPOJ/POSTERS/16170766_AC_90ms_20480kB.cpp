#include<bits/stdc++.h>
#define PB push_back
#define endl '\n'
using namespace std;

const int N = 80000;
int lazy[4 * N + 5];
int ST[4 * N + 5];
map<int,int> ms;
set<int> st;
int l[N + 5], r[N + 5];

void pushdown(int idx,int l,int r){
	if(lazy[idx] == 0) return ;
	if(l != r) {
		lazy[2 * idx] = lazy[idx];
		lazy[2 * idx + 1] = lazy[idx];
	}
	ST[idx] = lazy[idx];
	lazy[idx] = 0;
}

void update(int idx,int l,int r,int le,int ri,int v) {
	pushdown(idx,l,r);
	if(r < le || ri < l) return ;
	if(le <= l && r <= ri) {
		lazy[idx] = v;
		return ;
	}
	int mid = (l + r) / 2;
	update(2 * idx,l,mid,le,ri,v);
	update(2 * idx + 1,mid + 1,r,le,ri,v);
}

int query(int idx,int l,int r,int tar) {
	pushdown(idx,l,r);
	if(l == tar && r == tar) return ST[idx];
	int mid = (l + r)/2;
	if(tar <= mid) return query(2 * idx,l,mid,tar);
	else return query(2 * idx +1,mid +1,r,tar);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int ntc;
	cin>>ntc;
	while(ntc--) {
		int n;
		memset(ST,0,sizeof ST), memset(lazy,0,sizeof lazy);
		ms.clear();
		st.clear();
		cin>>n;
		for(int i = 1;i <= n;i++) {
			cin>>l[i]>>r[i];
			st.insert(l[i]), st.insert(r[i]);
		}
		int k = 0;
		for(set<int>::iterator it = st.begin();it != st.end();it++){
			ms[*it] = ++k;
		}
		for(int i = 1;i <= n;i++) {
			update(1,1,N,ms[l[i]],ms[r[i]],i);
		}
		set<int> str;
		for(int i = 1;i <= N;i++) {
			int res = query(1,1,N,i);
			if(res != 0) str.insert(res);
		}
		cout<<str.size()<<endl;
	}
}