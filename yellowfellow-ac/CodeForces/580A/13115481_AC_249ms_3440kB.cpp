#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,prev,ans=1,tmp=1;
	cin>>n;
	cin>>prev;
	for (int i=1;i<n;i++){
		cin>>a;
		if (a>=prev){
			tmp++;
			ans=max(ans,tmp);
		}
		else{
			tmp=1;
		}
		prev=a;
	}
	printf ("%d\n",ans);
}