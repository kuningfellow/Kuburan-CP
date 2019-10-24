#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char perm[27];
    scanf("%s",&perm);
    getchar();
    char temp[5000];
    for (int i=0;i<n;i++)
    {
        scanf("%s",temp);
        for (int j=0;j<strlen(temp);j++)
        {
            if (temp[j]=='_')printf (" ");
            else if (temp[j]>='a'&&temp[j]<='z')
            {
                printf ("%c",perm[temp[j]-'a']);
            }
            else if (temp[j]>='A'&&temp[j]<='Z')
            {
                printf ("%c",perm[temp[j]-'A']-'a'+'A');
            }
            else printf ("%c",temp[j]);
        }
        if (i<n-1)printf ("\n");
    }
}
