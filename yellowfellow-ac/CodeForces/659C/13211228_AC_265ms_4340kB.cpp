#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ar[n];
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar,ar+n);
	int t=0;
	vector<int>pick;
	int i=1;
	int j=0;
	while (m>0&&i<=m){
		if (j<n&&ar[j]==i){
			j++;
			i++;
			continue;
		}
		m-=(i);
		if (m>=0){
			pick.push_back(i);
		}
		i++;
	}
	printf ("%d\n",pick.size());
	for (int k=0;k<pick.size();k++){
		if (k!=0)printf (" ");
		printf ("%d",pick[k]);
	}
}