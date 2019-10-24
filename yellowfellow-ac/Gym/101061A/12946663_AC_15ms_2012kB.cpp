#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		long long int n;
		cin>>n;
		if (n%2==1){
			printf ("First Box\n");
		}
		else{
			int cnt=0;
			while (n%2==0){
				n/=2;
				cnt++;
			}
			if (cnt%2==0)printf ("First Box\n");
			else printf ("Second Box\n");
		}
	}
}