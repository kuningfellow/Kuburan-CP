#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        double a,b,c;
        cin>>a>>b>>c;
        int yes=0;
        if (a+b==c)
        {
            yes=1;
        }
        else if (a-b==c||b-a==c)
        {
            yes=1;
        }
        else  if (a*b==c)
        {
            yes=1;
        }
        else if ((b!=0&&a/b==c)||(a!=0&&b/a==c))
        {
            yes=1;
        }
        if (yes==1)printf ("Possible\n");
        else printf ("Impossible\n");
    }
}
