#include <bits/stdc++.h>
using namespace std;
int ar[300005];
int tr[300005];
int main(){
	int n,k;
	cin>>n>>k;
	int a;
	ar[0]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		tr[i]=a;
		ar[i]=a+ar[i-1];
	}
	int ansl=0,ansr=0;
	int l=1,r=n,mid;
	while (l<=r){
		mid=(l+r)/2;
		int yes=0;
		for (int i=mid;i<=n;i++){
			if (ar[i]-ar[i-mid]+k>=(mid)){
				yes=1;
				ansl=i-mid;
				ansr=i;
			}
		}
		if (yes==1){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf ("%d\n",ansr-ansl);
	for (int i=1;i<=n;i++){
		if (i>ansl&&i<=ansr){
			printf ("1");
		}
		else printf ("%d",tr[i]);
		if (i<=n-1)printf (" ");
	}
	printf ("\n");
}