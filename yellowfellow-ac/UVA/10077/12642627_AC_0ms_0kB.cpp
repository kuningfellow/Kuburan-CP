#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
double abs(double a,double b)
{
    if (a>b)return a-b;
    return b-a;
}
int main()
{
    int n,m;
    vector<int>step;
    while (1<2)
    {
        cin>>n>>m;
        if (n==1&&m==1)break;
        double rat=(double)n/m;
        double mid;
        double init=1;
        int la=0;
        int lb=1;
        int ra=1;
        int rb=0;
        while (1<2)
        {
            mid=(((double)(la+ra))/(lb+rb));
            if (abs(mid,rat)<1e-9)
            {
                break;
            }
            else if (mid>rat)
            {
                step.push_back(0);
                ra=(la+ra);
                rb=(lb+rb);
            }
            else if (mid<rat)
            {
                step.push_back(1);
                la=(la+ra);
                lb=(lb+rb);
            }
        }
        for (int i=0;i<step.size();i++)
        {
            if (step[i]==0)
            {
                printf ("L");
            }
            else printf ("R");
        }
        printf ("\n");
        step.clear();
    }
}
