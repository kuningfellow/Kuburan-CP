//UVA 637 Booklet Printing
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        int pag=0;
        while (pag*4<n)
        {
            pag++;
        }
        int ar[pag][4];
        for (int i=0;i<pag;i++)
        {
            ar[i][0]=-1;
            ar[i][1]=-1;
            ar[i][2]=-1;
            ar[i][3]=-1;
        }
        int now=0;
        int sec=0;
        ar[0][0]=1;
        for (int i=2;i<=n;i++)
        {
            if (ar[now][sec]!=-1)
            {
                if (sec==0)sec=1;
                else if (sec==1)
                {
                    now++;
                    sec=0;
                }
                if (now==pag)
                {
                    now--;
                    sec=2;
                }
                else if (sec==2)
                {
                    sec=3;
                }
                else if (sec==3)
                {
                    sec=2;
                    now--;
                }
            }
            ar[now][sec]=i;
        }
        printf ("Printing order for %d pages:\n",n);
        for (int i=0;i<pag;i++)
        {
            printf ("Sheet %d, ",i+1);
            printf ("front: ");
            if (ar[i][3]==-1)printf ("Blank, ");
            else printf ("%d, ",ar[i][3]);
            if (ar[i][0]==-1)printf ("Blank\n");
            else printf ("%d\n",ar[i][0]);
            if (ar[i][1]==-1&&ar[i][2]==-1)continue;
            printf ("Sheet %d, ",i+1);
            printf ("back : ");
            if (ar[i][1]==-1)printf ("Blank, ");
            else printf ("%d, ",ar[i][1]);
            if (ar[i][2]==-1)printf ("Blank\n");
            else printf ("%d\n",ar[i][2]);
        }
    }
}
