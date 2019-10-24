#include <bits/stdc++.h>
using namespace std;
int func(int x){
	if (x<=100){
		int a=func(x+11);
		return func(a);
	}
	else{
		return x-10;
	}
}
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		printf ("f91(%d) = %d\n",n,func(n));
	}
}