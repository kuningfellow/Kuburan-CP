#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int sz;
long long res[1005];
long long x;

int main(){
	int n;
	for(int i = 0 ; i < 1003 ; i ++) res[i] = 10000000000000000;
	scanf("%d",&n);
	for(int i = 0 ; (1<<i) <= n ; i ++ ){
		v.clear();
		for(int j = 1 ; j <= n ; j++){
			if(j & (1<<i)) v.push_back(j);
		}
		sz = v.size();
		if(sz == 0) continue;
		printf("%d\n",sz);
		fflush(stdout);
		for(int j = 0 ; j < sz; j ++){
			if(j!= 0 ) {
				printf(" ");
				fflush(stdout);
			}
			printf("%d",v[j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
		for(int j = 1 ; j <=n; j ++){
			scanf("%lld",&x);
			if((j & (1<<i)) == 0) res[j] = min(res[j],x);
		}
	}
	for(int i = 0 ; (1<<i) <= n ; i ++ ){
		v.clear();
		for(int j = 1 ; j <= n ; j++){
			if((j & (1<<i)) == 0 ) v.push_back(j);
		}
		sz = v.size();
		printf("%d\n",sz);
		fflush(stdout);
		for(int j = 0 ; j < sz; j ++){
			if(j!= 0 ){
				printf(" ");
				fflush(stdout);
			} 
			printf("%d",v[j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
		for(int j = 1 ; j <=n; j ++){
			scanf("%lld",&x);
			if(j & (1<<i) ) res[j] = min(res[j],x);
		}
	}
	printf("-1\n");
	fflush(stdout);
	for(int i = 1 ; i <= n ; i++) {
		if(i!= 1 ) {
			printf(" ");
			fflush(stdout);
		}
		printf("%d",res[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}