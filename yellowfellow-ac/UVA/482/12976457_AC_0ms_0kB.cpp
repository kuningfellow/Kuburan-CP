#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc,fir=1;
    cin>>tc;
    while (tc--){
        char rem[5000];
        rem[0]='\0';
        while (strlen(rem)==0){
            scanf("%[^\n]",rem);
            getchar();
        }
        int ar[5000];
        int siz=0,num=0,l;
        l=strlen(rem);
        for (int i=0;i<l;i++){
            if (rem[i]>='0'&&rem[i]<='9'){
                num*=10;
                num+=rem[i]-'0';
            }
            else{
                ar[siz++]=num-1;
                num=0;
            }
        }
        if (num>0){
            ar[siz++]=num-1;
        }
        int br[siz];
        for (int i=0;i<siz;i++){
            br[ar[i]]=i;
        }
        char cr[siz][5000];
        for (int i=0;i<siz;i++){
            scanf("%s",&cr[i]);
        }
        if (fir==0)printf ("\n");
        fir=0;
        for (int i=0;i<siz;i++){
            printf ("%s\n",cr[br[i]]);
        }
    }
}
