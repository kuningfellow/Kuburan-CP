#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
struct node{
	LL cnt=0,total=0;
	//count count count price
};
node st[4000005];
void update(int x,int l,int r, int z,LL zz){
	if(l>z||r<z){
		return;
	}
	if(l==r&&l==z){
		st[x].total+=zz*l;
		st[x].cnt+=zz;
		return;
	}
	int mid=(l+r)/2;
	update(x*2,l,mid,z,zz);
	update(x*2+1,mid+1,r,z,zz);
	st[x].total = st[x*2].total + st[x*2+1].total;
	st[x].cnt = st[x*2].cnt + st[x*2+1].cnt;
//	cout<<x<<" "<<st[x].total<<endl;
}
LL query(int x,int l,int r, LL z){
	// printf("at %d %d, need %d\n",l, r, z);
	if (z <= 0) return 0;
	int mid=(l+r)/2;
	if(st[x].cnt<=z){
		// printf("at %d %d return whol %d\n", l, r, st[x].total);
		return st[x].total;
	}
	if(l == r) {
		return (long long) l*z;
	}
	if(l != r){
		// printf("at %d %d try %d and %d\n",l, r, z, z-st[x*2].cnt);
		return query(x*2,l,mid,z) + query(x*2+1,mid+1,r,z-st[x*2].cnt);
	}
	return 0;
}

int main(){
	 int n,m,k;
	 priority_queue<pair<int,pair<int,int> > > pq;
	 scanf("%d %d %d",&n,&m,&k);
	 for(int i=0;i<k;i++){
	 	int x,y,cnt,pr;
	 	scanf("%d %d %d %d",&x,&y,&cnt,&pr);
	 	pq.push(make_pair(-x,make_pair(cnt,pr)));
	 	cnt*=-1;
	 	y++;
	 	pq.push(make_pair(-y,make_pair(cnt,pr)));
	 }
	 LL ans=0;
	 for(int i=1;i<=n;i++){
	 	while(!pq.empty()&&pq.top().first*-1<=i){
	 		int p = pq.top().second.second;
	 		int v = pq.top().second.first;
	 		update(1,1,1000000, p, v);
			pq.pop();
		 }
		 ans+=query(1,1,1000000,m);
	 }
	 cout<<ans<<endl;
}