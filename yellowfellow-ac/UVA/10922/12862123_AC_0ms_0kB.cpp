#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[5000];
	while (scanf("%s",rem)!=EOF){
		if (strlen(rem)==1&&rem[0]=='0'){
			break;
		}
		int sum=0;
		for (int i=strlen(rem)-1;i>=0;i--){
			sum+=rem[i]-'0';
		}
		if (sum%9!=0){
			printf ("%s is not a multiple of 9.\n",rem);
		}
		else{
			int deg=1;
			while (sum>9){
				int temp=0;
				while (sum>0){
					temp+=sum%10;
					sum/=10;
				}
				sum=temp;
				deg++;
			}
			printf ("%s is a multiple of 9 and has 9-degree %d.\n",rem,deg);
		}
	}
}