#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int datasetnumber;
		cin>>datasetnumber;
		vector<int>seq;
		int n;
		scanf("%d",&n);
		int a=1,b=1;
		int tmp=n;
		vector<int>step;
		while (n>1){
			if (n%2==1){
				step.push_back(1);
			}
			else{
				step.push_back(0);
			}
			n/=2;
		}
		for (int i=step.size()-1;i>=0;i--){
			if (step[i]==1){
				a+=b;
			}
			else{
				b+=a;
			}
		}
		printf ("%d %d/%d\n",datasetnumber,a,b);
	}
}