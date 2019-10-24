#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,o;
	cin>>c>>o;
	c-=(o-1);
	if (c<0||o==0){
		printf ("No\n");
	}
	else{
		if (c==0||(c%2==0&&o>1)){
			printf ("Yes\n");
		}
		else{
			printf ("No\n");
		}
	}
}