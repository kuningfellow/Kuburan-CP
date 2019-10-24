#include <bits/stdc++.h>
using namespace std;
char rem[100005];
int mark[100005];
int murk[100005];
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        scanf("%s",rem);
        int n;
        cin>>n;
        int take=n;
        int l=strlen(rem);
        for (int j=0;j<l;j++){
            mark[j]=0;
            murk[j]=0;
        }
        int i=0;
        vector<int>debt;
        while (take>0&&i<l){
            if (debt.size()==0){
                debt.push_back(i);
                i++;
            }
            else if ( rem[i] >= rem[debt[debt.size()-1]] ){
                debt.push_back(i);
                i++;
            }
            else{
                murk[debt[debt.size()-1]]=1;
                take--;
                debt.pop_back();
            }
        }
        while (take>0){
            murk[debt[debt.size()-1]]=1;
            take--;
            debt.pop_back();
        }
        i=0;
        while (i<l){
            if (murk[i]==0)printf ("%c",rem[i]);
            i++;
        }
        printf ("\n");
        i=0;
        take=n;
        debt.clear();
        while (take>0&&i<l){
            if (debt.size()==0){
                debt.push_back(i);
                i++;
            }
            else if ( rem[i] <= rem[debt[debt.size()-1]] ){
                debt.push_back(i);
                i++;
            }
            else{
                mark[debt[debt.size()-1]]=1;
                take--;
                debt.pop_back();
            }
        }
        while (take>0){
            mark[debt[debt.size()-1]]=1;
            take--;
            debt.pop_back();
        }
        i=0;
        while (i<l){
            if (mark[i]==0)printf ("%c",rem[i]);
            i++;
        }
        printf ("\n");
    }
return 0;
}