#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[1000];
	scanf("%s",rem);
	int l=strlen(rem);
	int cou[26];
	for (int i=0;i<26;i++)cou[i]=0;
	for (int i=0;i<l;i++){
		cou[rem[i]-'a']++;
	}
	priority_queue<int>q;
	for (int i=0;i<26;i++){
		if (cou[i]!=0)
		q.push(-cou[i]);
	}
	int cost=0;
	while (q.size()>2){
		cost+=-q.top();
		q.pop();
	}
	printf ("%d\n",cost);
}