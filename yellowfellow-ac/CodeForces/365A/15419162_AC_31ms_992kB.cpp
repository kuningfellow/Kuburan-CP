#include<bits/stdc++.h>
using namespace std;
char rem[1000005];
int main(){
	int n,k;
	cin>>n>>k;
	int good=0;
	for (int i=0;i<n;i++){
		scanf("%s",rem);
		int l=strlen(rem);
		int rec=k+1;
		int cnt[10];
		for (int j=0;j<10;j++){
			cnt[j]=0;
		}
		for (int j=0;j<l;j++){
			if (cnt[rem[j]-'0']==0){
				cnt[rem[j]-'0']=1;
				if (rem[j]-'0'<=k){
					rec--;
				}
			}
		}
		if (rec==0){
			good++;
		}
	}
	printf ("%d\n",good);
}