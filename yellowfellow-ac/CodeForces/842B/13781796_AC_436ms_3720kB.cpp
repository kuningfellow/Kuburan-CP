#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,d;
	cin>>r>>d;
	int n;
	cin>>n;
	int cnt=0;
	for (int i=0;i<n;i++){
		int x,y,l;
		cin>>x>>y>>l;
		double dist=sqrt(x*x+y*y);
		if (dist-l>=r-d&&dist+l<=r){
			cnt++;
		}
	}
	printf ("%d\n",cnt);
}