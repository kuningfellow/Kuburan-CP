#include <bits/stdc++.h>
using namespace std;
vector<int>lis[26];
stack<int>ans;
int vis[26];
void serc(int x){
    vis[x]=1;
    for (int i=0;i<lis[x].size();i++){
        if (vis[lis[x][i]]==0){
            serc(lis[x][i]);
        }
    }
    ans.push(x);
}
int main(){
    char rem[20005][25];
    int mark[26];
    for (int i=0;i<26;i++){
        mark[i]=0;
        vis[i]=0;
    }
    int siz=0;
    while (1<2){
        scanf("%s",rem[siz]);
        if (rem[siz++][0]=='#')break;
    }
    for (int i=0;i<siz-2;i++){
        int k=0;
        int l=min(strlen(rem[i]),strlen(rem[i+1]));
        int foun=0;
        while (k<l){
            if (rem[i][k]!=rem[i+1][k]){
                foun=1;
                break;
            }
            k++;
        }
        if (foun==1){
            lis[rem[i][k]-'A'].push_back(rem[i+1][k]-'A');
            mark[rem[i][k]-'A']=1;
        }
    }
    for (int i=0;i<26;i++){
        if (mark[i]==1&&vis[i]==0){
            serc(i);
        }
    }
    while (!ans.empty()){
        printf ("%c",ans.top()+'A');
        ans.pop();
    }
    printf ("\n");
}
