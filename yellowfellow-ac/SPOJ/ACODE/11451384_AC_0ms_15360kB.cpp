#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int dp[5005];
char s[5005];
int l;
long long int serc(int x)
{
    if (x==l)
        return 1;
    int temp=0;
    if (dp[x]!=-1)
        return dp[x];
    dp[x]=0;
    if ((s[x]-'0')>0)
    {
        if (x+1<l&&((s[x]-'0')*10+(s[x+1]-'0'))<=26)
        {
            dp[x]+=serc(x+2);
        }
            dp[x]+=serc(x+1);
    }
    return dp[x];
}
int main()
{
    while (1<2)
    {
        scanf("%s",&s);
        l=strlen(s);
        if (l==1&&s[0]=='0')break;
        for (int i=0;i<l;i++)
        {
            dp[i]=-1;
        }
//        printf ("%d\n",l);
        cout<<serc(0)<<endl;
    }
}
