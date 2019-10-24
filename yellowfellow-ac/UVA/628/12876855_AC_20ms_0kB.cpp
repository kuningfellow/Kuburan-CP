#include <bits/stdc++.h>
using namespace std;
int n;
char rules[1005][500];
char rem[105][500];
vector<int>pick;
void serc(int x, int m){
    if (x==strlen(rules[m])){
        for (int i=0;i<strlen(rules[m]);i++){
            if (rules[m][i]=='#'){
                printf ("%s",rem[pick[i]]);
            }
            else{
                printf ("%d",pick[i]);
            }
        }
        printf ("\n");
        return;
    }
    if (rules[m][x]=='#'){
        for (int i=0;i<n;i++){
            pick.push_back(i);
            serc(x+1,m);
            pick.pop_back();
        }
    }
    else if (rules[m][x]=='0'){
        for (int i=0;i<10;i++){
            pick.push_back(i);
            serc(x+1,m);
            pick.pop_back();
        }
    }
    return;
}
int main(){
    while (scanf("%d",&n)!=EOF){
        for (int i=0;i<n;i++){
            scanf("%s",rem[i]);
        }
        int k;
        cin>>k;
        for (int i=0;i<k;i++){
            scanf("%s",rules[i]);
        }
        printf ("--\n");
        for (int i=0;i<k;i++){
            serc(0,i);
        }
    }
}
