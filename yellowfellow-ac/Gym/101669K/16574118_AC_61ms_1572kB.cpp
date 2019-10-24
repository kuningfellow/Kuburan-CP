#include<bits/stdc++.h>
using namespace std;

pair<int,int> data[100005];
pair<int,int> has[100005];

int main(){
	int n,x;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&x);
		data[i].first = x;
		data[i].second = i;
	}
	sort(data+1,data+1+n);
	for(int i = 1 ; i <= n ; i ++){
		has[i].first = data[i].second;
		has[i].second = n-i+1;	
	}
	sort(has+1,has+n+1);
	for(int i = 1 ; i<= n ; i++){
		if(i!=1) printf(" ");
		printf("%d",has[i].second);	
	}
	printf("\n");
	return 0;	
}