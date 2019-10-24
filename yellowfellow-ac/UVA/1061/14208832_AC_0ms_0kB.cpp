//UVA 1061 Consanguine Casculations
#include <bits/stdc++.h>
using namespace std;
void print(pair<int,int> a){
    if (a.first==0)printf ("O");
    else if (a.first==1)printf ("A");
    else if (a.first==2)printf ("B");
    else if (a.first==3)printf ("AB");
    if (a.second==0)printf ("-");
    else if (a.second==1)printf ("+");
}
int main(){
    int kas=1;
    while (1<2){
        char s[3][50];
        scanf("%s",s[0]);
        scanf("%s",s[1]);
        scanf("%s",s[2]);
        if (s[0][0]=='E')break;
        vector<pair<int,int> >ans;
        printf ("Case %d: ",kas++);
        int missing;
        for (int i=0;i<3;i++){
            if (!strcmp(s[i],"?")){
                missing=i;
                break;
            }
        }
        int sel[2];
        int idx=0;
        for (int i=0;i<3&&idx<2;i++){
            if (i==missing)continue;
            sel[idx++]=i;
        }
        int abo1[2]={};
        int abo2[2]={};
        int rh1[2]={};
        int rh2[2]={};
        int vis[4][2]={};
        for (int i=0;i<strlen(s[sel[0]])-1;i++){
            if (s[sel[0]][i]=='A')abo1[i]=1;
            else if (s[sel[0]][i]=='B')abo1[i]=2;
        }
        for (int i=0;i<strlen(s[sel[1]])-1;i++){
            if (s[sel[1]][i]=='A')abo2[i]=1;
            else if (s[sel[1]][i]=='B')abo2[i]=2;
        }
        if (s[sel[0]][strlen(s[sel[0]])-1]=='+')rh1[0]=1;
        if (s[sel[1]][strlen(s[sel[1]])-1]=='+')rh2[0]=1;
        if (missing==2){
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++){
                    for (int k=0;k<2;k++){
                        for (int l=0;l<2;l++){
                            vis[(abo1[i]|abo2[j])][(rh1[k]|rh2[l])]=1;
                        }
                    }
                }
            }
            if (vis[0][0]==1)ans.push_back(pair<int,int>(0,0));
            if (vis[0][1]==1)ans.push_back(pair<int,int>(0,1));
            if (vis[3][0]==1)ans.push_back(pair<int,int>(3,0));
            if (vis[3][1]==1)ans.push_back(pair<int,int>(3,1));
            if (vis[2][0]==1)ans.push_back(pair<int,int>(2,0));
            if (vis[2][1]==1)ans.push_back(pair<int,int>(2,1));
            if (vis[1][0]==1)ans.push_back(pair<int,int>(1,0));
            if (vis[1][1]==1)ans.push_back(pair<int,int>(1,1));
        }
        else{
            int take[4][2]={};
            for (int i=0;i<2;i++){
                for (int j=0;j<3;j++){
                    for (int k=0;k<2;k++){
                        for (int l=0;l<2;l++){
                            int m1=abo1[i]|j;
                            int m2=abo2[0]|abo2[1];
                            int n1=rh1[k]|l;
                            int n2=rh2[0]|rh2[1];
                            if (m1==m2&&n1==n2){
                                vis[j][l]=1;
                                if (j==0){
                                    vis[1][l]=1;
                                    vis[2][l]=1;
                                    vis[1][1]=1;
                                    vis[2][1]=1;
                                }
                                if (j==1||j==2){
                                    vis[3][l]=1;
                                    vis[3][1]=1;
                                }
                                vis[j][1]=1;
                            }
                        }
                    }
                }
            }
            if (vis[0][0]==1)ans.push_back(pair<int,int>(0,0));
            if (vis[0][1]==1)ans.push_back(pair<int,int>(0,1));
            if (vis[3][0]==1)ans.push_back(pair<int,int>(3,0));
            if (vis[3][1]==1)ans.push_back(pair<int,int>(3,1));
            if (vis[2][0]==1)ans.push_back(pair<int,int>(2,0));
            if (vis[2][1]==1)ans.push_back(pair<int,int>(2,1));
            if (vis[1][0]==1)ans.push_back(pair<int,int>(1,0));
            if (vis[1][1]==1)ans.push_back(pair<int,int>(1,1));
        }
        if (missing==2)printf ("%s %s ",s[0],s[1]);
        else if (missing==1)printf ("%s ",s[0]);
        if (ans.size()==0)printf ("IMPOSSIBLE");
        for (int i=0;i<ans.size();i++){
            if (i==0&&ans.size()!=1)printf ("{");
            if (i!=0)printf (", ");
            print(ans[i]);
            if (i==ans.size()-1&&ans.size()!=1)printf ("}");
        }
        if (missing==2)printf ("\n");
        else if (missing==1)printf (" %s\n",s[2]);
        else if (missing==0)printf (" %s %s\n",s[1],s[2]);
    }
}