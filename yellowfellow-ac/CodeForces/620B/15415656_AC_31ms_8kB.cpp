#include<bits/stdc++.h>
using namespace std;
int main(){
	int ar[10]={6,2,5,5,4,5,6,3,7,6};
	int a,b;
	cin>>a>>b;
	long long int ans=0;
	for (int i=a;i<=b;i++){
		int tmp=i;
		while (tmp>0){
			ans+=ar[tmp%10];
			tmp/=10;
		}
	}
	printf ("%d\n",ans);
}