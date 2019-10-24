//UVA 111 History Grading
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
int nums(char ar[])
{
    int co=1;
    for (int i=0;i<strlen(ar);i++)
    {
        if (ar[i]==' ')co++;
    }
    return co;
}
int order[21];
int tempp[21];
int stud[21];
int siz;
int same()
{
    int k=0;
    for (int i=0;i<siz;i++)
    {
        if (stud[i]==order[i])k++;
    }
    return k;
}
int ordering(int a)
{
    if (a==0)
    {
        printf ("hi\n");
        return -1;
    }
    for (int i=0;i<siz;i++)
    {
        if (order[i]==a)
        {
            return i;
        }
    }
}
int dp[21][21];
int serc(int x,int a)
{
    if (x==siz)return 0;
    dp[x][a]=0;
    if (a==0)
    {
        dp[x][a]=max(1+serc(x+1,stud[x]),dp[x][a]);
    }
    else
    {
        for (int i=ordering(a)+1;i<siz;i++)
        {
            if (order[i]==stud[x])
            {
                dp[x][a]=max(1+serc(x+1,order[i]),dp[x][a]);
            }
        }
    }
    dp[x][a]=max(dp[x][a],serc(x+1,a));
    return dp[x][a];
}
int main()
{
    char ar[50];
    char le[10];
    int n;
    int ans=1;
    while (1<2)
    {
        if (scanf("%[^\n]s",ar)==EOF)break;
        getchar();
        n=nums(ar);
        if (n==1)
        {
            ans=1;
            siz=0;
            int mul=1;
            for (int i=strlen(ar)-1;i>=0;i--)
            {
                if (ar[i]>='0'&&ar[i]<='9')
                {
                    siz+=(ar[i]-'0')*mul;
                    mul*=10;
                }
            }
        }
        else if (ans==1)
        {
            ans=0;
            int mul=1;
            int j=siz-1;
            order[j]=0;
            int flag=0;
            for (int i=strlen(ar)-1;i>=0;i--)
            {
                if (ar[i]>='0'&&ar[i]<='9')
                {
                    flag=1;
                    order[j]+=(ar[i]-'0')*mul;
                    mul*=10;
                }
                else
                {
                    if (flag==1)
                    {
                        mul=1;
                        j--;
                        order[j]=0;
                    }
                    flag=0;
                }
            }
            for (int i=0;i<siz;i++)
            {
                tempp[i]=order[i];
            }
            for (int i=0;i<siz;i++)
            {
                order[tempp[i]-1]=i+1;
            }
        }
        else
        {
            ans=0;
            int mul=1;
            int j=siz-1;
            stud[j]=0;
            int flag=0;
            for (int i=strlen(ar)-1;i>=0;i--)
            {
                if (ar[i]>='0'&&ar[i]<='9')
                {
                    flag=1;
                    stud[j]+=(ar[i]-'0')*mul;
                    mul*=10;
                }
                else
                {
                    if (flag==1)
                    {
                        mul=1;
                        j--;
                        stud[j]=0;
                    }
                    flag=0;
                }
            }
            for (int i=0;i<siz;i++)
            {
                tempp[i]=stud[i];
            }
            for (int i=0;i<siz;i++)
            {
                stud[tempp[i]-1]=i+1;
            }
            cout<<serc(0,0)<<endl;
        }
    }
}
