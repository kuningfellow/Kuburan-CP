#include <bits/stdc++.h>
using namespace std;
stack<int>st;
int main(){
	int n;
	scanf("%d",&n);
	int a,b;
	for (int i=0;i<n;i++){
		scanf("%d",&a);
		if (a==1){
			scanf("%d",&b);
			st.push(b);
		}
		if (a==2){
			if (!st.empty())
			st.pop();
		}
		if (a==3){
			if (st.empty()){
				printf ("Empty!\n");
			}
			else printf ("%d\n",st.top());
		}
	}
}