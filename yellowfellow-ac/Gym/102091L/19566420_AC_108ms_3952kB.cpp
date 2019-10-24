#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define rap(i,n,N) for(int i = n; i>=N; i--)

int tc,n,m,x[1005][1005],le,ri,mid,ans;
bool st;
char c;
template<typename T>
void in(T& a) {
	bool neg = 0;
	char c;
	a = 0;
	double mul = 1;
	while (1) {
		c = getchar();
		if (c == EOF || c == '-' || c == '.' || (c >= '0' && c <= '9')) break;
	}
	if (c == '-') neg = 1;
	else if (c == '.') mul = 0.1;
	else a = c - '0';
	while (1) {
		c = getchar();
		if (c == '.') mul = 0.1;
		else if (c < '0' || c > '9') break;
		else {
			if (mul < 1) a = a + mul * (c - '0');
			else a = a * 10 + (c - '0');
			if (mul < 1) mul *= 0.1;
		}
	}
	if (neg) a *= -1;
}

int main(){
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	in(tc);
	while(tc--){
		in(n), in(m);
		rep(i,1,n)rep(j,1,m){
			in(x[i][j]);
			x[i][j]+=x[i-1][j]+x[i][j-1]-x[i-1][j-1];
		}
		ans = 0,le = 1, ri = min(n,m);
		while(le<=ri){
			mid = le+ri>>1;
			st = 0;
			rep(i,mid,n){
				if(st)break;
				rep(j,mid,m){
					if(st)break;
					if(x[i][j]-x[i-mid][j]-x[i][j-mid]+x[i-mid][j-mid]<=1)st = 1;
				}
			}
			if(st)ans = mid, le = mid+1;
			else ri = mid-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}