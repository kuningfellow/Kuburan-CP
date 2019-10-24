#include <bits/stdc++.h>
using namespace std;
char rem[20]="welcome to code jam";
char ram[505];
int dp[505][20];
int l;
int serc(int x, int p){
    if (x==l){
        if (p==19){
            return 1;
        }
        return 0;
    }
    if (dp[x][p]!=-1){
        return dp[x][p];
    }
    int r1=serc(x+1,p);
    int r2=0;
    if (ram[x]==rem[p]&&p<19){
        r2=serc(x+1,p+1);
    }
    return dp[x][p]=(r1+r2)%10000;
}
int main(){
    int tc,kas=1;
    cin>>tc;
    getchar();
    while (tc--){
        scanf("%[^\n]",ram);
        getchar();
        l=strlen(ram);
        for (int i=0;i<l;i++){
            for (int j=0;j<20;j++){
                dp[i][j]=-1;
            }
        }
        printf ("Case #%d: %04d\n",kas++,serc(0,0));
    }
}
