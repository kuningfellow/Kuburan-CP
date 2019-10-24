#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        char rem[500];
        scanf("%s",rem);
        int num[500],tnum[500];
        int predif[500];
        int l=strlen(rem);
        for (int i=0;i<l;i++){
            num[i]=rem[i]-'0';
        }
        int ans=1;
        for (int i=l;i>1;i--){
            for (int s=0;s<10;s++){
                for (int j=0;j<l;j++){
                    tnum[j]=s-num[j]+10;
                    tnum[j]%=10;
                    predif[j]=0;
                }
                int kil=0;
                int car=0;
                for (int j=0;j<=l-i;j++){
                    car+=predif[j];
                    kil=(tnum[j]-(car%10)+10)%10;
                    tnum[j]=0;
                    car+=kil;
                    predif[j+i]-=kil;
                }
                for (int j=l-i+1;j<l;j++){
                    car+=predif[j];
                    tnum[j]-=car%10+10;
                    tnum[j]%=10;
                }
                int flag=1;
                for (int j=0;j<l;j++){
                    if (tnum[j]!=0){
                        flag=0;
                        break;
                    }
                }
                if (flag==1){
                    ans=i;
                    break;
                }
            }
            if (ans!=1)break;
        }
        printf("%d\n",ans);
    }
}
