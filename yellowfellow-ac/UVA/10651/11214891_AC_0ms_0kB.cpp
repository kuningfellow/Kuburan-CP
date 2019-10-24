#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int dp[1<<13];

bool check(int mask){
	for(int i=0;i<=9;i++){
		if(mask&(1<<i) && mask&(1<<(i+1)) && !(mask&(1<<(i+2)))) return false;
	}
	
	for(int i=11;i>=2;i--){
		if(mask&(1<<i) && mask&(1<<(i-1)) && !(mask&(1<<(i-2)))) return false;
	}
	return true;
}

int kill(int mask)
{
	//base case
	if(check(mask)){
		int cnt=0;
		while(mask>0){
			cnt+=mask%2;
			mask/=2;
		}
		return cnt;
	}
	//check dp
	if(dp[mask]!=-1) return dp[mask];
	//transisi
	int tmp=100;
	for(int i=0;i<=9;i++){
		if(mask&(1<<i) && mask&(1<<(i+1)) && !(mask&(1<<(i+2))))
		{
			int temp=mask;
			temp=temp^(1<<i);
			temp=temp^(1<<(i+1));
			temp=temp^(1<<(i+2));
			tmp=min(tmp,kill(temp));
		}
	}
	for (int i=11;i>=2;i--)
	{
		if(mask&(1<<i) && mask&(1<<(i-1)) && !(mask&(1<<(i-2))))
		{
			int temp=mask;
			temp=temp^(1<<i);
			temp=temp^(1<<(i-1));
			temp=temp^(1<<(i-2));
			tmp=min(tmp,kill(temp));
		}
	}
	return dp[mask]=tmp;
}
int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		char peb[13];
		scanf("%s",peb);
		int j;
		memset(dp,-1,sizeof(dp));
		int mask=0;
		for (int i=0;i<12;i++)
		{
			if (peb[i]=='o')
			{
				mask|=(1<<i);
			}
		}
		cout<<kill(mask)<<endl;
	}
}