#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int worse=0;
	int tmp=0;
	for (int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		tmp+=a;
		worse=min(worse,tmp);
	}
	printf ("%d\n",-worse);
}