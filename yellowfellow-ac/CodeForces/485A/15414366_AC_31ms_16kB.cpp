#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,m;
	cin>>a>>m;
	int stop=0;
	for (int i=0;i<m;i++){
		a=a+a%m;
		a%=m;
		if (a%m==0){
			stop=1;
		}
	}
	if (stop)printf ("Yes\n");
	else printf ("No\n");
}