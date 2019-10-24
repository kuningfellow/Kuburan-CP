#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if (n==0)
	{
		printf ("a\n");
		return 0;
	}
	int m=0;
	while (n>0)
	{
		int i=2;
		while (i*(i-1)/2<=n)
		{
			i++;
		}
		i--;
		for (int j=0;j<i;j++)
		{
			printf ("%c",m+'a');
		}
		n-=(i*(i-1)/2);
		m++;
	}
	printf ("\n");
}