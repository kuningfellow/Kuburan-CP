#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char rem[1000005];
int main(){
	int tc;
	cin>>tc;
	int kas=1;
	while (tc--){
		scanf("%s",rem);
		int cnt=0;
		int temp=0;
		int val=1;
		int l=strlen(rem);
		int j=0;
		for (int i=0;i<l;i++){
			if (rem[i]=='c'){
				j=i;
				break;
			}
			if (rem[i]!='c'&&rem[i]!='f'){
				val=0;
				break;
			}
			temp++;
		}
		for (int i=l-1;i>=j;i--){
			if (rem[i]=='f'){
				temp++;
			}
			else if (rem[i]=='c'){
				if (temp<2){
					val=0;
					break;
				}
				temp=0;
				cnt++;
			}
			else{
				val=0;
				break;
			}
		}
		printf ("Case #%d: ",kas++);
		if (val){
			if (cnt==0){
				printf ("%d\n",l/2+(l%2>0));
			}
			else{
				printf ("%d\n",cnt);
			}
		}
		else printf ("-1\n");
	}
}