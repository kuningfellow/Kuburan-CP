#include<bits/stdc++.h>
using namespace std;

map<string , bool> data[10005];
map<string,int> ada;
map<string,string> simp;

int main(){
	int n;
	scanf("%d",&n);
	string s,now;
	int sz; 
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		sz = s.size();
		for(int j = 0 ; j < sz; j ++){
			now = "";
			for(int k = j ; k < sz; k++){
				now += s[k];
				if(data[i].count(now) > 0)continue;
				data[i][now] = true;
				ada[now]++;
				simp[now] = s;
			}
		}
	}
	int q;
	string que;
	scanf("%d",&q);
	int ans ;
	for(int i = 0 ; i < q ; i++){
		cin>>que;
		ans = ada[que];
		printf("%d ",ans);
		if(ans == 0) printf("-\n");
		else cout << simp[que] <<endl;
	}
	return 0;
}