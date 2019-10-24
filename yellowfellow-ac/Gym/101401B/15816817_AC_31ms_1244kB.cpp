#include<bits/stdc++.h>
using namespace std;
char rem[200005];
int smi[200005];
int main(){
	scanf("%s",rem);
	int l =strlen(rem);
	int car=0;
	for (int i=l-2;i>=0;i--){
		if (rem[i]==':'&&rem[i+1]==')'){
			car++;
		}
		smi[i]=car;
	}
	int ans=smi[0];
	car=0;
	for (int i=0;i<l;i++){
		if (i>0&&rem[i-1]=='('&&rem[i]==':'){
			car++;
		}
		int cur=car;
		if (i<l-1){
			cur+=smi[i+1];
		}
		if (rem[0]==':'&&rem[i+1]==')'){
			cur++;
		}
		ans=max(ans,cur);
	}
	ans=max(ans,car);
	printf("%d\n",ans);
}