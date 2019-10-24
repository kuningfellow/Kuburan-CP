#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,d;
	cin>>r>>d;
	int n;
scanf("%d",&n);
	int cnt=0;
	for (int i=0;i<n;i++){
		int x,y,l;
scanf("%d%d%d",&x,&y,&l);
		double dist=sqrt(x*x+y*y);
		if (dist-l>=r-d&&dist+l<=r){
			cnt++;
		}
	}
	printf ("%d\n",cnt);
}