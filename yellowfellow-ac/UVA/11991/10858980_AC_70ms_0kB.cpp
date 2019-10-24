#include <stdio.h>
#include <vector>
using namespace std;
vector<int> dpo[1000005];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int peta[n];
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            dpo[x].push_back(i);
        }
        int indeks;
        for (indeks=0;indeks<m;indeks++)
        {
            int oc,num;
            scanf("%d%d",&oc,&num);
            if (oc > dpo[num].size()) {
                printf("0\n");
            } else {
                printf("%d\n", dpo[num][oc-1] + 1);
            }
        }
    }
    return 0;
}
