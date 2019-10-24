#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        int n,m;
        cin>>n>>m;
        char rem[n][m+1];
        int vis[n][m];
        vector<pair<int,int> >lis[26];
        int xs,ys;
        int st[3][2];
        for (int i=0;i<n;i++){
            scanf("%s",rem[i]);
            for (int j=0;j<m;j++){
                if (rem[i][j]!='.'&&rem[i][j]!='#'&&rem[i][j]>'D'&&rem[i][j]<='Z'){
                    lis[rem[i][j]-'A'].push_back(pair<int,int>(i,j));
                }
                if (rem[i][j]=='A'){
                    st[0][0]=i;
                    st[0][1]=j;
                }
                if (rem[i][j]=='B'){
                    st[1][0]=i;
                    st[1][1]=j;
                }
                if (rem[i][j]=='C'){
                    st[2][0]=i;
                    st[2][1]=j;
                }
                if (rem[i][j]=='#'){
                    xs=i;
                    ys=j;
                }
            }
        }
        int ans=0;
        for (int i=0;i<3;i++){
            int x,y;
            queue<pair<int,int> >q;
            q.push(pair<int,int>(st[i][0],st[i][1]));
            for (int j=0;j<n;j++){
                for (int k=0;k<m;k++){
                    vis[j][k]=0;
                }
            }
            int tim=0;
            while (!q.empty()&&vis[xs][ys]==0){
                tim++;
                int siz=q.size();
                for (int j=0;j<siz;j++){
                    x=q.front().first;
                    y=q.front().second;
                    for (int k=-1;k<2;k++){
                        for (int l=-1;l<2;l++){
                            if (k==0&&l==0)continue;
                            if (x+k<n&&x+k>=0&&y+l<m&&y+l>=0&&vis[x+k][y+l]==0&&rem[x+k][y+l]!='D'){
                                vis[x+k][y+l]=1;
                                q.push(pair<int,int>(x+k,y+l));
                            }
                        }
                    }
                    if (rem[x][y]>'D'&&rem[x][y]<='Z'){
                        for (int z=0;z<lis[rem[x][y]-'A'].size();z++){
                            int tx=lis[rem[x][y]-'A'][z].first;
                            int ty=lis[rem[x][y]-'A'][z].second;
                            if (vis[tx][ty]==0){
                                vis[tx][ty]=1;
                                q.push(pair<int,int>(tx,ty));
                            }
                        }
                    }
                    q.pop();
                }
            }
            if (vis[xs][ys]==0){
                ans=-1;
                break;
            }
            ans=max(tim,ans);
        }
        printf ("Case %d: ",kas++);
        if (ans==-1)printf ("impossible\n");
        else printf ("%d\n",ans);
    }
}
