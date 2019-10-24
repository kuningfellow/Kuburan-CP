#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ar[n][2];
	int maxi=0;
	int coun=0;
	for (int i=0;i<n;i++){
		cin>>ar[i][0]>>ar[i][1];
		if (ar[i][0]>maxi){
			maxi=ar[i][0];
		}
	}
	for (int i=0;i<n;i++){
		if (ar[i][0]<=maxi&&ar[i][1]>=maxi){
			coun++;
		}
	}
	printf ("%d\n",coun);
}