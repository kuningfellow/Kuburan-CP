#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if (2*c>a||2*c>b)printf ("Second\n");
	else printf ("First\n");
}