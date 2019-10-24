//UVA 10903 Rock-Paper-Scissor Tournament
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int fir=1;
    while (1<2)
    {
        int n,m;
        cin>>n;
        if (n==0)break;
        cin>>m;
        int ta,tb;
        char ma[50],mb[50];
        int win[n];
        int lose[n];
        for (int i=0;i<n;i++)
        {
            win[i]=0;
            lose[i]=0;
        }
        m=m*(n-1)*n/2;
        for (int i=0;i<m;i++)
        {
            scanf("%d%s%d%s",&ta,&ma,&tb,&mb);
            ta--;
            tb--;
            if (!strcmp(ma,"rock"))
            {
                if (!strcmp(mb,"scissors"))
                {
                    lose[tb]++;
                    win[ta]++;
                }
                else if (!strcmp(mb,"paper"))
                {
                    lose[ta]++;
                    win[tb]++;
                }
            }
            else if (!strcmp(ma,"paper"))
            {
                if (!strcmp(mb,"scissors"))
                {
                    lose[ta]++;
                    win[tb]++;
                }
                else if (!strcmp(mb,"rock"))
                {
                    lose[tb]++;
                    win[ta]++;
                }
            }
            else if (!strcmp(ma,"scissors"))
            {
                if (!strcmp(mb,"rock"))
                {
                    lose[ta]++;
                    win[tb]++;
                }
                else if (!strcmp(mb,"paper"))
                {
                    lose[tb]++;
                    win[ta]++;
                }
            }
        }
        if (fir==0)
        {
            printf("\n");
        }
        fir=0;
        for (int i=0;i<n;i++)
        {
            if (lose[i]+win[i]==0)printf ("-\n");
            else printf ("%.3f\n",(double)win[i]/(win[i]+lose[i]));
        }
    }
}
