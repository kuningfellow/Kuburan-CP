#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	int n,k,a,b;
	cin>>n>>k;
	long long ar[n];
	for (int i=0;i<n;i++){
		ar[i]=0;
	}
	for (int i=0;i<n;i++){
		cin>>a;
		for (int j=0;j<a;j++){
			cin>>b;
			ar[i]|=(1ll<<(b-1));
		}
	}
	int choi=0;
	int bes=n;
	long long int cap=(1<<n);
	for (long long int i=0;i<cap;i++){
		long long int pick=0;
		int coun=0;
		for (int j=0;j<n;j++){
			if ((i&(1<<j))>0){
				coun++;
				pick|=ar[j];
			}
		}
		if (pick==(1ll<<(k))-1){
			if (coun<=bes){
				bes=coun;
				choi=i;
			}
		}
	}
	int fir=1;
	printf ("%d\n",bes);
	for (int j=0;j<n;j++){
		if ((choi&(1<<j))>0){
			if (fir==0)printf (" ");
			fir=0;
			printf ("%d",j+1);
		}
	}
	printf ("\n");
}