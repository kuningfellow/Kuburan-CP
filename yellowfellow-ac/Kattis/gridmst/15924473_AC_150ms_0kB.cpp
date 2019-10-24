//
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

const int INF=(int)1e9;
const ll MOD=(ll)1e9+7;
/*==========================================================*/
/*                     END OF TEMPLATE                      */
/* DOMINUS pascit me, et nihil mihi deerit (Psalmorum 23:1) */
/*==========================================================*/

class UFDS{
	int par[100005];
	//
	int findPar(int a){ return par[a] = (par[a]==a) ? a : findPar(par[a]); }
public:
	int reset(){
		FOR(i,100003)par[i]=i;
		return 0;
	}
	int unionDS(int a, int b){
		a=findPar(a); b=findPar(b);
		if(a==b)return 0;
		par[b]=a;
		return 1;
	}
};

UFDS ds;

struct Pos{ int x,y, diff,sum, id; } p[100005];
vi BIT;
vector<pair<pair<int,int>,int>> Raw_Edges;
int n;

bool sortpoint(Pos A, Pos B){
	if(A.x != B.x)return A.x > B.x;
	return A.y > B.y;
}

int GetNearest(int x){
	int ret =-1;
	for(; x>0; x-=(x&(-x)))
		if(BIT[x]!=-1&&(ret==-1 || p[BIT[x]].sum < p[ret].sum))ret = BIT[x];
	return ret;
}
void Insert(int x,int id){
	int maxi = BIT.size();
	for(; x<maxi; x+=(x&(-x)))
		if(BIT[x]==-1 || (p[id].sum<p[BIT[x]].sum)) BIT[x] = id;
}
void AddEdges(){
	vi axis; axis.pb(-INF);
	FOR(a,n)axis.pb(p[a].diff);
	sort(axis.begin(),axis.end());
	axis.erase(unique(axis.begin(),axis.end()),axis.end());
	sort(p,p+n,sortpoint);
	BIT = vi(axis.size(),-1);
	FOR(a,n){
		int pos = lower_bound(axis.begin(),axis.end(), p[a].diff) - axis.begin();
		int nearest = GetNearest(pos);
		if(nearest != -1)Raw_Edges.pb(mp(mp(p[a].id, p[nearest].id),p[nearest].sum - p[a].sum));
		Insert(pos,a);
	}
}

bool cmppp(pair<pii,int> a, pair<pii,int> b){
	if(a.se==b.se)return 0;
	return (a.se< b.se);
}

int main(){
	ds.reset();
	//
//	int n;
	scanf("%d",&n);
	FOR(a,n){
		scanf("%d %d",&p[a].x,&p[a].y);
		p[a].sum = p[a].x + p[a].y;
		p[a].diff = p[a].x - p[a].y;
		p[a].id = a;
	}
	FOR(a,4){
		FOR(b,n){
			if(a==1 || a==3){
				swap(p[b].x,p[b].y);
				p[b].diff = p[b].x - p[b].y;
			} else if(a==2){
				p[b].x =-p[b].x;
				p[b].sum = p[b].x + p[b].y;
				p[b].diff = p[b].x - p[b].y;
			}
		} AddEdges();
	}
	//DO MST
	sort(Raw_Edges.begin(), Raw_Edges.end(), cmppp);
//	fprintf(stderr,"     << %d\n",(int)Raw_Edges.size());
	int cnt=1;
	int res=0;
	for(auto x: Raw_Edges){
//		printf("     << %d %d %d\n",x.fi.fi,x.fi.se,x.se);
		int ret=ds.unionDS(x.fi.fi,x.fi.se);
		if(ret){
			res+=x.se;
//			if(++cnt==n)break;
		}
	}
	//print
	printf("%d\n",res);
	return 0;
}