#include<bits/stdc++.h>
using namespace std;
int ar[1005];
int deg[1005];
int mark[1005];
vector<int>nums;
int bv;
int bvc;
int serc(int x, int mode, int car){
	if (x==bv){
		mode=0;
	}
	int ret=0;
	if (ar[x]==0&&mode==1){
		nums.push_back(car+1);
		return 1;
	}
	else if (ar[x]==0 && mode==0){
		ret=1;
	}
	else{
		ret=1+serc(ar[x],mode,car+1);
	}
	if (x==bv){
		bvc=ret;
	}
	return ret;
}
int main(){
	int n;
	cin>>n>>bv;
	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
		deg[ar[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (deg[i]==0){
			serc(i,1,0);
		}
	}
	mark[0]=1;
	for (int i=0;i<nums.size();i++){
		for (int j=1004;j>=0;j--){
			if (j-nums[i]>=0&&mark[j-nums[i]]==1){
				mark[j]=1;
			}
		}
	}
	for (int i=0;i<1005;i++){
		if (mark[i]==1){
			printf ("%d\n",bvc+i);
		}
	}
}