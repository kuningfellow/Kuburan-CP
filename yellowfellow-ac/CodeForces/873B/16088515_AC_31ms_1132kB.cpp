#include<bits/stdc++.h>
using namespace std;
char str[100005];
int ar[200005];
int main(){
	int n;
	scanf("%d%s", &n, str);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0')cur--;
		else cur++;
		ar[cur+100000] = i+1;
	}
	int ans = 0;
	cur = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, ar[cur+100000] - i);
		if (str[i] == '0')cur--;
		else cur++;
	}
	printf("%d\n", ans);
}