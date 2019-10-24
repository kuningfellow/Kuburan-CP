//UVA 444 Encoder and Decoder
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char temp[500];
    while (scanf("%[^\n]s",&temp)!=EOF)
    {
        getchar();
        int lim=strlen(temp),con=0;
        if (temp[0]>='0'&&temp[0]<='9')
        {
            int res[500];
            int si=0;
            for (int i=lim-1;i>=0;i--)
            {
                if (con<32)
                {
                    con*=10;
                    con+=temp[i]-'0';
                }
                if (con>=32)
                {
                    res[si++]=con;
                    con=0;
                }
            }
            for (int i=0;i<si;i++)
            {
                printf ("%c",res[i]);
            }
        }
        else
        {
            for (int i=lim-1;i>=0;i--)
            {
                con=(int)temp[i];
                while (con>0)
                {
                    printf ("%d",con%10);
                    con/=10;
                }
            }
        }
        printf ("\n");
        temp[0]='\0';
    }
}
