#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		int datasetnumber;
		cin>>datasetnumber;
		vector<int>seq;
		int a,b;
		scanf("%d/%d",&a,&b);
		while (a!=1||b!=1){
			if (a>b){
				a-=b;
				seq.push_back(1);
			}
			else{
				b-=a;
				seq.push_back(0);
			}
		}
		int k=1;
		for (int i=seq.size()-1;i>=0;i--){
//			printf ("%d ",seq[i]);
			if (seq[i]==1)
				k=k*2+1;
			else k*=2;
		}
		printf ("%d %d\n",datasetnumber,k);
	}
}