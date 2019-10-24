#include<bits/stdc++.h>
using namespace std;
struct dat{
	long long int l,m,r;
	long long int lm,lr;
	long long int rm,rr;
};
dat tree[200005];
long long int ar[50005];
dat combine(const dat& left, const dat& right){
	long long int a=left.m;
	long long int b=right.m;
	long long int c=left.m+right.m+left.r+right.l;
	long long int d=left.rm+right.lm;
	dat ret;
	if (a>b){
		ret.m=a;
		ret.l=left.l;
		ret.r=left.r+right.l+right.m+right.r;
	}
	else{
		ret.m=b;
		ret.l=left.l+left.m+left.r+right.l;
		ret.r=right.r;
	}
	if (c>=ret.m){
		ret.m=c;
		ret.l=left.l;
		ret.r=right.r;
	}
	if (d>=ret.m){
		ret.m=d;
		ret.l=left.rr;
		ret.r=right.lr;
	}
	if (left.l+left.m+left.r+right.lm>=left.lm){
		ret.lm=left.l+left.m+left.r+right.lm;
		ret.lr=right.lr;
	}
	else{
		ret.lm=left.lm;
		ret.lr=left.lr+right.l+right.m+right.r;
	}
	if (left.rm+right.l+right.m+right.r>=right.rm){
		ret.rm=left.rm+right.l+right.m+right.r;
		ret.rr=left.rr;
	}
	else{
		ret.rm=right.rm;
		ret.rr=right.rr+left.l+left.m+left.r;
	}
	return ret;
}
void update(int k, int l, int r, int p, int v){
	if (l==r&&l==p){
		tree[k].m=v;
		tree[k].l=tree[k].r=0;
		tree[k].lm=tree[k].rm=v;
		tree[k].lr=tree[k].rr=0;
		return;
	}
	else if (l>p||r<p){
		return;
	}
	else{
		update(k*2,l,(l+r)/2,p,v);
		update(k*2+1,(l+r)/2+1,r,p,v);
		tree[k]=combine(tree[k*2],tree[k*2+1]);
	}
}
void build(int k, int l, int r){
	if (l==r){
		tree[k].m=ar[l];
		tree[k].l=tree[k].r=0;
		tree[k].lm=tree[k].rm=ar[l];
		tree[k].lr=tree[k].rr=0;
		return;
	}
	build(k*2,l,(l+r)/2);
	build(k*2+1,(l+r)/2+1,r);
	tree[k]=combine(tree[k*2],tree[k*2+1]);
}
dat query(int k, int l, int r, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	if (l>qr||r<ql){
		dat empt;
		empt.l=empt.r=empt.lr=empt.rr=0;
		empt.m=empt.lm=empt.rm=-15008;
		return empt;
	}
	dat left=query(k*2,l,(l+r)/2,ql,qr);
	dat right=query(k*2+1,(l+r)/2+1,r,ql,qr);
	dat ret=combine(left,right);
	return ret;
}
int main(){
	int n,m;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%lld",&ar[i]);
	}
	build(1,0,n-1);
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if (a==0){
			update(1,0,n-1,b-1,c);
		}
		else{
			printf("%lld\n",query(1,0,n-1,b-1,c-1).m);
		}
	}
}