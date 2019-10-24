#include <bits/stdc++.h>
using namespace std;
long long int n;
int fin(long long int x){
	if (x==n)return 1;
	if (x<=0)return 0;
	if ((x-3)%3==0)return fin((x-3)/3);
	else return 0;
}
int main(){
	cin>>n;
	long long int pow=2;
	int stat=0;
	for (int i=0;i<60;i++){
		stat=max(fin(pow),stat);
		if (stat==1){
			break;
		}
		pow*=2;
	}
	if (stat==0&&n>1)printf ("NIE\n");
	else printf ("TAK\n");
}