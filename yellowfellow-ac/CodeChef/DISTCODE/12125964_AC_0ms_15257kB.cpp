#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int ar[26][26];
        for (int i=0;i<26;i++)
        {
            for (int j=0;j<26;j++)
            {
                ar[i][j]=0;
            }
        }
        char temp[100000];
        int co=0;
        scanf("%s",temp);
        for (int i=0;i<strlen(temp)-1;i++)
        {
            if (ar[temp[i]-'A'][temp[i+1]-'A']==0)
            {
                co++;
                ar[temp[i]-'A'][temp[i+1]-'A']=1;
            }
        }
        printf ("%d\n",co);
    }
}
