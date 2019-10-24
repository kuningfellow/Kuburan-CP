#include <stdio.h>
int points[5][1005];
int good[1005];
int dot(int a, int b, int c)
{
    int i,j=0;
    if (good[a]==1)
    {
        for (i=0;i<5;i++)
        {
            j+=(points[i][c]-points[i][a])*(points[i][b]-points[i][a]);
        }
        if (j<=0)
            return 1;
        else return 0;
    }
    else return 0;
}
void triangulate(int a, int b, int c)
{
    good[a]=dot(a,b,c);
    good[b]=dot(b,a,c);
    good[c]=dot(c,a,b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for (i=0;i<n;i++)
    {
        good[i]=1;
        for (j=0;j<5;j++)
        {
            scanf("%d",&points[j][i]);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (i!=k)
            {
                for (k=j+1;k<n;k++)
                {
                    if(good[i]==1||good[j]==1||good[k]==1)
                    {
                        triangulate(i,j,k);
                    }
                }
            }
        }
    }
    j=0;
    for (i=0;i<n;i++)
    {
        if (good[i]==1)
            j++;
    }
    printf ("%d\n",j);
    for (i=0;i<n;i++)
    {
        if (good[i]==1)
            printf ("%i\n",i+1);
    }
    return 0;
}
