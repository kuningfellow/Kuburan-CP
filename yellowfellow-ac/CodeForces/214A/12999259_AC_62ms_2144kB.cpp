#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for (int i=0;i<=1000;i++){
		for (int j=0;j<=1000;j++){
			if (i*i+j==n&&i+j*j==m){
				cnt++;
			}
		}
	}
	printf ("%d\n",cnt);
}