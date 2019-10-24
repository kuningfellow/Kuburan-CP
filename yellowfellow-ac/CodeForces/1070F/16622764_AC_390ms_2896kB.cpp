#include<bits/stdc++.h>
using namespace std;

priority_queue<int> sn,ns,nn;

int main(){
	int ban;
	scanf("%d",&ban);
	string tipe;
	int inv;
	long long  tot = 0;
	int banor = 0;
	for(int i = 0 ; i < ban ; i++){
		cin>>tipe;
		scanf("%d",&inv);
		if(tipe == "11") {
			tot += inv;
			banor ++;
		}
		else{
			if(tipe == "10") sn.push(inv);
			else if(tipe == "01") ns.push(inv);
			else nn.push(inv);
		}
	}
	while(!sn.empty() && !ns.empty()){
		tot += sn.top();
		tot += ns.top();
		sn.pop();
		ns.pop();
	}
	while(banor){
		if(!sn.empty()){
			if(!nn.empty()){
				if(sn.top() > nn.top()){
					tot += sn.top();
					sn.pop();
				}
				else{
					tot+= nn.top();
					nn.pop();
				}
			}
			else{
				tot += sn.top();
				sn.pop();
			}
			banor--;
		}
		else if(!ns.empty()){
			if(!nn.empty()){
				if(ns.top() > nn.top()){
					tot += ns.top();
					ns.pop();
				}
				else{
					tot+= nn.top();
					nn.pop();
				}
			}
			else{
				tot += ns.top();
				ns.pop();
			}
			banor--;
		}
		else if(!nn.empty()){
			tot+= nn.top();
			nn.pop();
			banor--;
		}
		else{
			break;
		}
	}
	printf("%lld\n",tot);
	return 0;
}