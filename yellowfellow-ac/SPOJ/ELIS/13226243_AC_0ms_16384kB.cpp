#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ar[n];
	int maxi=0;
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}
	for (int i=0;i<(1<<n);i++){
		int bef=-1;
		int val=1;
		int len=0;
		for (int j=0;j<n;j++){
			if ((i&(1<<j))>0){
				len++;
				if (bef>=ar[j]){
					val=0;
					break;
				}
				bef=ar[j];
			}
		}
		if (val==1&&len>maxi)maxi=len;
	}
	printf ("%d\n",maxi);
}