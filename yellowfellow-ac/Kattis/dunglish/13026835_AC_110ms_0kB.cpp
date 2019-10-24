#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string>lis;
	string rem,ram,emi;
	for (int i=0;i<n;i++){
		cin>>rem;
		lis.push_back(rem);
	}
	int tr;
	cin>>tr;
	map<string,vector<pair<string,int> > >trans;
	for (int i=0;i<tr;i++){
		cin>>rem>>ram>>emi;
		if (emi=="correct"){
			trans[rem].push_back(pair<string,int>(ram,1));
		}
		else{
			trans[rem].push_back(pair<string,int>(ram,0));
		}
	}
	int un=1;
	long long int cor=1;
	long long int fals=1;
	for (int i=0;i<n;i++){
		if (trans[lis[i]].size()>1){
			un=0;
			long long int ta=0,tb=0;
			for (int j=0;j<trans[lis[i]].size();j++){
				if (trans[lis[i]][j].second==0){
					tb++;
				}
				else ta++;
			}
			cor*=(ta);
			fals*=(ta+tb);
		}
	}
	int good=1;
	if (un==1){
		for (int i=0;i<n;i++){
			if (i>0)cout<<" ";
			cout<<trans[lis[i]][0].first;
			if (trans[lis[i]][0].second==0){
				good=0;
			}
		}
		if (good==0)printf ("\nincorrect\n");
		else printf ("\ncorrect\n");
	}
	else{
		printf ("%lld correct\n%lld incorrect\n",cor,fals-cor);
	}
}