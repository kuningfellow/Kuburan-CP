#include <bits/stdc++.h>
using namespace std;
int A,B,t;
int dp[1005][1005];
vector<int>mov;
int bac(int a,int b){
    if (a==t||b==t){
        for (int i=0;i<mov.size();i++){
            if (mov[i]==1)printf ("fill A\n");
            else if (mov[i]==2)printf ("fill B\n");
            else if (mov[i]==3)printf ("empty A\n");
            else if (mov[i]==4)printf ("empty B\n");
            else if (mov[i]==5)printf ("pour A B\n");
            else if (mov[i]==6)printf ("pour B A\n");
        }
        printf ("success\n");
        return 1;
    }
    int ret=0;
    int tmp;
    mov.push_back(1);
    if (a!=A&&dp[A][b]==0){
        dp[A][b]=1;
        ret=max(ret,bac(A,b));
    }
    mov.pop_back();

    mov.push_back(2);
    if (ret==0&&b!=B&&dp[a][B]==0){
        dp[a][B]=1;
        ret=max(ret,bac(a,B));
    }
    mov.pop_back();

    mov.push_back(3);
    if (ret==0&&a!=0&&dp[0][b]==0){
        dp[0][b]=1;
        ret=max(ret,bac(0,b));
    }
    mov.pop_back();

    mov.push_back(4);
    if (ret==0&&b!=0&&dp[a][0]==0){
        dp[a][0]=1;
        ret=max(ret,bac(a,0));
    }
    mov.pop_back();

    mov.push_back(5);
    tmp=min(a,B-b);
    if (ret==0&&a!=0&&dp[a-tmp][b+tmp]==0){
        dp[a-tmp][b+tmp]=1;
        ret=max(ret,bac(a-tmp,b+tmp));
    }
    mov.pop_back();

    mov.push_back(6);
    tmp=min(b,A-a);
    if (ret==0&&b!=0&&dp[a+tmp][b-tmp]==0){
        dp[a+tmp][b-tmp]=1;
        ret=max(ret,bac(a+tmp,b-tmp));
    }
    mov.pop_back();
    return ret;
}
int main(){
    while (scanf("%d%d%d",&A,&B,&t)!=EOF){
        for (int i=0;i<1005;i++){
            for (int j=0;j<1005;j++){
                dp[i][j]=0;
            }
        }
        bac(0,0);
    }
}
