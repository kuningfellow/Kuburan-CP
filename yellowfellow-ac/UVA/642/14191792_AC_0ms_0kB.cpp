//UVA 642 Word Amalgamation
#include <bits/stdc++.h>
using namespace std;
struct data{
    char str[21];
    int cnt[26];
    bool operator<(const data& a){
        int l1=strlen(str);
        int l2=strlen(a.str);
        int l=min(l1,l2);
        for (int i=0;i<l;i++){
            if (str[i]<a.str[i])
                return 1;
            if (str[i]>a.str[i]){
                return 0;
            }
        }
        if (l1<l2)return 1;
        return 0;
    }
};
int main(){
    data rem[101];
    int n=0;
    while (1<2){
        scanf("%s",rem[n].str);
        if (!strcmp(rem[n].str,"XXXXXX"))
            break;
        for (int j=0;j<26;j++)
            rem[n].cnt[j]=0;
        for (int j=0;j<strlen(rem[n].str);j++){
            rem[n].cnt[rem[n].str[j]-'a']++;
        }
        n++;
    }
    sort(rem,rem+n);
    while (1<2){
        char ram[50];
        scanf("%s",ram);
        if (!strcmp(ram,"XXXXXX"))
            break;
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
                printf ("%s\n",rem[i].str);
            }
        }
        if (found==0){
            printf ("NOT A VALID WORD\n");
        }
        printf ("******\n");
    }
}