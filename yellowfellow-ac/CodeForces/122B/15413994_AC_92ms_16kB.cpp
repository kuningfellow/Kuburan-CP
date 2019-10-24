#include<bits/stdc++.h>
using namespace std;
int main(){
	char rem[55];
	scanf("%s",rem);
	int four=0;
	int seven=0;
	int ans=-1;
	for (int i=0;i<strlen(rem);i++){
		if (rem[i]=='4')four++;
		if (rem[i]=='7')seven++;
	}
	if (four>0)ans=4;
	if (seven>four){
		printf ("7\n");
	}
	else printf ("%d\n",ans);
}