#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);
	int n, inp;
	int ret=0;
	cin>>n;
	for(int a=0;a<n;a++)
	{
		scanf("%d", &inp);
		ret+=inp;
	}
	ret-=n;
	if(ret%2==0)
	{
		printf("Mike");
	}
	else
	{
		printf("Constantine");
	}
	printf("\n");
}