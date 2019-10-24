#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char rem[n][105];
	vector<int>lis[n][26];
	for (int i=0;i<n;i++){
		scanf("%s",rem[i]);
		int l=strlen(rem[i]);
		for (int j=0;j<l;j++){
			lis[i][rem[i][j]-'a'].push_back(j);
		}
	}
	char ram[4];
	for (int i=0;i<m;i++){
		scanf("%s",ram);
		int found=0;
		for (int j=0;j<n;j++){
			int idx=-1;
			int hash;
			for (int k=0;k<3;k++){
				int l=0;
				hash=ram[k]-'A';
				while (l<lis[j][hash].size()&&lis[j][hash][l]<=idx){
					l++;
				}
				if (l==lis[j][hash].size()){
					break;
				}
				idx=lis[j][hash][l];
				if (k==2){
					found=1;
					printf ("%s\n",rem[j]);
				}
			}
			if (found)break;
		}
		if (found==0){
			printf ("No valid word\n");
		}
	}
}