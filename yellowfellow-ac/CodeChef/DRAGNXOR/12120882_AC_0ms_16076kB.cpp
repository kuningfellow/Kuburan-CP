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
        int c,a,b;
        cin>>c>>a>>b;
        int counta=0;
        int countb=0;
        while (a>0)
        {
            if (a%2==1)counta++;
            a/=2;
        }
        while (b>0)
        {
            if (b%2==1)countb++;
            b/=2;
        }
        int siz=counta+countb;
        if (siz>c)siz=c;
        int bit=0;
        int red=0;
        if (countb+counta>c)
        {
            red=counta+countb-c;
        }
        int val=0;
        siz-=red;
        while (bit<c)
        {
            val*=2;
            if (siz>0)
            {
                val+=1;
                siz--;
            }
            bit++;
        }
        printf ("%d\n",val);
    }
}
