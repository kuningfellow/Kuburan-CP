#include <bits/stdc++.h>
using namespace std;
int main(){
    int kas=1;
    while (1<2){
        int n,m;
        cin>>n>>m;
        if (n==0&&m==0)break;
        char rem[n][m+1];
        int vis[n][m];
        queue<pair<int,int> >q;
        for (int i=0;i<n;i++){
            scanf("%s",rem[i]);
            for (int j=0;j<m;j++){
                vis[i][j]=0;
                if (rem[i][j]=='A'){
                    q.push(pair<int,int>(i,j));
                }
            }
        }
        int len=0;
        int x,y;
        while (!q.empty()){
            int siz=q.size();
            len++;
            for (int i=0;i<siz;i++){
                x=q.front().first;
                y=q.front().second;
                for (int j=-1;j<=1;j++){
                    for (int k=-1;k<=1;k++){
                        if (j==0&&k==0)continue;
                        if (x+j<n&&x+j>=0&&y+k<m&&y+k>=0&&vis[x+j][y+k]==0&&rem[x+j][y+k]=='A'+len){
                            vis[x+j][y+k]=1;
                            q.push(pair<int,int>(x+j,y+k));
                        }
                    }
                }
                q.pop();
            }
        }
        printf ("Case %d: %d\n",kas++,len);
    }
}
