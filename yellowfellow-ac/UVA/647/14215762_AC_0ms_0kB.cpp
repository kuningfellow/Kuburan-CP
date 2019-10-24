//UVA 647 Chutes and Ladders
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>moves;
    int idx=1;
    while (idx!=0){
        scanf("%d",&idx);
        moves.push_back(idx);
    }
    idx=0;
    int ar[101];
    int br[101];
    while (1<2){
        int n;
        scanf("%d",&n);
        if (n==0)break;
        for (int i=0;i<101;i++){
            ar[i]=0;
            br[i]=0;
        }
        int p[n][2];
        for (int i=0;i<n;i++){
            p[i][0]=0;
            p[i][1]=1;
        }
        int a=1,b=1;
        while (1<2){
            scanf("%d%d",&a,&b);
            if (a==0&&b==0)break;
            ar[a]=b;
        }
        while (1<2){
            scanf("%d",&a);
            if (a==0)break;
            if (a<0)br[-a]-=1;
            else br[a]+=1;
        }
        int win=-1;
        idx=0;
        while (1<2){
            for (int i=0;i<n;i++){
                while (p[i][1]>0){
                    p[i][1]--;
                    p[i][0]+=moves[idx];
                    if (p[i][0]>100){
                        p[i][0]-=moves[idx];
                        idx++;
                        continue;
                    }
                    idx++;
                    p[i][1]+=br[p[i][0]];
                    if (ar[p[i][0]]!=0){
                        p[i][0]=ar[p[i][0]];
                    }
                    if (p[i][0]==100){
                        win=i+1;
                        break;
                    }
                }
                p[i][1]++;
                if (win!=-1)break;
            }
            if (win!=-1)break;
        }
        printf ("%d\n",win);
    }
}