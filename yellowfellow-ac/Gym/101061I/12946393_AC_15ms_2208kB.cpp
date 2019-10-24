#include <bits/stdc++.h>
using namespace std;
		char rem[100005];
		char ram[100005];
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		scanf("%s",rem);
		scanf("%s",ram);
		int ar[26];
		int br[26];
		for (int i=0;i<26;i++){
			ar[i]=0;
			br[i]=0;
		}
		int l=strlen(rem);
		for (int i=0;i<l;i++){
			ar[rem[i]-'a']++;
		}
		l=strlen(ram);
		for (int i=0;i<l;i++){
			br[ram[i]-'a']++;
		}
		int del;
		for (int i=0;i<26;i++){
			del=min(br[i],ar[i]);
			br[i]-=del;
			ar[i]-=del;
		}
		int mo=0;
		for (int i=0;i<26;i++){
			mo+=br[i]+ar[i];
		}
		printf ("%d\n",mo);
	}
}