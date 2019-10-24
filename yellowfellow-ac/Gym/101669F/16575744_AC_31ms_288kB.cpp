#include<bits/stdc++.h>
using namespace std;

long long c[5005];

string fr,to;

priority_queue<long long> ic,d,te,icc,dd;

int main(){
	int n;
	scanf("%d",&n);
	for(int i= 0 ; i < n ; i ++){
		scanf("%lld",&c[i]);	
	}
	cin>>fr>>to;
	unsigned long long cost = 0;
	for(int i = 0 ; i < n ; i++){
		if(fr[i] == '1' && to[i] == '1'){
			te.push(c[i]);
		}
		else if(fr[i]=='1') {
			d.push(c[i]);
			dd.push(c[i]);
		}
		else if(to[i]=='1') {
			ic.push(-c[i]);
			icc.push(-c[i]);
		}
		if(fr[i]=='1')cost += c[i];
	}
	unsigned long long tmp = cost, tmp2 = cost , cost2 =0 ;
	cost =0;
	while(!d.empty()){
		if(te.empty() || d.top() > te.top() || d.size() == 1 ) {
			tmp -= d.top();
			d.pop();
		}
		else{
			tmp -= te.top();
			ic.push(-te.top());
			te.pop();
		}
		cost += tmp;	
	}
	while(!ic.empty()){
		tmp -= ic.top();
		ic.pop();
		cost += tmp;
	}
	
	while(!dd.empty()){
		if(te.empty() || dd.top() > te.top() || dd.size() == 1 ) {
			tmp2 -= dd.top();
			dd.pop();
		}
		else{
			tmp2 -= te.top();
			icc.push(-te.top());
			te.pop();
		}
		cost2 += tmp2;	
	}
	while(!icc.empty()){
		tmp2 -= icc.top();
		icc.pop();
		cost2 += tmp2;
	}
	printf("%llu\n",min(cost,cost2));
	return 0;	
}