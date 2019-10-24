#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int ma[27][27];
int visit[27];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        double fee[27];
        double temp;
        char att[1000];
        char id[3];
        for (int i=0;i<27;i++)
        {
            fee[i]=0;
        }
        for (int i=0;i<27;i++)
        {
            visit[i]=0;
            for (int j=0;j<27;j++)
                ma[i][j]=0;
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s%lf%s",id,&temp,att);
            fee[id[0]-'A']=temp;
            for (int j=0;j<strlen(att);j++)
            {
                if (att[j]=='*')
                {
                    ma[id[0]-'A'][26]=1;
                    ma[26][id[0]-'A']=1;
                }
                else
                {
                    ma[id[0]-'A'][att[j]-'A']=1;
                    ma[att[j]-'A'][id[0]-'A']=1;
                }
            }
        }
        queue<int>q;
        q.push(26);
        double tax=0.95;
        while (!q.empty())
        {
            for (int j=0;j<q.size();j++)
            {
                for (int i=0;i<27;i++)
                {
                    if (ma[q.front()][i]==1&&visit[i]==0&&i!=q.front())
                    {
                        visit[i]=1;
                        q.push(i);
                        if (q.front()!=26)
                        {
                            fee[i]*=tax;
                        }
                        ma[q.front()][i]=0;
                        ma[i][q.front()]=0;
                    }
                }
                q.pop();
            }
            tax*=0.95;
        }
        int maxi=0;
        for (int i=0;i<27;i++)
        {
            if (fee[maxi]<fee[i])
            {
                maxi=i;
            }
        }
        printf ("Import from %c\n",maxi+'A');
    }
}
