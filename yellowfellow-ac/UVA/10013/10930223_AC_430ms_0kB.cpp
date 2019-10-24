#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> ar;
void ad()
{
    int m=ar.size();
    int i;
    for (i=m-1;i>0;i--)
    {
        while (ar[i]>=10)
        {
            ar[i]-=10;
            ar[i-1]++;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while (n>0)
    {
        int m;
        scanf("%d",&m);
        int i;
        for (i=0;i<m;i++)
            ar.push_back(0);
        int a,b;
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            ar.push_back(a+b);
        }
        ad();
        m=ar.size();
        int flag=0;
        int cou=0;
        for (i=0;i<m;i++)
        {
            if (ar[i]>0)
            {
                flag=1;
                printf ("%d",ar[i]);
            }
            else if (ar[i]==0&&flag==1)
            {
                cou++;
                printf ("0");
            }
            else if (ar[i]==0)
            {
                cou++;
            }
        }
        if (cou==m)
            printf ("0");
        n--;
        printf ("\n");
        if (n>0)
            printf ("\n");
        ar.clear();
    }
    return 0;
}
