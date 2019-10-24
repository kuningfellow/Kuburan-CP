//UVA 347 Run
#include <stdio.h>
#include <vector>
using namespace std;
int runthru(vector<int>num)
{
    int siz=num.size();
    int mark[siz];
    int coun[10];
    for (int i=0;i<=9;i++)
    {
        coun[i]=0;
    }
    for (int i=0;i<siz;i++)
    {
        coun[num[i]]++;
        if (coun[num[i]]>1)return 0;
        mark[i]=0;
    }
    int pos=0;
    int steps=0;
    while (steps<siz)
    {
        mark[pos]=1;
        pos=pos+num[pos];
        pos%=siz;
        steps++;
    }
    if (pos!=0)return 0;
    for (int i=0;i<siz;i++)
    {
        if (mark[i]==0)return 0;
    }
    return 1;
}
int main()
{
    int temp;
    int kase=1;
    while (1<2)
    {
        vector<int>run;
        vector<int>num;
        scanf("%d",&temp);
        if (temp==0)break;
        int sel=temp;
        int flag=0;
        while (!flag)
        {
            temp=sel;
            while (temp>0)
            {
                int a=temp%10;
                run.push_back(a);
                temp/=10;
            }
            for (int i=run.size()-1;i>=0;i--)
            {
                num.push_back(run[i]);
            }
            flag=runthru(num);
            run.clear();
            num.clear();
            sel++;
        }
        printf ("Case %d: %d\n",kase++,sel-1);
    }
}
