#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	printf ("%d\n",min(c,max(0,a/2+b)));
}