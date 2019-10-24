//UVA 11225 Tarot scores.
#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc,kas=1;
	cin>>tc;
	while (tc--){
		int n;
		cin>>n;
		char rem[50];
		char of[4];
		char ram[50];
		int point=0;
		int debt=0;
		for (int i=0;i<n;i++){
			scanf("%s",rem);
			if (!strcmp(rem,"fool")){
				debt++;
				point+=9;
				continue;
			}
			scanf("%s",of);
			scanf("%s",ram);
			if (!strcmp(rem,"one")||!strcmp(rem,"twenty-one")){
				debt++;
				point+=9;
			}
			else if (!strcmp(rem,"king"))point+=9;
			else if (!strcmp(rem,"queen"))point+=7;
			else if (!strcmp(rem,"knight"))point+=5;
			else if (!strcmp(rem,"jack"))point+=3;
			else point+=1;
		}
		if (debt==3)debt=36;
		else if (debt==2)debt=41;
		else if (debt==1)debt=51;
		else if (debt==0)debt=56;
		point/=2;
		point-=debt;
		printf ("Hand #%d\nGame ",kas++);
		if (point<0)printf ("lost by %d point(s).\n",-point);
		else printf ("won by %d point(s).\n",point);
		if (tc!=0)printf ("\n");
	}
}