//UVA 729 The Hamming Distance Problem
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int>lis;
int t;
int print(int rem, int num, int h)
{
    if (rem==h)
    {
        int temp=num;
        int co=0;
        while (temp>0)
        {
            if (temp%2==1)co++;
            temp/=2;
        }
        if (co==t)
        {
            lis.push_back(num);
        }
        return 0;
    }
    else
    {
        print (rem+1,(num<<1)+1,h);
        print (rem+1,(num<<1),h);
    }
    return 1;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        int h;
        cin>>h>>t;
        print(0,0,h);
        sort(lis.begin(),lis.end());
        int s=lis.size();
        stack<int>rev;
        int di=h;
        for (int i=0;i<s;i++)
        {
            di=h;
            while (di--)
            {
                rev.push(lis[i]%2);
                lis[i]/=2;
            }
            while (!rev.empty())
            {
                printf ("%d",rev.top());
                rev.pop();
            }
            printf ("\n");
        }
        lis.clear();
        if (tc>0)
            printf ("\n");
    }
}
