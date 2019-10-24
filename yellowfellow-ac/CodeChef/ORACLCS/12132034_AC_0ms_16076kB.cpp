#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dif(int a, int b)
{
    if (a>b)return a-b;
    else return b-a;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        char in[500];
        int co[n][2];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<2;j++)
            {
                co[i][j]=0;
            }
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s",in);
            int len=strlen(in);
            for (int j=0;j<len;j++)
            {
                co[i][in[j]-'a']++;
            }
        }
        int maxi=(1<<30)-1;
        int temp;
        for (int j=0;j<2;j++)
        {
            temp=co[0][j];
            for (int i=1;i<n;i++)
            {
                temp=min(co[i][j],temp);
            }
            if (temp<maxi)maxi=temp;
        }
        printf("%d\n",maxi);
    }
}
