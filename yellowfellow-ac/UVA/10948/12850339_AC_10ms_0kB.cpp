//UVA 10948 The primary problem
#include <bits/stdc++.h> 
using namespace std;
int isprime[1000005];
int sav[1000005][2];
vector<int>lis;
void sieve(){
	for (int i=2;i<1000005;i++){
		if (isprime[i]==0){
			lis.push_back(i);
			for (int j=i*2;j<1000005;j+=i){
				isprime[j]=1;
			}
		}
	}
}
int main(){
	sieve();
	int n;
	for (int i=0;i<1000005;i++){
		for (int j=0;j<lis.size();j++){
			if (i-lis[j]<0)break;
			if (i%2==1&&isprime[i-2]==0){
				sav[i][0]=2;
				sav[i][1]=i-2;
				break;
			}
			else if (i%2==1)break;
			if (isprime[i-lis[j]]==0){
				sav[i][0]=lis[j];
				sav[i][1]=i-lis[j];
				break;
			}
		}
	}
	while (scanf("%d",&n)&&n!=0){
		if (sav[n][1]==0){
			printf ("%d:\nNO WAY!\n",n);
		}
		else{
			printf ("%d:\n%d+%d\n",n,sav[n][0],sav[n][1]);
		}
	}
}