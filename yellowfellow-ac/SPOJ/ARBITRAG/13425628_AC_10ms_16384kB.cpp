#include <bits/stdc++.h>
using namespace std;
int main(){
    int kas=1;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    while (1<2){
        int n;
        cin>>n;
        if (n==0)break;
        double con[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                con[i][j]=0;
            }
        }
        map<string,int>ma;
        for (int i=0;i<n;i++){
            string rem;
            cin>>rem;
            ma[rem]=i;
        }
        int m;
        cin>>m;
        for (int i=0;i<m;i++){
            string rem,ram;
            double rate;
            cin>>rem;
            cin>>rate;
            cin>>ram;
            con[ma[rem]][ma[ram]]=rate;
        }
        int val=1;
        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    con[i][j]=max(con[i][j],con[i][k]*con[k][j]);
                    if (i==j&&con[i][j]>1.0){
                        val=0;
                    }
                }
            }
        }
        printf ("Case %d: ",kas++);
        if (val==1){
            printf ("No\n");
        }
        else printf ("Yes\n");
    }
}