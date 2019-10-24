//UVA 200 Rare Order
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int>lis[26];
vector<int>sorted;
int vis[26];
void serc(int x)
{
    vis[x]=1;
    for (int i=0;i<lis[x].size();i++)
    {
        if (vis[lis[x][i]]==0)
        {
            serc(lis[x][i]);
        }
    }
    sorted.push_back(x);
}
int mar[26];
int main()
{
    char rem[20005][27];
    int siz=0;
    while(1<2)
    {
        scanf("%s",rem[siz]);
        if(rem[siz][0]=='#')break;
        siz++;
    }
    for (int j=0;j<siz-1;j++)
    {
        int k=0;
        while (rem[j][k]==rem[j+1][k]&&strlen(rem[j])>k+1&&strlen(rem[j+1])>k+1)
        {
            k++;
        }
        mar[rem[j+1][k]-'A']=1;
        mar[rem[j][k]-'A']=1;
        lis[rem[j][k]-'A'].push_back(rem[j+1][k]-'A');
    }
    for (int i=0;i<26;i++)
    {
        if (vis[i]==0&&mar[i]==1)
        {
            serc(i);
        }
    }
    for (int i=sorted.size()-1;i>=0;i--)
    {
        printf ("%c",sorted[i]+'A');
    }
    printf ("\n");
}
