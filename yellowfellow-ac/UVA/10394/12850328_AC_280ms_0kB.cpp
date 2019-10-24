//UVA 10394 Twin Primes
#include <bits/stdc++.h>
using namespace std;
bool isprime[20000005];
vector<int>lis;
void sieve(){
	for (int i=2;i<20000005;i++){
		if (isprime[i]==0){
			lis.push_back(i);
			for (int j=i*2;j<20000005;j+=i){
				isprime[j]=1;
			}
		}
	}
}
vector<int>twin;
int main(){
	sieve();
	for (int i=0;i<lis.size()-1;i++){
		if (lis[i+1]-lis[i]==2){
			twin.push_back(lis[i]);
		}
	}
	int n;
	while (scanf("%d",&n)!=EOF){
		printf ("(%d, %d)\n",twin[n-1],twin[n-1]+2);
	}
}