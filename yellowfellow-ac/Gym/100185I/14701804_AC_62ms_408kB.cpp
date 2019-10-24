#include<bits/stdc++.h>
using namespace std;
int main(){
	char rem[10005];
	scanf("%[^\n]",rem);
	getchar();
	int n;
	cin>>n;
	getchar();
	vector<string>cont[n];
	for (int i=0;i<n;i++){
		scanf("%[^\n]",rem);
		getchar();
		int l=strlen(rem);
		string str="";
		for (int j=0;j<l;j++){
			str.push_back(rem[j]);
			if (rem[j]==','){
				cont[i].push_back(str);
				str="";
			}
		}
		cont[i].push_back(str);
	}
	int coun=1000000;
	for (int i=0;i<n;i++){
		int tmp=0;
		for (int j=0;j<n;j++){
			if (i==j)continue;
			int cur=0;
			for (int k=0;k<cont[i].size();k++){
				if (cont[i][k]!=cont[j][k]){
					cur++;
				}
			}
			tmp=max(tmp,cur);
		}
		coun=min(coun,tmp);
	}
	for (int i=0;i<n;i++){
		int tmp=0;
		for (int j=0;j<n;j++){
			if (i==j)continue;
			int cur=0;
			for (int k=0;k<cont[i].size();k++){
				if (cont[i][k]!=cont[j][k])
					cur++;
			}
			tmp=max(cur,tmp);
		}
		if (tmp==coun){
			for (int j=0;j<cont[i].size();j++){
				cout<<cont[i][j];
			}
			cout<<endl;
		}
	}
}