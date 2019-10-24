#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		int ar[n][2];
		int suma=0;
		int sumb=0;
		for (int i=0;i<n;i++){
			cin>>ar[i][0]>>ar[i][1];
		}
		for (int i=0;i<n;i++){
			suma+=ar[i][0]*ar[(i+1)%n][1];
			sumb+=ar[i][1]*ar[(i+1)%n][0];
		}
		if (suma-sumb<0){
			printf ("CW %.1f\n",((double)sumb-suma)/2);
		}
		else printf ("CCW %.1f\n",((double)suma-sumb)/2);
	}
}