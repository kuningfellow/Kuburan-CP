#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ar[n+1];
	int maxi=-(1<<30);
	int mini=(1<<30);
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
		if (ar[i]>maxi)maxi=ar[i];
		if (ar[i]<mini)mini=ar[i];
	}
	printf ("%d\n",maxi);
}