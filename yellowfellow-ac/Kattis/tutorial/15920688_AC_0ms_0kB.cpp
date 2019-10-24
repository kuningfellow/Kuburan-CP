//A
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

inline double get(double m, int t){
	if(t==1){
		//manual
		double temp=(double)1.0;
		int res=0;
		while(temp-m<EPS)temp*=(double)++res;
		return (double)(res-1);
	}
	if(t==2)return log(m)/log((double)2.0);
	if(t==3)return (double)sqrt(sqrt(m));
	if(t==4)return (double)cbrt(m);
	if(t==5)return (double)sqrt(m);
	if(t==6){
		//binser
		int a=1, b, c=(int)1e9;
		int res=-1;
		while(a<=c){
			b=(a+c)>>1;
			double key=(double)b;
			double ret=key*(log(key)/log((double)2.0));
			if(ret-m<EPS)a=b+1,res=max(res,b);
			if(ret-m>EPS)c=b-1;
		}
		return (double)res+(double)0.5; //tolerance
	}
	if(t==7)return m;
	return (double)0.0;
}

int main(){
	int m,n,t;
	scanf("%d %d %d",&m,&n,&t);
	double maxN = get((double)m,t);
	if((double)n-maxN<EPS)puts("AC");
	else puts("TLE");
	return 0;
}