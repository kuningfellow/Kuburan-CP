#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    char pas[500];
    int copas[101];
    for (int i=0;i<101;i++)copas[i]=0;
    for (int i=0;i<n;i++)
    {
        scanf("%s",pas);
        copas[strlen(pas)]++;
    }
    scanf("%s",pas);
    int t=strlen(pas);
    int be=0;
    int wo=0;
    int pen=0;
    for (int i=0;i<101;i++)
    {
        if (i==t)
        {
            wo=be;
            wo+=copas[i]-1;
            pen+=copas[i]-1;
            wo+=pen/k*5;
            break;
        }
        else
        {
            be+=copas[i];
            pen+=copas[i];
            be+=pen/k*5;
            pen%=k;
        }
    }
    printf ("%d %d\n",be+1,wo+1);
}
