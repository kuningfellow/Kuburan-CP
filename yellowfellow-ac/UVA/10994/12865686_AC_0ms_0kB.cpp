#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		long long int a,b;
		cin>>a>>b;
		if (a<0||b<0)break;
		long long int sumb=0;
		long long int suma=0;
		long long int tmp;
		while (b>0){
			tmp=b;
			sumb+=tmp/10*45;
			for (long long int i=1;i<=tmp%10;i++){
				sumb+=i;
			}
			b/=10;
		}
		a--;
		while (a>0){
			tmp=a;
			suma+=tmp/10*45;
			for (long long int i=1;i<=tmp%10;i++){
				suma+=i;
			}
			a/=10;
		}
		printf ("%lld\n",sumb-suma);
	}
}
