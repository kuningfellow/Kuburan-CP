#include <bits/stdc++.h>
using namespace std;
double tree[400005];
double ar[100005];
void build(int k, int l, int r){
	if (l==r){
		tree[k]=ar[l];
		return;
	}
	else{
		build(k*2,l,(l+r)/2);
		build(k*2+1,(l+r)/2+1,r);
		tree[k]=tree[k*2]+tree[k*2+1];
	}
}
void update(int k, int l, int r, int p, double v){
	if (l==r&&l==p){
		tree[k]=v;
		return;
	}
	else if (l>p||r<p){
		return;
	}
	else{
		update(k*2,l,(l+r)/2,p,v);
		update(k*2+1,(l+r)/2+1,r,p,v);
		tree[k]=tree[k*2]+tree[k*2+1];
	}
}
double query(int k, int l, int r, int ql, int qr){
	if (ql<=l&&r<=qr){
		return tree[k];
	}
	else if (l>qr||r<ql){
		return 0;
	}
	else{
		return query(k*2,l,(l+r)/2,ql,qr)+query(k*2+1,(l+r)/2+1,r,ql,qr);
	}
}
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%lf",&ar[i]);
	}
	build(1,0,n-1);
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int a;
		scanf("%d",&a);
		if (a==1){
			int p;
			double v;
			scanf("%d%lf",&p,&v);
			p--;
			update(1,0,n-1,p,v);
		}
		else{
			int ql,qr;
			scanf("%d%d",&ql,&qr);
			ql--;
			qr--;
			double res=query(1,0,n-1,ql,qr);
			printf ("%.9f\n",res/(qr-ql+1));
		}
	}
}