#include<bits/stdc++.h>
using namespace std;
char rem[1000005];
struct dat{
	int l, r, s;
	dat operator+(const dat& a){
		dat ret;
		ret.l=l+a.l;
		ret.r=r+a.r;
		ret.s=s+a.s;
		return ret;
	}
};
dat tree[4000005];
void build(int k, int l, int r){
	if (l==r){
		tree[k].l=0;
		tree[k].r=0;
		tree[k].s=0;
		if (rem[l]=='('){
			tree[k].l++;
		}
		else{
			tree[k].r++;
		}
		return;
	}
	build(k*2,l,(l+r)/2);
	build(k*2+1,(l+r)/2+1,r);
	int add=min(tree[k*2].l,tree[k*2+1].r);
	tree[k].s=tree[k*2].s+tree[k*2+1].s+add*2;
	tree[k].l=tree[k*2].l+tree[k*2+1].l-add;
	tree[k].r=tree[k*2].r+tree[k*2+1].r-add;
}
dat query(int k, int l, int r, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	if (l>qr||r<ql){
		dat dum;
		dum.l=dum.r=dum.s=0;
		return dum;
	}
	dat left=query(k*2,l,(l+r)/2,ql,qr);
	dat right=query(k*2+1,(l+r)/2+1,r,ql,qr);
	int add=min(left.l,right.r);
	left.l-=add;
	right.r-=add;
	left=left+right;
	left.s+=add*2;
	return left;
}
int main(){
	scanf("%s",rem);
	int l=strlen(rem);
	build(1,0,l-1);
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		printf ("%d\n",query(1,0,l-1,a-1,b-1).s);
	}
}