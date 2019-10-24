#include<bits/stdc++.h>
using namespace std;
int main(){
	int p,n;
	cin>>p>>n;
	map<int,int>hash;
	int ans=-1;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		if (hash[a%p]==1&&ans==-1){
			ans=i+1;
		}
		hash[a%p]=1;
	}
	printf ("%d\n",ans);
}