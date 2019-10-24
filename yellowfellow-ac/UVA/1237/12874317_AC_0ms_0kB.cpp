#include <bits/stdc++.h>
using namespace std;
struct dat{
    char name[50];
    int low;
    int high;
};
dat data[10005];
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%s%d%d",data[i].name,&data[i].low,&data[i].high);
        }
        int q;
        scanf("%d",&q);
        int m,f,p;
        while (q--){
            scanf("%d",&m);
            f=0;
            for (int i=0;i<n;i++){
                if (data[i].low<=m&&data[i].high>=m){
                    f++;
                    p=i;
if (f>1)break;
                }
            }
            if (f!=1)printf ("UNDETERMINED\n");
            else printf ("%s\n",data[p].name);
        }
        if (tc>0)printf ("\n");
    }
}