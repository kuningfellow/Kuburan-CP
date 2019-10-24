#include <bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		map<int,int>kil;
		priority_queue<int>pq;
		queue<int>m;
		queue<int>q;
		int n,k,a;
		cin>>n>>k;
		for (int i=0;i<n;i++){
			cin>>a;
			q.push(a);
			pq.push(a);
			if (i==k)m.push(1);
			else m.push(0);
		}
		int co=0;
		int con=1;
		while (!q.empty()&&con){
			while (q.front()<pq.top()){
				q.push(q.front());
				q.pop();
				m.push(m.front());
				m.pop();
			}
			if (q.front()==pq.top()){
				pq.pop();
				q.pop();
				co++;
				if (m.front()==1){
					con=0;
				}
				m.pop();
			}
		}
		printf ("%d\n",co);
	}
}