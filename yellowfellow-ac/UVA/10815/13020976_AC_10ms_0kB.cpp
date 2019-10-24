#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,int>mark;
    vector<string>lis;
    string rem;
    string ram="";
    mark[ram]=1;
    while (cin>>rem){
        ram="";
        for (int i=0;i<rem.size();i++){
            if (rem[i]>='A'&&rem[i]<='Z'){
                rem[i]=rem[i]-'A'+'a';
            }
            if (rem[i]>='a'&&rem[i]<='z'){
                ram+=rem[i];
            }
            else{
                if (mark[ram]==0){
                    lis.push_back(ram);
                    mark[ram]=1;
                }
                ram="";
            }
        }
        if (mark[ram]==0){
            lis.push_back(ram);
            mark[ram]=1;
        }
    }
    sort(lis.begin(),lis.end());
    for (int i=0;i<lis.size();i++){
        cout<<lis[i]<<endl;
    }
}
