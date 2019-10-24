#include<bits/stdc++.h>
using namespace std;

#define mini(a,b) (a)<(b)?(a):(b)

pair<int,int> data[2005];
int has[2005];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	int k,pel;
	scanf("%d%d",&k,&pel);
	for(int i=0;i<pel;i++){
		int ang;
		scanf("%d",&ang);
		data[i].first=ang;
		data[i].second=i;
	}
	sort(data,data+pel);
	for(int i=0;i<pel;i++){
		has[data[i].second]=mini(data[i].first,k);
		k-=has[data[i].second];
		if(k==0)break;
	}
	for(int i=0;i<pel;i++){
		printf("%d",has[i]);
		if(i!=pel-1)printf(" ");
	}
	printf("\n");
	return 0;
}