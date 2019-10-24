//UVA 401 Palindromes
#include <stdio.h>
#include <string.h>
int main()
{
    char s[500];
    while (scanf("%s",s)!=EOF)
    {
        int l=strlen(s);
        int pal=1;
        int mir=1;
        for (int i=0;i<=l/2;i++)
        {
            if (s[i]!=s[l-1-i])
            {
                pal=0;
            }
            if ((s[i]=='A'&&s[l-1-i]!='A')||
                 (s[i]=='E'&&s[l-1-i]!='3')||
                 (s[i]=='H'&&s[l-1-i]!='H')||
                 (s[i]=='I'&&s[l-1-i]!='I')||
                 (s[i]=='J'&&s[l-1-i]!='L')||
                 (s[i]=='L'&&s[l-1-i]!='J')||
                 (s[i]=='M'&&s[l-1-i]!='M')||
                 (s[i]=='O'&&s[l-1-i]!='O')||
                 (s[i]=='S'&&s[l-1-i]!='2')||
                 (s[i]=='T'&&s[l-1-i]!='T')||
                 (s[i]=='U'&&s[l-1-i]!='U')||
                 (s[i]=='V'&&s[l-1-i]!='V')||
                 (s[i]=='W'&&s[l-1-i]!='W')||
                 (s[i]=='X'&&s[l-1-i]!='X')||
                 (s[i]=='Y'&&s[l-1-i]!='Y')||
                 (s[i]=='Z'&&s[l-1-i]!='5')||
                 (s[i]=='1'&&s[l-1-i]!='1')||
                 (s[i]=='2'&&s[l-1-i]!='S')||
                 (s[i]=='3'&&s[l-1-i]!='E')||
                 (s[i]=='5'&&s[l-1-i]!='Z')||
                 (s[i]=='8'&&s[l-1-i]!='8')||
                 s[i]=='B'||s[i]=='C'||s[i]=='D'||s[i]=='F'||s[i]=='G'||s[i]=='K'||s[i]=='N'||s[i]=='P'||s[i]=='Q'||s[i]=='R'||
                 s[i]=='4'||s[i]=='6'||s[i]=='7'||s[i]=='9')
            {
                mir=0;
            }
        }
        if (pal==0&&mir==0)
        {
            printf ("%s -- is not a palindrome.\n",s);
        }
        else if (pal==1&&mir==0)
        {
            printf ("%s -- is a regular palindrome.\n",s);
        }
        else if (pal==0&&mir==1)
        {
            printf ("%s -- is a mirrored string.\n",s);
        }
        else if (pal==1&&mir==1)
        {
            printf ("%s -- is a mirrored palindrome.\n",s);
        }
        printf ("\n");
    }
}
