#include <bits/stdc++.h>
using namespace std;
int main(){
	while (1<2){
		int a,b;
		scanf("%d%d",&a,&b);
		if (a==0&&b==0)break;
		priority_queue<int>rem;
		priority_queue<int>ram;
		int x;
		for (int i=0;i<a;i++){
			scanf("%d",&x);
			rem.push(x);
		}
		for (int i=0;i<b;i++){
			scanf("%d",&x);
			ram.push(x);
		}
		int sam=0;
		while (!rem.empty()&&!ram.empty()){
			if (rem.top()==ram.top()){
				sam++;
				ram.pop();
				rem.pop();
			}
			else if (rem.top()>ram.top()){
				rem.pop();
			}
			else ram.pop();
		}
		printf ("%d\n",sam);
	}
}