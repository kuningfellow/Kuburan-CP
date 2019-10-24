#include <bits/stdc++.h>
using namespace std;
int bal[5005];
int coun[5005];
int ar[5005];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&ar[i]);
	}
	int dom=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<5005;j++){
			bal[j]=0;
		}
		for (int j=i;j<n;j++){
			bal[ar[j]]++;
			if ( bal[ar[j]]>bal[dom] || (bal[ar[j]]==bal[dom]&&dom>ar[j]) ){
				dom=ar[j];
			}
			coun[dom]++;
		}
	}
	for (int i=1;i<=n;i++){
		if (i!=1)printf (" ");
		printf ("%d",coun[i]);
	}
}