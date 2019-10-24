//UVA 10813 Traditional BINGO
#include <stdio.h>
#include <vector>
using namespace std;
pair<int,int> card[76];
int mark[5][5];
int main()
{
    int tc;
    scanf("%d",&tc);
    while (tc--)
    {
        int a;
        for (int i=0;i<76;i++)
        {
            card[i]=pair<int,int>(-1,-1);
        }
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++)
            {
                if (i==2&&j==2)
                {
                    mark[i][j]=1;
                    continue;
                }
                scanf("%d",&a);
                mark[i][j]=0;
                card[a]=pair<int,int>(i,j);
            }
        }
        int mov=-1;
        for (int k=0;k<75;k++)
        {
            scanf("%d",&a);
            if (mov!=-1)continue;
            if (card[a].first!=-1)
            {
                mark[card[a].first][card[a].second]=1;
                int winx=1;
                int winy=1;
                int wind=0;
                for (int i=0;i<5;i++)
                {
                    if (mark[i][card[a].second]!=1)
                    {
                        winy=0;
                    }
                    if (mark[card[a].first][i]!=1)
                    {
                        winx=0;
                    }
                }
                if ((winx==1||winy==1)&&mov==-1)
                {
                    mov=k;
                }
                if (card[a].first==card[a].second)
                {
                    wind=1;
                    for (int i=0;i<5;i++)
                    {
                        if (mark[i][i]!=1)
                        {
                            wind=0;
                            break;
                        }
                    }
                }
                if (4-card[a].first==card[a].second)
                {
                    wind=1;
                    for (int i=0;i<5;i++)
                    {
                        if (mark[4-i][i]!=1)
                        {
                            wind=0;
                            break;
                        }
                    }
                }
                if ((wind==1)&&mov==-1)
                {
                    mov=k;
                }
            }
        }
        printf ("BINGO after %d numbers announced\n",mov+1);
    }
}
