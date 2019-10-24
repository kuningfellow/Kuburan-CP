#include<bits/stdc++.h>
using namespace std;
vector<int>filth;
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		filth.push_back(a);
	}
	sort(filth.begin(),filth.end());
	printf ("%d\n",filth[m-1]);
}