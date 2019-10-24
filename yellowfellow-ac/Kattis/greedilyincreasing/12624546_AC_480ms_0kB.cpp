#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a;
    vector<int>lis;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        if (lis.size()==0||a>lis[lis.size()-1])
        {
            lis.push_back(a);
        }
    }
    printf ("%d\n",lis.size());
    for (int i=0;i<lis.size();i++)
    {
        printf ("%d",lis[i]);
        if (i<lis.size()-1)printf (" ");
    }
    printf ("\n");
}
