#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        char s[5000];
        scanf("%s",s);
        int val=0;
        char sel;
        int ans=10000;
        sel=s[0];
//        for (int j=0;j<26;j++)
        {
            sel=s[0];
            val=2;
            for (int i=1;i<strlen(s);i++)
            {
    //            printf ("%d %c ",val,s[i]);
                if (s[i]<sel)
                {
                    val+=26-(sel-s[i]);
                }
                else
                {
                    val+=s[i]-sel;
                }
                val++;
    //            printf ("%d\n",val);
                sel=s[i];
            }
//            if (val<ans)ans=val;
        }
        if (val>strlen(s)*11)
        {
            printf ("NO\n");
        }
        else printf ("YES\n");
    }
}
