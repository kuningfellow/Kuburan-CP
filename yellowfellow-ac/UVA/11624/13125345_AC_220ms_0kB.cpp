#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        char rem[n][m+1];
        int tj[n][m];
        int tf[n][m];
        queue<pair<int,int> >q;
        queue<pair<int,int> >fq;
        for (int i=0;i<n;i++){
            scanf("%s",rem[i]);
            for (int j=0;j<m;j++){
                tj[i][j]=(1<<30);
                tf[i][j]=(1<<30);
                if (rem[i][j]=='J'){
                    q.push(pair<int,int>(i,j));
                    tj[i][j]=1;
                }
                if (rem[i][j]=='F'){
                    fq.push(pair<int,int>(i,j));
                    tf[i][j]=1;
                }
            }
        }
        int x,y,t=2;
        while (!q.empty()){
            int siz=q.size();
            for (int i=0;i<siz;i++){
                x=q.front().first;
                y=q.front().second;
                q.pop();
                if (x+1<n&&tj[x+1][y]==(1<<30)&&rem[x+1][y]=='.'){
                    tj[x+1][y]=t;
                    q.push(pair<int,int>(x+1,y));
                }
                if (y+1<m&&tj[x][y+1]==(1<<30)&&rem[x][y+1]=='.'){
                    tj[x][y+1]=t;
                    q.push(pair<int,int>(x,y+1));
                }
                if (x-1>=0&&tj[x-1][y]==(1<<30)&&rem[x-1][y]=='.'){
                    tj[x-1][y]=t;
                    q.push(pair<int,int>(x-1,y));
                }
                if (y-1>=0&&tj[x][y-1]==(1<<30)&&rem[x][y-1]=='.'){
                    tj[x][y-1]=t;
                    q.push(pair<int,int>(x,y-1));
                }
            }
            t++;
        }
        t=2;
        while (!fq.empty()){
            int siz=fq.size();
            for (int i=0;i<siz;i++){
                x=fq.front().first;
                y=fq.front().second;
                fq.pop();
                if (x+1<n&&tf[x+1][y]==(1<<30)&&rem[x+1][y]=='.'){
                    tf[x+1][y]=t;
                    fq.push(pair<int,int>(x+1,y));
                }
                if (y+1<m&&tf[x][y+1]==(1<<30)&&rem[x][y+1]=='.'){
                    tf[x][y+1]=t;
                    fq.push(pair<int,int>(x,y+1));
                }
                if (x-1>=0&&tf[x-1][y]==(1<<30)&&rem[x-1][y]=='.'){
                    tf[x-1][y]=t;
                    fq.push(pair<int,int>(x-1,y));
                }
                if (y-1>=0&&tf[x][y-1]==(1<<30)&&rem[x][y-1]=='.'){
                    tf[x][y-1]=t;
                    fq.push(pair<int,int>(x,y-1));
                }
            }
            t++;
        }
        int ans=(1<<30);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if ((i==0||i==n-1)&&tj[i][j]<tf[i][j]){
                    ans=min(ans,tj[i][j]);
                }
                if ((j==0||j==m-1)&&tj[i][j]<tf[i][j]){
                    ans=min(ans,tj[i][j]);
                }
            }
        }
        if (ans!=(1<<30))
            printf ("%d\n",ans);
        else printf ("IMPOSSIBLE\n");
    }
}
