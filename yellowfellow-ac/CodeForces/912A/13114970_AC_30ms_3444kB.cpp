#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int a,b;
	cin>>a>>b;
	long long int x,y,z;
	cin>>x>>y>>z;
	long long int ra=0,rb=0;
	ra+=x*2+y;
	rb+=y+z*3;
	printf ("%lld\n",max(0ll,ra-a)+max(0ll,rb-b));
}