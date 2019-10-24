//UVA 10035 Primary Arithmetic
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    while (1<2)
    {
        int A,B;
        cin>>A>>B;
        if (A==0&&B==0)break;
        char a[12],b[12];
        int j=10;
        a[11]='\0';
        b[11]='\0';
        while (j>=0)
        {
            a[j]=A%10+'0';
            b[j]=B%10+'0';
            j--;
            A/=10;
            B/=10;
        }
        int op=0,c=0;
        for (int i=10;i>=0;i--)
        {
            if (a[i]-'0'+b[i]-'0'+c>9)
            {
                op++;
                c=1;
            }
            else
            {
                c=0;
            }
        }
        if (op==0)printf ("No carry operation.\n");
        else if (op==1)printf ("1 carry operation.\n");
        else printf ("%d carry operations.\n",op);
    }
}
