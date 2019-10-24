//UVA 454 Anagrams
#include <bits/stdc++.h>
using namespace std;
struct data{
    char str[10000];
    int cnt[256];
    bool operator<(const data& a)const{
        int l1=strlen(str);
        int l2=strlen(a.str);
        int l=min(l1,l2);
        for (int i=0;i<l;i++){
            if (str[i]<a.str[i]){
                return 1;
            }
            if (str[i]>a.str[i]){
                return 0;
            }
        }
        if (l1<l2)return 1;
        return 0;
    }
};
int main(){
    int tc;
    cin>>tc;
    data rem[105];
    while (tc--){
        int siz=0;
        int take[105][105];
        for (int i=0;i<105;i++){
            for (int j=0;j<105;j++){
                take[i][j]=0;
            }
        }
        while (1<2){
            rem[siz].str[0]='\0';
            scanf("%[^\n]",rem[siz].str);
            getchar();
            if (siz!=0&&strlen(rem[siz].str)==0)
                break;
            if (strlen(rem[siz].str)!=0){
                for (int i=0;i<256;i++){
                    rem[siz].cnt[i]=0;
                }
                for (int i=0;i<strlen(rem[siz].str);i++){
                    if (rem[siz].str[i]!=' ')
                        rem[siz].cnt[rem[siz].str[i]]++;
                }
                siz++;
            }
        }
        sort(rem,rem+siz);
        for (int i=0;i<siz;i++){
            for (int j=0;j<siz;j++){
                if (i==j||take[i][j]==1)continue;
                int match=1;
                for (int k=0;k<256;k++){
                    if (rem[i].cnt[k]!=rem[j].cnt[k]){
                        match=0;
                        break;
                    }
                }
                if (match==1){
                    take[i][j]=1;
                    take[j][i]=1;
                    printf ("%s = %s\n",rem[i].str,rem[j].str);
                }
            }
        }
        if (tc!=0)printf ("\n");
    }
}