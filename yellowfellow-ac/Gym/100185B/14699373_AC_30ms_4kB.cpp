#include<bits/stdc++.h>
using namespace std;
int main(){
	char rem[1005];
	scanf("%s",rem);
	int cnt[26];
	for (int i=0;i<26;i++){
		cnt[i]=0;
	}
	for (int i=0;i<strlen(rem);i++){
		cnt[rem[i]-'a']++;
	}
	int bonus=1;
	int cost=0;
	for (int i=0;i<26;i++){
		if (cnt[i]%2!=0){
			if (bonus==1){
				bonus=0;
			}
			else{
				cost++;
			}
		}
	}
	printf ("%d\n",cost);
}