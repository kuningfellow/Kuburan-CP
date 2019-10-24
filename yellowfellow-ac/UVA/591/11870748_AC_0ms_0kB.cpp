//UVA 591 Box of Bricks
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int kas=1;
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        int ar[n];
        int h=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            h+=ar[i];
        }
        h/=n;
        int temp;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n-1;j++)
            {
                if (ar[j]<ar[j+1])
                {
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
        }
        int mov=0;
        for (int i=0;i<n;i++)
        {
            if (ar[i]>h)
            {
                mov+=ar[i]-h;
            }
        }
        printf ("Set #%d\nThe minimum number of moves is %d.\n\n",kas++,mov);
    }
}
