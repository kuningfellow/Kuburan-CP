#include <bits/stdc++.h>
using namespace std;
char rem[100005];
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	scanf("%s",rem);
	int le=strlen(rem);
	int B=0;
	int u=0;
	int l=0;
	int b=0;
	int a=0;
	int s=0;
	int r=0;
	for (int i=0;i<le;i++){
		if (rem[i]=='B')B++;
		if (rem[i]=='b')b++;
		if (rem[i]=='l')l++;
		if (rem[i]=='u')u++;
		if (rem[i]=='a')a++;
		if (rem[i]=='s')s++;
		if (rem[i]=='r')r++;
	}
	int made=100000;
	made=min(made,B);
	made=min(made,u/2);
	made=min(made,l);
	made=min(made,b);
	made=min(made,a/2);
	made=min(made,s);
	made=min(made,r);
	printf ("%d\n",made);
}