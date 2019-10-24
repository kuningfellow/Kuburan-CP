//UVA 10415 Eb Alto Saxophone Player
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    getchar();
    while (tc--){
        char rem[500];
        rem[0]='\0';
        scanf("%[^\n]",rem);
        getchar();
        int l=strlen(rem);
        int ar[10]={};
        int stat[10]={};
        char sel[15]="cdefgabCDEFGAB";
        int cor[14][10]={0,1,1,1,0,0,1,1,1,1,
                         0,1,1,1,0,0,1,1,1,0,
                         0,1,1,1,0,0,1,1,0,0,
                         0,1,1,1,0,0,1,0,0,0,
                         0,1,1,1,0,0,0,0,0,0,
                         0,1,1,0,0,0,0,0,0,0,
                         0,1,0,0,0,0,0,0,0,0,
                         0,0,1,0,0,0,0,0,0,0,
                         1,1,1,1,0,0,1,1,1,0,
                         1,1,1,1,0,0,1,1,0,0,
                         1,1,1,1,0,0,1,0,0,0,
                         1,1,1,1,0,0,0,0,0,0,
                         1,1,1,0,0,0,0,0,0,0,
                         1,1,0,0,0,0,0,0,0,0};
        for (int i=0;i<l;i++){
            int mode;
            for (int j=0;j<14;j++){
                if (rem[i]==sel[j]){
                    mode=j;
                    break;
                }
            }
            for (int j=0;j<10;j++){
                if (stat[j]<cor[mode][j]){
                    ar[j]++;
                }
                stat[j]=cor[mode][j];
            }
        }
        for (int i=0;i<10;i++){
            if (i!=0)printf (" ");
            printf ("%d",ar[i]);
        }
        printf ("\n");
    }
}