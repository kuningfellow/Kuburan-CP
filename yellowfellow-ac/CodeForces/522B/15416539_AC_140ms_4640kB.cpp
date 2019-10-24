#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int> >lis;
	int ar[n];
	int ans[n];
	int sum=0;
	for (int i=0;i<n;i++){
		int a;
		scanf("%d%d",&ar[i],&a);
		sum+=ar[i];
		lis.push_back(pair<int,int>(a,i));
	}
	sort(lis.begin(),lis.end());
	int maxi=lis[lis.size()-1].first;
	int maxicnt=0;
	for (int i=0;i<lis.size();i++){
		if (lis[i].first==maxi)maxicnt++;
	}
	for (int i=lis.size()-1;i>=0;i--){
		if (maxicnt>1){
			ans[lis[i].second]=(sum-ar[lis[i].second])*maxi;
		}
		else{
			if (lis[i].first==maxi){
				ans[lis[i].second]=(sum-ar[lis[i].second])*lis[lis.size()-2].first;
			}
			else{
				ans[lis[i].second]=(sum-ar[lis[i].second])*maxi;
			}
		}
	}
	for (int i=0;i<n;i++){
		printf ("%d ",ans[i]);
	}
}