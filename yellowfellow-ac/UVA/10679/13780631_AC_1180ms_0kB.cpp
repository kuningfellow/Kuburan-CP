#include <bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	cin>>tc;
	while (tc--){
		char rem[100005];
		scanf("%s",rem);
		int el=strlen(rem);
		int q;
		cin>>q;
		while (q--){
			char ram[1005];
			scanf("%s",ram);
			int l=strlen(ram);
			int kmp[l],j=0;
			kmp[0]=0;
			for (int i=1;i<l;i++){
				while (j-1>=0&&ram[j]!=ram[i])j=kmp[j-1];
				if (ram[j]==ram[i])j++;
				kmp[i]=j;
			}
			j=0;
			int cnt=0;
			for (int i=0;i<el;i++){
				while (j-1>=0&&ram[j]!=rem[i])j=kmp[j-1];
				if (ram[j]==rem[i])j++;
				if (j==l){
					cnt=1;
					break;
				}
			}
			if (cnt==1)printf ("y\n");
			else printf ("n\n");
		}
	}
}