//UVA 353 Pesky Palindromes
#include <bits/stdc++.h>
using namespace std;
map<string,int>coun;
map<string,int>caun;
int main(){
    char rem[500];
    while (scanf("%s",rem)!=EOF){
        coun.clear();
        caun.clear();
        int cnt=0;
        for (int i=0;i<strlen(rem);i++){
            string ram="";
            string rram="";
            for (int j=0;i+j<strlen(rem)&&i-j>=0&&rem[i+j]==rem[i-j];j++){
                ram+=rem[i+j];
                if (coun[ram]==0){
                    cnt++;
                    coun[ram]=1;
                }
            }
            for (int j=0;i+j+1<strlen(rem)&&i-j>=0&&rem[i+j+1]==rem[i-j];j++){
                rram+=rem[i+j+1];
                if (caun[rram]==0){
                    cnt++;
                    caun[rram]=1;
                }
            }
        }
        printf ("The string '%s' contains %d palindromes.\n",rem,cnt);
    }
}