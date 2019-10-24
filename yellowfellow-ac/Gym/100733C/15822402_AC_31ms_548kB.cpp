#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b){
	long long int ret= 1;
	while (ret>0){
		ret= a%b;
		a=b;
		b=ret;
	}
	return a;
}
int main(){
	char rem[50];
	scanf("%s",rem);
	long long int bot=100;
	int l=strlen(rem);
	long long int x=0;
	int mode=0;
	for (int i=0;i<l;i++){
		if (rem[i]=='.'){
			mode=1;
		}
		else{
			if (mode)bot*=10;
			x=x*10+rem[i]-'0';
		}
	}
	long long int g=gcd((long long )x,bot);
	printf ("%lld\n",bot/g);
}