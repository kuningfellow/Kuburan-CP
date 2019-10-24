#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int red=n+(n+1)*((1<<m)-1);
	if (k-red<=1)printf ("yes\n");
	else printf ("no\n");
}