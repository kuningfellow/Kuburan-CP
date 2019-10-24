#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int j=0;
	while (j+1<=m){
		m-=j+1;
		j++;
		j%=n;
	}
	printf ("%d\n",m);
}