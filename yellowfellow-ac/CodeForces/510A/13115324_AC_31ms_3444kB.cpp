#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		int s=0;
		if (i%2==0&&(i/2)%2==1){
			s=k-1;
		}
		if (i%2==0){
			for (int j=0;j<k;j++){
				if (j==s)printf ("#");
				else printf (".");
			}
		}
		else{
			for (int j=0;j<k;j++){
				printf ("#");
			}
		}
		printf ("\n");
	}
}