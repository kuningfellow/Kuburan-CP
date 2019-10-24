#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>lis;
	while(n>0){
		if (n%2==1&&n>2){
			lis.push_back(3);
			n-=3;
		}
		else if (n>1) {
			lis.push_back(2);
			n-=2;
		}
	}
	printf ("%d\n",lis.size());
	sort(lis.begin(),lis.end());
	for (int i=0;i<lis.size();i++){
		if (i!=0)printf (" ");
		printf ("%d",lis[i]);
	}
	printf ("\n");
}