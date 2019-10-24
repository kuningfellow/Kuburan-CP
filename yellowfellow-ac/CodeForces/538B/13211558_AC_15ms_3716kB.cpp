#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k=0;
	vector<int>lis;
	int maxi=0;
	while (n>0){
		lis.push_back(n%10);
		maxi=max(maxi,n%10);
		n/=10;
	}
	printf ("%d\n",maxi);
	for (int i=0;i<maxi;i++){
		int flag=0;
		if (i!=0)printf (" ");
		for (int j=lis.size()-1;j>=0;j--){
			if (flag==1){
				if (lis[j]>0)printf ("1");
				else printf ("0");
				lis[j]--;
			}
			else{
				if (lis[j]>0){
					printf ("1");
					lis[j]--;
					flag=1;
				}
			}
		}
	}
	printf ("\n");
}