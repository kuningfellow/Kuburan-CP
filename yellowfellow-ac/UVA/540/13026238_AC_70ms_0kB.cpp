#include <bits/stdc++.h>
using namespace std;
int main(){
	int kas=1;
	while (1<2){
		int n;
		scanf("%d",&n);
		if (n==0)break;
		queue<int>sta[n];
		map<int,int>coun;
		map<int,int>ass;
		queue<int>qoq;
		map<int,int>av;
		for (int i=0;i<n;i++){
			int a,b;
			scanf("%d",&a);
			for (int j=0;j<a;j++){
				scanf("%d",&b);
				ass[b]=i;
			}
		}
		char rem[500];
		int x;
		printf ("Scenario #%d\n",kas++);
		while (1<2){
			scanf("%s",rem);
			if (!strcmp(rem,"STOP"))break;
			else if (!strcmp(rem,"ENQUEUE")){
				scanf("%d",&x);
				if (coun[x]==0){
					sta[ass[x]].push(x);
				}
				if (av[ass[x]]==0){
					qoq.push(ass[x]);
				}
				av[ass[x]]++;
				coun[x]++;
			}
			else if (!strcmp(rem,"DEQUEUE")){
				int x=qoq.front();
				av[x]--;
				if (av[x]==0){
					qoq.pop();
				}
				int prin=sta[x].front();
				coun[prin]--;
				if (coun[prin]==0){
					sta[x].pop();
				}
				printf ("%d\n",prin);
			}
		}
		printf ("\n");
	}
}