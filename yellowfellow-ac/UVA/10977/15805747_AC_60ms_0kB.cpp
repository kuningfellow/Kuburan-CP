#include<bits/stdc++.h>
using namespace std;
int vis[205][205];
int bad[205][205];
int main(){
	while (1<2){
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0){
			break;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				vis[i][j] = 0;
				bad[i][j] = 0;
			}
		}
		int B;
		cin >> B;
		for (int i = 0; i < B; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			bad[a-1][b-1]=1;
		}
		cin >> B;
		for (int i = 0; i < B; i++){
			int a, b, l;
			scanf("%d%d%d", &a, &b, &l);
			a--;
			b--;
			for (int j = -l; j <= l; j++){
				for (int k = -l; k <= l; k++){
					double dist = sqrt(j*j + k*k);
					if (dist <= l && a+j >= 0 && a+j < n && b+k >= 0 && b+k < m){
						bad[a+j][b+k] = 1;
					}
				}
			}
		}
		queue<pair<int,int> >q;
		q.push(pair<int,int>(0,0));
		vis[0][0] = 1;
		int phase = 0;
		while (!q.empty() && vis[n-1][m-1] == 0){
			phase++;
			int siz = q.size();
			for (int i = 0; i < siz && vis[n-1][m-1] == 0; i++){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int j = -1; j <= 1; j++){
					for (int k = -1; k <= 1; k++){
						if (j == 0 && k == 0)continue;
						if (j != 0 && k != 0)continue;
						if (x+j >= 0 && x+j < n && y+k >= 0 && y+k < m && vis[x+j][y+k] == 0 && bad[x+j][y+k] == 0){
							vis[x+j][y+k] = 1;
							q.push(pair<int,int>(x+j, y+k));
						}
					}
				}
			}
		}
		if (vis[n-1][m-1] == 0){
			printf ("Impossible.\n");
		}
		else{
			printf ("%d\n", phase);
		}
	}
}