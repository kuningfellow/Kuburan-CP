#include <bits/stdc++.h>
using namespace std;
int tree[300000];
int lazy[300000];
int res[300000];
void update(int k, int l, int r, int ql, int qr, int v){
	if (lazy[k]!=0){
		tree[k]=lazy[k];
		lazy[k*2]=lazy[k];
		lazy[k*2+1]=lazy[k];
		lazy[k]=0;
	}
	if (l>=ql&&r<=qr){
		lazy[k]=v;
	}
	else if (l>qr||r<ql){
		return;
	}
	else{
		update(k*2,l,(l+r)/2,ql,qr,v);
		update(k*2+1,(l+r)/2+1,r,ql,qr,v);
	}
}
void flat(int k, int l, int r){
	if (lazy[k]!=0){
		tree[k]=lazy[k];
		lazy[k*2]=lazy[k];
		lazy[k*2+1]=lazy[k];
		lazy[k]=0;
	}
	if (l==r){
		res[l]=tree[k];
	}
	else if (l!=r){
		flat(k*2,l,(l+r)/2);
		flat(k*2+1,(l+r)/2+1,r);
	}
}
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		map<int,int>take;
		vector<int>lis;
		int ar[n][2];
		for (int i=0;i<n;i++){
			cin>>ar[i][0]>>ar[i][1];
			if (take[ar[i][0]]==0){
				take[ar[i][0]]=1;
				lis.push_back(ar[i][0]);
			}
			if (take[ar[i][1]]==0){
				take[ar[i][1]]=1;
				lis.push_back(ar[i][1]);
			}
		}
		sort(lis.begin(),lis.end());
		map<int,int>cor;
		for (int i=0;i<lis.size();i++){
			cor[lis[i]]=i;
		}
		for (int i=0;i<=n*2;i++){
			lazy[i]=0;
			tree[i]=0;
		}
		for (int i=0;i<n;i++){
			int x=cor[ar[i][0]];
			int y=cor[ar[i][1]];
			update(1,0,lis.size()-1,x,y,i+1);
		}
		flat(1,0,lis.size()-1);
		map<int,int>coun;
		int cnt=0;
		for (int i=0;i<lis.size();i++){
			if (coun[res[i]]==0){
				coun[res[i]]=1;
				cnt++;
			}
		}
		printf ("%d\n",cnt);
	}
}