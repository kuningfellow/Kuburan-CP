//UVA 12195 Jingle Composing
#include <bits/stdc++.h>
using namespace std;
int main(){
    char rem[500];
    while (1<2){
        scanf("%s",rem);
        if (!strcmp(rem,"*"))break;
        int tot=0;
        int cnt=0;
        int l=strlen(rem);
        for (int i=0;i<l;i++){
            if (rem[i]=='/'){
                if (tot==64)
                    cnt++;
                tot=0;
            }
            else if (rem[i]=='W')tot+=64;
            else if (rem[i]=='H')tot+=32;
            else if (rem[i]=='Q')tot+=16;
            else if (rem[i]=='E')tot+=8;
            else if (rem[i]=='S')tot+=4;
            else if (rem[i]=='T')tot+=2;
            else if (rem[i]=='X')tot+=1;
        }
        printf ("%d\n",cnt);
    }
}