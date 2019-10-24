#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	int fir=1;
	while (tc--){
		priority_queue<int>hi;
		priority_queue<int>lo;
		int n,m;
		cin>>n>>m;
		int ar[n];
		int qr[m];
		for (int i=0;i<n;i++){
			cin>>ar[i];
		}
		for (int i=0;i<m;i++){
			cin>>qr[i];
		}
		int j=0;
		int flag=0;
		if (fir==0)printf ("\n");
		fir=0;
		for (int i=0;i<m;i++){
			while (j<qr[i]){
				if (flag==1||lo.empty()){
					lo.push(ar[j]);
				}
				else if (ar[j]<lo.top()){
					hi.push(-lo.top());
					lo.pop();
					lo.push(ar[j]);
				}
				else{
					hi.push(-ar[j]);
				}
				flag=0;
				j++;
			}
			printf ("%d\n",lo.top());
			if (!hi.empty()){
				int tem=-hi.top();
				hi.pop();
				lo.push(tem);
				flag=0;
			}
			else flag=1;
		}
	}
	
}