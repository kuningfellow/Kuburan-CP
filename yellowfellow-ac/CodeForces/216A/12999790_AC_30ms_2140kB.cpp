#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int l=b*c;
	l+=(a-1)*(b+c-1);
	printf ("%d\n",l);
}