#include<bits/stdc++.h>
using namespace std;
int main(){
	int last=1;
	int prev=1;
	int n,m;
	int val=1;
	int maxi=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		maxi=max(maxi,b);
		if (i==0){
			maxi=max(maxi,a-1+b);
		}
		maxi=max(maxi,(a-prev+abs(b-last))/2+min(b,last));
		int delta=a-prev;
		if (delta<abs(b-last)&&i!=0){
			val=0;
		}
		prev=a;
		last=b;
	}
	maxi=max(maxi,(n-prev)+last);
	if (val==0)printf ("IMPOSSIBLE\n");
	else printf ("%d\n",maxi);
}