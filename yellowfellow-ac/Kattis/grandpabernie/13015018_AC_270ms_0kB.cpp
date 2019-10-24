#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	map<string,vector<int> >ma;
	string rem;
	int year;
	for (int i=0;i<n;i++){
		cin>>rem>>year;
		ma[rem].push_back(year);
	}
	for (map<string,vector<int> >::iterator it=ma.begin(); it!=ma.end() ; it++){
		sort(it->second.begin(),it->second.end());
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		cin>>rem>>year;
		printf ("%d\n",ma[rem][year-1]);
	}
}