#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int n;
		cin>>n;
		long long int twos=0;
		long long int fives=0;
		long long int cou=1;
		long long int temp=n;
		while (temp>0){
			temp/=2;
			twos+=temp;
		}		
		temp=n;
		cou=1;
		while (temp>0){
			fives+=temp/5;
			temp/=5;
		}
		printf ("%lld\n",min(fives,twos));
	}
}