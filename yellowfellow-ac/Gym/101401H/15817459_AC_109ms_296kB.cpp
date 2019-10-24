#include<bits/stdc++.h>
using namespace std;
int ar[10005];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		ar[a-1]=i;
	}
	int ans=0;
	for (int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int dist=abs(ar[a-1]-ar[b-1]+n-1)%n;
		if (n%2==1){
			ans++;
		}
		else if (dist%2==1){
			ans++;
		}
	}
	printf ("%d\n",ans);
}