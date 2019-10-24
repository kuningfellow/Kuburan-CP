#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char rem[50];
	scanf("%s",rem);
	int cnt=0;
	for (int i=0;i<10;i++){
		int x=i/3;
		int y=i%3;
		if (i==9){
			x=3;
			y=1;
		}
		int val=1;
		for (int j=1;j<n;j++){
			int af=rem[j]-'0'-1;
			int bf=rem[j-1]-'0'-1;
			int ax=af/3;
			int ay=af%3;
			int bx=bf/3;
			int by=bf%3;
			if (af==-1){
				ax=3;
				ay=1;
			}
			if (bf==-1){
				bx=3;
				by=1;
			}
			x+=ax-bx;
			y+=ay-by;
			if (x<0)val=0;
			if (y<0||y>2)val=0;
			if (x>2&&y!=1)val=0;
			if (x>3)val=0;
			if (val==0)break;
		}
		cnt+=val;
	}
	if (cnt==1)printf ("YES\n");
	else printf ("NO\n");
}