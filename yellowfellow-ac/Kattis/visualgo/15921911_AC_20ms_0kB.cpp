//C
/*==========================================================*/
/*    Template ver 2017-0720    |    Created by JollyBee    */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
const double EPS=(double)1e-9;
const double PI=(double)acos(-1.0);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define FOR(i,n) for(int i=0;i<n;i++)
#define REPP(i,l,r,c) for(int i=l;i<=r;i+=c)
#define REP(i,l,r) REPP(i,l,r,1)
#define FORD(i,n) for(int i=n-1;i>=0;i--)
#define REVV(i,l,r,c) for(int i=l;i>=r;i-=c)
#define REV(i,l,r) REVV(i,l,r,1)
//random
int irand(int lo, int hi){
	return (((double)rand())/(RAND_MAX+1.0)) * (hi-lo+1) + lo;
}
//ll to string
string toString(ll x) {
	stringstream ss;
	ss << x;
	return ss.str();
}
//string to ll
ll toNumber(string S) {
	ll ret; 
	sscanf(S.c_str(),"%lld",&ret); 
	return ret;
}
// std::fill(start, end, value);
// for(auto it: DS){}

const int INF=(int)2e9;
const ll MOD=(ll)1e9+7;
/*==========================================================*/
/*                     END OF TEMPLATE                      */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/

typedef pair<int,pii> tup;

vii adjList[10005];
pii vis[10005];
priority_queue<tup, vector<tup>, greater<tup> > dijk;

int main(){
	//reset
	FOR(i,10003)adjList[i].clear(),vis[i]=mp(INF,0);
	while(!dijk.empty())dijk.pop();
	vis[10003]=mp(0,1);
	//
	int v,e, s,t;
	scanf("%d %d",&v,&e);
	FOR(i,e){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adjList[u].pb(mp(v,w));
	}
	scanf("%d %d",&s,&t);
	//dijkstra
	dijk.push(mp(0,mp(s,10003)));
	while(!dijk.empty() && dijk.top().fi<=vis[t].fi){
		int w=dijk.top().fi, u=dijk.top().se.fi, par=dijk.top().se.se;
		dijk.pop();
		//check
		if(vis[u].fi< w)continue;
		if(vis[u].fi==w){ vis[u].se+=vis[par].se; continue; }
		//assign
		vis[u]=mp(w,vis[par].se);
		if(u==t)continue;
		//move
		for(pii v: adjList[u])dijk.push(mp(w+v.se, mp(v.fi,u)));
	}
	printf("%d\n",vis[t].se);
	return 0;
}