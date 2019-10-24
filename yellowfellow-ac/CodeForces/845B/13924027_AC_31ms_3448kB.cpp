#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int num1[3];
	int num2[3];
	char rem[8];
	int sum1=0;
	int sum2=0;
	scanf("%s",rem);
	for (int i=0;i<3;i++){
		num1[i]=rem[i]-'0';
	}
	for (int i=3;i<6;i++){
		num2[i-3]=rem[i]-'0';
	}
	sort(num1,num1+3);
	sort(num2,num2+3);
	sum1=num1[0]+num1[1]+num1[2];
	sum2=num2[0]+num2[1]+num2[2];
	int cnt=0;
	while (sum1!=sum2){
		if (sum1<sum2){
			if (9-num1[0]<num2[2]){
				cnt++;
				int del=sum2-sum1;
				num2[2]-=min(del,num2[2]);
			}
			else{
				cnt++;
				int del=sum2-sum1;
				num1[0]+=min(del,9-num1[0]);
			}
		}
		else{
			if (9-num2[0]<num1[2]){
				cnt++;
				int del=sum1-sum2;
				num1[2]-=min(del,num1[2]);
			}
			else{
				cnt++;
				int del=sum1-sum2;
				num2[0]+=min(del,9-num2[0]);
			}
		}
		sort(num1,num1+3);
		sort(num2,num2+3);
		sum1=num1[0]+num1[1]+num1[2];
		sum2=num2[0]+num2[1]+num2[2];
	}
	printf ("%d\n",cnt);
}