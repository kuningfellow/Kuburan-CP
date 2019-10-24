//UVA 1172 The Bridges of Kolsberg
#include<bits/stdc++.h>
using namespace std;

pair<int,int> dp[1005][1005];
int nr[2][1005][2];
int n[2];
string str;
map<string,int>whash;

pair<int,int> max( const pair<int,int>& a, const pair<int,int>& b ){
	if ( ( b.first > a.first ) || ( b.first == a.first && b.second < a.second ) ){
		return b;
	}
	return a;
}
pair<int,int> solve(int x, int y){
	if (x == n[0] || y == n[1]){
		return pair<int,int>(0, 0);
	}
	if (dp[x][y].first != -1){
		return dp[x][y];
	}
	pair<int,int> ret;
	ret.first = 0;
	ret.second = 0;
	if ( nr[0][x][1] == nr[1][y][1] ){
		pair<int,int> tmp = solve( x + 1, y + 1 );
		tmp.first += nr[0][x][0] + nr[1][y][0];
		tmp.second++;
		ret = max( ret, tmp );
	}
	ret = max( ret, solve( x + 1, y ) );
	ret = max( ret, solve( x, y + 1 ) );
	return dp[x][y] = ret;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		whash.clear();
		int cnt = 1;
		for(int i = 0; i < 2; i++){
			scanf("%d", &n[i]);
			for(int j = 0; j < n[i]; j++){
				cin >> str;
				cin >> str;
				scanf("%d", &nr[i][j][0]);
				if ( whash[str] == 0 ){
					whash[str] = cnt++;
				}
				nr[i][j][1] = whash[str];
			}
		}
		for(int i = 0; i < n[0]; i++){
			for(int j = 0; j < n[1]; j++){
				dp[i][j].first = dp[i][j].second = -1;
			}
		}
		pair<int,int>ans = solve(0, 0);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}