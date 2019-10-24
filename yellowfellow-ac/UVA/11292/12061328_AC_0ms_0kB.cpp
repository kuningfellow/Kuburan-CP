//UVA 11292 Dragon of Loowater
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int dra[20005];
int kni[20005];
int tempo[20005];
int main()
{
    while (1<2)
    {
        scanf("%d%d",&n,&m);
        if (n==0&&m==0)break;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&dra[i]);
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&kni[i]);
        }
        sort(dra,dra+n);
        sort(kni,kni+m);
        int j=0;
        int dead=0;
        int pay=0;
        for (int i=0;i<m;i++)
        {
            if (dra[j]<=kni[i])
            {
                j++;
                pay+=kni[i];
            }
            if (j==n)break;
        }
        if (j<n)dead=1;
        if (dead==1)printf ("Loowater is doomed!\n");
        else printf ("%d\n",pay);
    }
}
