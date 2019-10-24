#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f,g,h,i;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	a=(b+c+f+h-d-g)/2;
	e=a+g-f;
	i=a+d-h;
	printf ("%d %d %d\n%d %d %d\n%d %d %d\n",a,b,c,d,e,f,g,h,i);
}