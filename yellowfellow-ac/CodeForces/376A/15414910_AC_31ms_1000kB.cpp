#include<bits/stdc++.h>
using namespace std;
char rem[1000005];
int main(){
	long long int totl=0;
	long long int totr=0;
	scanf("%s",rem);
	int l=strlen(rem);
	int mid=-1;
	for (int i=0;i<l;i++){
		if (rem[i]=='^'){
			mid=i;
		}
	}
	for (int i=mid+1;i<l;i++){
		if (rem[i]>='0'&&rem[i]<='9'){
			totr+=(i-mid)*(rem[i]-'0');
		}
	}
	for (int i=0;i<mid;i++){
		if (rem[i]>='0'&&rem[i]<='9'){
			totl+=(mid-i)*(rem[i]-'0');
		}
	}
	if (totl==totr)printf ("balance\n");
	else if (totl<totr)printf ("right\n");
	else if (totl>totr)printf ("left\n");
}