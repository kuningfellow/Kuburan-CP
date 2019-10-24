#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int tc;
	cin>>tc;
	string rem;
	map<string,int>diar;
	while (tc--)
	{
		cin>>rem;
		if (diar[rem]==0)printf ("NO\n");
		else printf ("YES\n");
		diar[rem]=1;
	}
}