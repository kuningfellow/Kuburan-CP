//UVA 630 Anagrams (II)
#include <bits/stdc++.h>
using namespace std;
struct data{
    char str[21];
    int cnt[26];
};
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        data rem[n];
        for (int i=0;i<n;i++){
            scanf("%s",rem[i].str);
            for (int j=0;j<26;j++)
                rem[i].cnt[j]=0;
            for (int j=0;j<strlen(rem[i].str);j++){
                rem[i].cnt[rem[i].str[j]-'a']++;
            }
        }
        while (1<2){
            char ram[50];
            scanf("%s",ram);
            if (!strcmp(ram,"END"))
                break;
            printf ("Anagrams for: %s\n",ram);
            int cnt[26]={};
            for (int i=0;i<strlen(ram);i++){
                cnt[ram[i]-'a']++;
            }
            int found=0;
            for (int i=0;i<n;i++){
                int match=1;
                for (int j=0;j<26;j++){
                    if (cnt[j]!=rem[i].cnt[j]){
                        match=0;
                        break;
                    }
                }
                if (match==1){
                    found++;
                    printf ("%3d) %s\n",found,rem[i].str);
                }
            }
            if (found==0){
                printf ("No anagrams for: %s\n",ram);
            }
        }
        if (tc!=0)printf ("\n");
    }
}