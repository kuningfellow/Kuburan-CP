#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n, a, b;
		cin >> n >> a >> b;
		int ar[n];
		int win = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
			if (abs(ar[i]) == abs(a) || abs(ar[i]) == abs(b)){
				win = 1;
			}
		}
		if (win == 0){
			win = 2;
			for (int i = 0; i < n; i++){
				int tmp = 0;
				for (int j = 0; j < n; j++){
					int x = ar[i] + ar[j];
					if (x == a || x == b) tmp = 1;
					x = ar[i] - ar[j];
					if (x == a || x == b) tmp = 1;
				}
				if (tmp == 0){
					win = 0;
					break;
				}
			}
			for (int i = 0; i < n; i++){
				int tmp = 0;
				for (int j = 0; j < n; j++){
					int x = -ar[i] + ar[j];
					if (x == a || x == b) tmp = 1;
					x = -ar[i] - ar[j];
					if (x == a || x == b) tmp = 1;
				}
				if (tmp == 0){
					win = 0;
					break;
				}
			}
		}
		printf ("%d\n", win);
	}
}