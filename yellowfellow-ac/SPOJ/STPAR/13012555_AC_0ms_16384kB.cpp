#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		queue<int>q;
		stack<int>s;
		int a;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			q.push(a);
		}
		int yes=1;
		int j=1;
		while (j<=n&&!q.empty()){
			if (!s.empty()&&s.top()==j){
				s.pop();
				j++;
			}
			else if (q.front()!=j){
				s.push(q.front());
				q.pop();
			}
			else if (q.front()==j){
				q.pop();
				j++;
			}
		}
		while (j<=n&&!s.empty()){
			if (!s.empty()&&s.top()==j){
				s.pop();
				j++;
			}
			else break;
		}
		if (j==n+1){
			printf ("yes\n");
		}
		else printf ("no\n");
		
	}
}