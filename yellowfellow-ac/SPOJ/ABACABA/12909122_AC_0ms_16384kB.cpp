#include <bits/stdc++.h>
using namespace std;
void rec(int a){
	if (a==1)printf ("A");
	else{
		rec(a-1);
		printf ("%c",a-1+'A');
		rec(a-1);
	}
}
int main(){
	int n;
	cin>>n;
	rec(n);
}