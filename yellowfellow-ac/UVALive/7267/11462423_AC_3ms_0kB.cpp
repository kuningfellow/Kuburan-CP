#include <bits/stdc++.h>
using namespace std;

int X[8], Y[8];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        for (int i=0;i<4;i++)
        {
            scanf("%d%d",&X[i], &Y[i]);
        }
        bool check=0;
        for(int a=0;a<4;a++)
        {
            for(int b=0;b<4;b++)
            {
                if(a==b) continue;
                int newX=-1, newY=-1;
                if(X[a]==X[b])
                {
                    newY=Y[a]+Y[b];
                    newX=X[a];
                }
                else if(Y[a]==Y[b])
                {
                    newX=X[a]+X[b];
                    newY=Y[a];
                }
                else if(X[a]==Y[b])
                {
                    newY=Y[a]+X[b];
                    newX=X[a];
                }
                else if(Y[a]==X[b])
                {
                    newX=X[a]+Y[b];
                    newY=Y[a];
                }
                if(newX<0 || newY<0) continue;
                for(int c=0;c<4;c++)
                {
                    if(a==c || b==c) continue;
                    int mark=-1;
                    if(newX==X[c])
                    {
                        mark=1;
                        newY=newY+Y[c];
                        newX=newX;
                    }
                    else if(newY==Y[c])
                    {
                        mark=1;
                        newX=newX+X[c];
                        newY=newY;
                    }
                    else if(newX==Y[c])
                    {
                        mark=1;
                        newY=newY+X[c];
                        newX=newX;
                    }
                    else if(newY==X[c])
                    {
                        mark=1;
                        newX=newX+Y[c];
                        newY=newY;
                    }
                    if (mark==-1)continue;
                    else check=1;
                }
            }
        }
        if (check==0)printf ("No\n");
        else printf ("Yes\n");
    }
}
