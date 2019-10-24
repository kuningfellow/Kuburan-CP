//B
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

#define REPS(i,a,b,c) for(int i=a; i!=b; i+=c)

class M{
	int dat[4][4];
	//
	int moveLeftRight(int stepJ){
		int loJ=3, hiJ=0;
		if(stepJ==1)loJ=0, hiJ=3;
		FOR(i,4) REPS(j,loJ,hiJ,stepJ){
			//find non zero
			int pos=INF;
			REPS(k,hiJ,j,-stepJ) if(dat[i][k]!=0)pos=k;
			if(pos==INF)continue;
			//
			if(dat[i][j]==0)dat[i][j]=dat[i][pos], dat[i][pos]=0, j-=stepJ;
			else if(dat[i][j]==dat[i][pos])dat[i][j]<<=1, dat[i][pos]=0;
		}
		return 0;
	}
	int moveUpDown(int stepI){
		int loI=3, hiI=0;
		if(stepI==1)loI=0, hiI=3;
		FOR(j,4) REPS(i,loI,hiI,stepI){
			//find non zero
			int pos=INF;
			REPS(k,hiI,i,-stepI) if(dat[k][j]!=0)pos=k;
			if(pos==INF)continue;
			//
			if(dat[i][j]==0)dat[i][j]=dat[pos][j], dat[pos][j]=0, i-=stepI;
			else if(dat[i][j]==dat[pos][j])dat[i][j]<<=1, dat[pos][j]=0;
		}
		return 0;
	}
public:
	int input(){
		FOR(i,4) FOR(j,4)scanf("%d",&dat[i][j]);
		return 0;
	}
	int play(int k){
		if(k==0)return moveLeftRight(1);
		if(k==1)return moveUpDown(1);
		if(k==2)return moveLeftRight(-1);
		if(k==3)return moveUpDown(-1);
		return -1;
	}
	int print(){
		FOR(i,4) FOR(j,4)printf("%d%c",dat[i][j]," \n"[j==3]);
		return 0;
	}
};

M ds;

int main(){
	ds.input();
	int k;
	scanf("%d",&k);
	ds.play(k);
	ds.print();
	return 0;
}