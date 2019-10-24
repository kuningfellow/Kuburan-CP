//UVA 156 Ananagrams
#include <bits/stdc++.h>
using namespace std;
struct cnts{
    int cnt[26];
};
int main(){
    vector<string>str;
    vector<cnts>ok;
    while (1<2){
        string rem;
        cin>>rem;
        if (rem=="#")break;
        str.push_back(rem);
        cnts temp;
        for (int j=0;j<26;j++)
            temp.cnt[j]=0;
        for (int j=0;j<rem.length();j++){
            if (rem[j]>='A'&&rem[j]<='Z'){
                temp.cnt[rem[j]-'A']++;
            }
            else{
                temp.cnt[rem[j]-'a']++;
            }
        }
        ok.push_back(temp);
    }
    sort(str.begin(),str.end());
    for (int i=0;i<str.size();i++){
        int cn=0;
        cnts temp;
        for (int j=0;j<26;j++)
            temp.cnt[j]=0;
        for (int j=0;j<str[i].length();j++){
            if (str[i][j]>='A'&&str[i][j]<='Z'){
                temp.cnt[str[i][j]-'A']++;
            }
            else{
                temp.cnt[str[i][j]-'a']++;
            }
        }
        for (int j=0;j<ok.size();j++){
            int val=1;
            for (int k=0;k<26;k++){
                if (temp.cnt[k]!=ok[j].cnt[k]){
                    val=0;
                    break;
                }
            }
            cn+=val;
        }
        if (cn==1)cout<<str[i]<<endl;
    }
}