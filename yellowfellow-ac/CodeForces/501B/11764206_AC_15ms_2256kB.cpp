#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
struct handle{
    char name[50];
    char cur[50];
};
int main()
{
    int t;
    cin>>t;
    struct handle lis[t];
    char a[50];
    int siz=0;
    char b[50];
    char take[t][50];
    int takesiz=0;
    char save[t][2][50];
    int saves=0;
    while (t--)
    {
        scanf("%s%s",a,b);
        int found=0;
        for (int i=0;i<=siz;i++)
        {
            if (!strcmp(lis[i].name,a))
            {
                found=1;
                strcpy(lis[siz].cur,b);
                strcpy(lis[siz].name,lis[i].name);
                siz++;
                break;
            }
            else if (!strcmp(lis[i].cur,a))
            {
                found=1;
                strcpy(lis[siz].cur,b);
                strcpy(lis[siz].name,lis[i].name);
                siz++;
                break;
            }
        }
        if (found==0)
        {
            strcpy(lis[siz].name,a);
            strcpy(lis[siz].cur,b);
            siz++;
        }
    }
    for (int i=siz-1;i>=0;i--)
    {
        int bad=0;
        for (int j=0;j<takesiz;j++)
        {
            if (!strcmp(take[j],lis[i].name))
            {
                bad=1;
                break;
            }
        }
        if (bad==0)
        {
            strcpy(save[saves][0],lis[i].name);
            strcpy(save[saves][1],lis[i].cur);
            strcpy(take[takesiz],lis[i].name);
            takesiz++;
            saves++;
        }
    }
    printf ("%d\n",saves);
    for (int i=0;i<saves;i++)
    {
        printf("%s %s\n",save[i][0],save[i][1]);
    }
}
