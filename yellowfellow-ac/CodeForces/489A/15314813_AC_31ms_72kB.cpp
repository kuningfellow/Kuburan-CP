#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ar[n];
	for (int i=0;i<n;i++){
		scanf("%d",ar+i);
	}
	vector<pair<int,int> >ans;
	for (int i=0;i<n-1;i++){
		int found=-1;
		for (int j=i+1;j<n;j++){
			if (found==-1||ar[j]<ar[found]){
				found=j;
			}
		}
		if (ar[found]>=ar[i])continue;
		ar[i]^=ar[found]^=ar[i]^=ar[found];
		ans.push_back(pair<int,int>(i,found));
	}
	printf ("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf ("%d %d\n",ans[i].first,ans[i].second);
	}
}