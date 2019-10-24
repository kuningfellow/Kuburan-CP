#include <bits/stdc++.h>
using namespace std;
int main(){
    int vis[7500];
    for (int i=0;i<7500;i++){
        vis[i]=0;
    }
    vis[0]=1;
    int cent[5]={50,25,10,5,1};
    for (int i=0;i<5;i++){
        for (int j=0;j<7500;j++){
            if (j-cent[i]>=0&&vis[j-cent[i]]!=0){
                vis[j]+=vis[j-cent[i]];
            }
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF){
        printf ("%d\n",vis[n]);
    }
}
