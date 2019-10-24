#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		long long int a=0,b=0;
		cin>>a>>b;
		if (a<0&&b<0)break;
		a--;
		long long int suma=1,sumb=1;
		long long int sava=a,savb=b;
		if (a==-1)suma--;
		long long int pow=10;
		while (sava>=pow){
			if (sava%pow>=(pow/10)){
				suma+=(sava/pow)*(pow/10);
			}
			else suma+=(sava/pow-1)*(pow/10)+sava%(pow/10)+1;
			a/=10;
			pow*=10;
		}
		pow=10;
		while (savb>=pow){
			if (savb%pow>=(pow/10)){
				sumb+=(savb/pow)*(pow/10);
			}
			else sumb+=(savb/pow-1)*(pow/10)+savb%(pow/10)+1;
			b/=10;
			pow*=10;
		}
		printf ("%lld\n",sumb-suma);
	}
}