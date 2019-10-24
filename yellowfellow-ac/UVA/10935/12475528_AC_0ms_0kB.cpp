#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    while (1<2)
    {
        int n;
        cin>>n;
        if (n==0)break;
        if (n==1)
        {
            printf ("Discarded cards:\n");
            printf ("Remaining card: 1\n");
            continue;
        }
        queue<int>q;
        for (int i=0;i<n;i++)
        {
            q.push(i+1);
        }
        queue<int>disc;
        int car=0;
        while (!q.empty())
        {
            disc.push(q.front());
            q.pop();
            car++;
            if (!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        printf ("Discarded cards: %d",disc.front());
        disc.pop();
        car--;
        while (--car)
        {
            printf (", %d",disc.front());
            disc.pop();
        }
        printf ("\nRemaining card: %d\n",disc.front());
    }
}
