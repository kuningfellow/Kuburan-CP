#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[1000005];
	scanf("%s",rem);
	long long int coun=0;
	long long int bcoun=0;
	int l=strlen(rem);
	for (int i=l-1;i>=0;i--){
		if (rem[i]=='b'){
			bcoun++;
			bcoun%=1000000007;
		}
		else{
			coun+=bcoun;
			coun%=1000000007;
			bcoun*=2;
			bcoun%=1000000007;
		}
	}
	printf ("%lld\n",coun);
}