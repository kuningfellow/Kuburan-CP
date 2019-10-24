#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,a,b;
	scanf("%d%d%d", &k,&a,&b);
	int res=(a/k)+(b/k);
	if ((a%k>0 && b<k) || (b%k>0 && a<k)) printf("-1\n");
	else if (a<k && b<k)printf ("-1\n");
	else printf("%d\n",res);
}