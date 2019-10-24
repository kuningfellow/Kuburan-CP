#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		char rem[500];
		scanf("%s", rem);
		if (rem[1] == '+'){
			x++;
		}
		else{
			x--;
		}
	}
	printf("%d\n", x);
}