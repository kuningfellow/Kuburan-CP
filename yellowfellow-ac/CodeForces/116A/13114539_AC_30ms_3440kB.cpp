#include <bits/stdc++.h>
using namespace std;
int main(){
	int take=0;
	int n;
	cin>>n;
	int a,b;
	int maxi=0;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		take+=(b-a);
		take=max(take,0);
		maxi=max(take,maxi);
	}
	printf ("%d\n",maxi);
}