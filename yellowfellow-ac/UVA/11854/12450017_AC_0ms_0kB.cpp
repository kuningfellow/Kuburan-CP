//UVA 11854 Egypt
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    while (1<2)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if (a+b+c==0)break;
        if (a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
            printf ("right\n");
        else printf ("wrong\n");
    }
}
