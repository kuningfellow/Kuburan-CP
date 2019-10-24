#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	printf ("%d\n",max(n/2+(n%2>0)-1,0));
}