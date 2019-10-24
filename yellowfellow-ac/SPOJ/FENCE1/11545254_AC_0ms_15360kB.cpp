#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	while (1<2)
	{
		int n;
		cin>>n;
		if (n==0)break;
		double area=(double)n*n/2/3.14159265359;
		printf ("%.2f\n",area);
	}
}