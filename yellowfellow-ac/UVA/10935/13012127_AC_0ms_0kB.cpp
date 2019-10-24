#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		queue<int>q;
		for (int i=0;i<n;i++){
			q.push(i+1);
		}
		int fir=1;
		printf ("Discarded cards:");
		while (q.size()>1){
			if (fir==0)printf (",");
			fir=0;
			printf (" %d",q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		printf ("\nRemaining card: %d\n",q.front());
	}
}