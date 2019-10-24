#include<bits/stdc++.h>
using namespace std;
char rem[100005];
char ram[100005];
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	int found=0;
	for (int i=0;i<n;i++){
		scanf("%s",rem);
		int l=strlen(rem);
		if (rem[0]=='0'){
			printf ("0\n");
			return 0;
		}
		else{
			int tog=0;
			int tmp=0;
			for (int j=0;j<l;j++){
				if (!found){
					ram[j]=rem[j];
					ram[j+1]='\0';
				}
				if ((rem[j]!='0'&&rem[j]!='1')||(rem[j]=='1'&&j>0)){
					tog=1;
				}
				else if (rem[j]=='0'){
					tmp++;
				}
			}
			if (tog)found=1;
			if (!tog)cnt+=tmp;
		}
	}
	if (found)printf ("%s",ram);
	else printf ("1");
	while(cnt--){
		printf ("0");
	}
}