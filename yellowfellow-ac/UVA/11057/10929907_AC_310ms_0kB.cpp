#include <stdio.h>
#include <vector>
using namespace std;
vector<int> bo;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%d",&j);
            bo.push_back(j);
        }
        int m;
        scanf("%d",&m);
        int dif;
        int x=0,y=0;
        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                if (bo[i]+bo[j]==m&&i!=j)
                {
                    if (((bo[i]>bo[j]?bo[i]:bo[j])-(bo[i]<bo[j]?bo[i]:bo[j])<dif||x==0&&y==0)&&bo[i]>0&&bo[j]>0)
                    {
                        x=bo[i];
                        y=bo[j];
                        dif=(y>x?y:x)-(y<x?y:x);
                    }
                }
            }
        }
        printf ("Peter should buy books whose prices are %d and %d.\n\n",(x<y?x:y),(y>x?y:x));
        bo.clear();
    }
    return 0;
}
