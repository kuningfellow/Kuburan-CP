//UVA 10443 Rock, Scissors, Paper
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,m,d;
        cin>>n>>m>>d;
        char rem[n][m+1];
        char ram[n][m+1];
        for (int i=0;i<n;i++){
            scanf("%s",rem[i]);
            for (int j=0;j<m;j++){
                ram[i][j]=rem[i][j];
            }
        }
        int mov[4][2]={-1,0,0,-1,1,0,0,1};
        while (d--){
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    for (int k=0;k<4;k++){
                        int x=mov[k][0];
                        int y=mov[k][1];
                        if (i+x<n&&i+x>=0&&j+y<m&&j+y>=0){
                            if (rem[i][j]=='R'&&rem[i+x][j+y]=='S')ram[i+x][j+y]='R';
                            else if (rem[i][j]=='S'&&rem[i+x][j+y]=='P')ram[i+x][j+y]='S';
                            else if (rem[i][j]=='P'&&rem[i+x][j+y]=='R')ram[i+x][j+y]='P';
                        }
                    }
                }
            }
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    rem[i][j]=ram[i][j];
                }
            }
        }
        for (int i=0;i<n;i++){
            printf ("%s\n",rem[i]);
        }
        if (tc!=0)printf ("\n");
    }
}