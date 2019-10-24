#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1<2){
        int n,m,q;
        cin>>n>>m>>q;
        if (n==0&&m==0&&q==0){
            break;
        }
        int a,b,c;
        vector<pair<int,int> >lis[n];
        for (int i=0;i<m;i++){
            cin>>a>>b>>c;
            lis[a].push_back(pair<int,int>(b,c));
        }
        int cost[n][n];
        int neg[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cost[i][j]=(1<<28);
                if (i==j){
                    cost[i][j]=0;
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n-1;j++){
                for (int k=0;k<n;k++){
                    for (int l=0;l<lis[k].size();l++){
                        if (cost[i][k]!=(1<<28)){
                            cost[i][lis[k][l].first]=min(cost[i][lis[k][l].first],cost[i][k]+lis[k][l].second);
                        }
                    }
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                neg[i][j]=cost[i][j];
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n-1;j++){
                for (int k=0;k<n;k++){
                    for (int l=0;l<lis[k].size();l++){
                        if (neg[i][k]!=(1<<28)){
                            neg[i][lis[k][l].first]=min(neg[i][lis[k][l].first],neg[i][k]+lis[k][l].second);
                        }
                    }
                }
            }
        }
        for (int i=0;i<q;i++){
            cin>>a>>b;
            if (cost[a][b]==(1<<28)){
                printf ("Impossible\n");
            }
            else{
                if (cost[a][b]>neg[a][b]){
                    printf ("-Infinity\n");
                }
                else{
                    printf ("%d\n",cost[a][b]);
                }
            }
        }
        printf ("\n");
    }
}