#include <bits/stdc++.h>
using namespace std;
int n;
int ar[1005];
void revel(int x){
	if (x==n)return;
	revel(x+1);
	int temp=ar[x];
	ar[x]=ar[x-1];
	ar[x-1]=temp;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		ar[i]=i+1;
	}
	revel(1);
	for (int i=0;i<n;i++){
		printf ("%d",ar[i]);
		if (i<n-1)printf (" ");
		else printf ("\n");
	}
}