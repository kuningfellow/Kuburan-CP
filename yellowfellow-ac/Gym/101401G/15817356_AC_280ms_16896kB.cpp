#include<bits/stdc++.h>
using namespace std;
struct dat{
	int r,g,b;
	int R,G,B;
	void reset(){
		r=g=b=R=G=B=0;
	}
	void combine(const dat& left, const dat& right){
		r=left.r+right.r;
		g=left.g+right.g;
		b=left.b+right.b;
		R=left.R+right.R;
		G=left.G+right.G;
		B=left.B+right.B;
	}
};
dat tree[600005];
int lazy[600005];
char rem[200005];
void build(int k, int l, int r){
	if (l==r){
		tree[k].reset();
		if (rem[l]=='R')tree[k].r=1;
		else if (rem[l]=='G')tree[k].g=1;
		else if (rem[l]=='B')tree[k].b=1;
		return;
	}
	build(k*2,l,(l+r)/2);
	build(k*2+1,(l+r)/2+1,r);
	tree[k].combine(tree[k*2],tree[k*2+1]);
}
void update(int k ,int l, int r, int ql, int qr){
	if (lazy[k]==1){
		return;
	}
	if (ql<=l&&r<=qr){
		tree[k].B+=tree[k].r;
		tree[k].R+=tree[k].g;
		tree[k].G+=tree[k].b;
		tree[k].r=0;
		tree[k].g=0;
		tree[k].b=0;
		lazy[k]=1;
		return;
	}
	if (l>qr||r<ql){
		return;
	}
	update(k*2,l,(l+r)/2,ql,qr);
	update(k*2+1,(l+r)/2+1,r,ql,qr);
	tree[k].combine(tree[k*2],tree[k*2+1]);
}
int main(){
	int n,m;
	cin>>n>>m;
	scanf("%s",rem);
	build(1,0,n-1);
	for (int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		update(1,0,n-1,a-1,b-1);
		printf("%d %d %d\n",tree[1].R+tree[1].r,tree[1].G+tree[1].g,tree[1].B+tree[1].b);
	}
}