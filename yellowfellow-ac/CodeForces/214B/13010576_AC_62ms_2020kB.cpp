#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int flag=0;
	int a;
	int sum=0;
	int coun[10];
	for (int i=0;i<10;i++)coun[i]=0;
	for (int i=0;i<n;i++){
		scanf("%d",&a);
		if (a==0)flag=1;
		coun[a]++;
		sum+=a;
	}
	if (flag==0){
		printf ("-1\n");
	}
	else{
		for (int i=1;i<9;i++){
			if (i%3==0)continue;
			if (i%3==sum%3&&coun[i]>0){
				coun[i]--;
				sum=0;
			}
			if (sum==0)break;
		}
		if (sum%3!=0){
			for (int i=1;i<9;i++){
				if (i%3==0)continue;
				for (int j=1;j<9;j++){
					if (j%3==0)continue;
					if (sum%3==(i%3+j%3)%3){
						if ((i==j&&coun[i]>1)||i!=j&&coun[i]>0&&coun[j]>0){
						coun[i]--;
						coun[j]--;
						sum=0;
						}
					}
				}
			}
		}
		flag=0;
		for (int i=9;i>=0;i--){
			if (i!=0&&coun[i]>0)flag=1;
			if (flag==0&&i==0){
				printf ("0");
				break;
			}
			for (int j=0;j<coun[i];j++){
				printf ("%d",i);
			}
		}
		printf ("\n");
	}
}