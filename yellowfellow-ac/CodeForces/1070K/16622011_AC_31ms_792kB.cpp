#include<bits/stdc++.h>
using namespace std;

int data[100005],ban[100005];

int main(){
	int n,k;
	long long tot = 0;
	scanf("%d%d",&n,&k);
	for(int i= 0 ; i < n ; i++){
		scanf("%d",&data[i]);
		tot += data[i];
	}
	if(tot%k != 0 ) printf("No\n");
	else{
		bool flag = true;
		long long midi = tot / k,now = 0; 
		int idx = 0;
		for(int i = 0 ; i  < n ; i++){
			now += data[i];
			ban[idx]++;
			if(now > midi ){
				flag = false;
				break;
			}
			if(now == midi){
				now = 0;
				idx++;
			}
		}
		if(!flag) printf("No\n");
		else{
			printf("Yes\n");
			for(int i = 0 ; i < k ; i ++){
				if(i!=0) printf(" ");
				printf("%d",ban[i]);
			}
		}
	}
	return 0;
	
}