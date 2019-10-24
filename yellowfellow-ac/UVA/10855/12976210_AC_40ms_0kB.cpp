#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1<2){
        int N,n;
        cin>>N>>n;
        if (N==0&&n==0)break;
        char rem[N][N+1];
        for (int i=0;i<N;i++){
            scanf("%s",rem[i]);
        }
        char ram[n][n+1];
        for (int i=0;i<n;i++){
            scanf("%s",ram[i]);
        }
        int cou[4]={0,0,0,0};
        int val[4];
        for (int i=0;i<=N-n;i++){
            for (int j=0;j<=N-n;j++){
                for (int k=0;k<4;k++)val[k]=1;
                for (int k=0;k<n;k++){
                    for (int l=0;l<n;l++){
                        if (rem[i+k][j+l]!=ram[k][l])val[0]=0;
                        if (rem[i+k][j+l]!=ram[n-1-l][k])val[1]=0;
                        if (rem[i+k][j+l]!=ram[n-1-k][n-1-l])val[2]=0;
                        if (rem[i+k][j+l]!=ram[l][n-1-k])val[3]=0;
                    }
                }
                for (int k=0;k<4;k++){
                    cou[k]+=val[k];
                }
            }
        }
        for (int k=0;k<4;k++){
            printf ("%d",cou[k]);
            if (k<3)printf (" ");
            else printf ("\n");
        }
    }
}
