#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int main()
{
    int kasus=1;
    while (1<2)
    {
        int r,d,s;
        cin>>r>>d>>s;
        if (r==0&&d==0&&s==0)break;
        int a,b;
        vector<int>dor[12];
        vector<int>swi[12];
        for (int i=0;i<d;i++)
        {
            cin>>a>>b;
            dor[a].push_back(b);
            dor[b].push_back(a);
        }
        for (int i=0;i<s;i++)
        {
            cin>>a>>b;
            swi[a].push_back(b);
        }
        queue<pair<int, int > >q;
        q.push(pair<int,int>(2,1));
        int visit[1<<12][12][4];
        int cost=1;
        for (int i=0;i<(1<<12);i++)
        {
            for (int j=0;j<12;j++)
            {
                visit[i][j][0]=-1;
                visit[i][j][1]=0;
                visit[i][j][2]=0;
                visit[i][j][3]=0;
            }
        }
        visit[2][1][0]=0;
        visit[2][1][1]=-1;
        visit[2][1][2]=-1;
        visit[2][1][3]=0;
        int help;
        int misk;
        while (!q.empty())
        {
            int siz=q.size();
            for (int j=0;j<siz;j++)
            {
                for (int i=0;i<dor[q.front().second].size();i++)
                {
                    help=dor[q.front().second][i];
                    misk=q.front().first;
                    if (((q.front().first)&(1<<help))>0&&visit[misk][help][0]==-1)
                    {
                        visit[misk][help][0]=cost;
                        visit[misk][help][1]=q.front().second;
                        visit[misk][help][2]=misk;
                        visit[misk][help][3]=0;
                        q.push(pair<int,int>(misk,help));
                    }
                }
                for (int i=0;i<swi[q.front().second].size();i++)
                {
                    help=swi[q.front().second][i];
                    misk=q.front().first;
                    misk^=(1<<help);
                    if (visit[misk][q.front().second][0]==-1&&((misk&(1<<(q.front().second)))>0))
                    {
                        visit[misk][q.front().second][0]=cost;
                        visit[misk][q.front().second][1]=q.front().second;
                        visit[misk][q.front().second][2]=q.front().first;
                        if ((misk&(1<<(help)))==0)
                            visit[misk][q.front().second][3]=-help;
                        else visit[misk][q.front().second][3]=help;
                        q.push(pair<int,int>(misk,q.front().second));
                    }
                }
                q.pop();
            }
            cost++;
        }
        //fstream fout;
        //fout.open("villa.txt",ios::app);
        //fout<<"Villa #"<<kasus<<endl;
        printf ("Villa #%d\n",kasus);
        kasus++;
        if (visit[1<<r][r][0]!=-1)
        {
            //fout<<"The problem can be solved in "<<visit[1<<r][r][0]<<" steps:"<<endl;
            printf ("The problem can be solved in %d steps:\n",visit[1<<r][r][0]);
            int mask=(1<<r);
            int x=r;
            int e;
            vector<int>temp[4];
            while (x!=1||mask!=2)
            {
                temp[0].push_back(x);
                temp[1].push_back(visit[mask][x][1]);
                temp[2].push_back(visit[mask][x][2]);
                temp[3].push_back(visit[mask][x][3]);
                e=x;
                x=visit[mask][e][1];
                mask=visit[mask][e][2];
            }
            for (int i=temp[0].size()-1;i>=0;i--)
            {
                if (temp[3][i]==0)
                {
                    //fout<<"- Move to room "<<temp[0][i]<<".\n";
                    printf ("- Move to room %d.\n",temp[0][i]);
                }
                else if (temp[3][i]<0)
                {
                    //fout<<"- Switch off light in room "<<-temp[3][i]<<".\n";
                    printf ("- Switch off light in room %d.\n",-temp[3][i]);
                }
                else if (temp[3][i]>0)
                {
                    //fout<<"- Switch on light in room "<<temp[3][i]<<".\n";
                    printf ("- Switch on light in room %d.\n",temp[3][i]);
                }
            }
        }
        else
        {
            //fout<<"The problem cannot be solved.\n";
            printf ("The problem cannot be solved.\n");
        }
        //fout<<endl;
        printf ("\n");
    }
}
