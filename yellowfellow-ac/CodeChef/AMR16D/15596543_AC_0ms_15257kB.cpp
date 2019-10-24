#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		if (k/3!=(k-1)/3){
			printf ("no\n");
		}
		else{
			printf ("yes\n");
		}
	}
}