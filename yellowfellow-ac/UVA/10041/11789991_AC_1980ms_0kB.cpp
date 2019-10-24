//UVA 10041 Vito's Family
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int ar[n];
        int vit=0;
        int vat=(1<<31)-1;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if (ar[i]>vit)vit=ar[i];
            if (ar[i]<vat)vat=ar[i];
        }
        int tamp=(1<<31)-1;
        for (int i=vat;i<=vit;i++)
        {
            int temp=0;
            for (int j=0;j<n;j++)
            {
                if (ar[j]>i)
                {
                    temp+=ar[j]-i;
                }
                else temp+=i-ar[j];
            }
            if (temp<tamp)tamp=temp;
        }
        printf ("%d\n",tamp);
    }
}
