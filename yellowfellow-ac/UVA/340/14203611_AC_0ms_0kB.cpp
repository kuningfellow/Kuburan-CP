//UVA 340 Master-Mind Hints
#include <bits/stdc++.h>
using namespace std;
int main(){
    int kas=1;
    while (1<2){
        int n;
        cin>>n;
        if (n==0)break;
        int ar[n];
        int br[n];
        int cr[n];
        for (int i=0;i<n;i++){
            cin>>ar[i];
        }
        printf ("Game %d:\n",kas++);
        while (1<2){
            int sum=0;
            for (int i=0;i<n;i++){
                cin>>br[i];
                sum+=br[i];
                cr[i]=0;
            }
            if (sum==0)
                break;
            int st=0,we=0;
            for (int i=0;i<n;i++){
                if (ar[i]==br[i]){
                    st++;
                    cr[i]=1;
                    br[i]=-1;
                }
            }
            for (int i=0;i<n;i++){
                if (br[i]!=-1){
                    int ma=0;
                    for (int j=0;j<n;j++){
                        if (cr[j]==1)continue;
                        if (br[i]==ar[j]){
                            cr[j]=1;
                            ma=1;
                            break;
                        }
                    }
                    we+=ma;
                }
            }
            printf ("    (%d,%d)\n",st,we);
        }
    }
}