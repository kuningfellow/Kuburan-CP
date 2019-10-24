#include <bits/stdc++.h>
using namespace std;
int ar[10000000];
int cor(char a){
    if (a>='0'&&a<='9')return a-'0';
    else if (a>='A'&&a<='C')return 2;
    else if (a>='D'&&a<='F')return 3;
    else if (a>='G'&&a<='I')return 4;
    else if (a>='J'&&a<='L')return 5;
    else if (a>='M'&&a<='O')return 6;
    else if (a>='P'&&a<='S'&&a!='Q')return 7;
    else if (a>='T'&&a<='V')return 8;
    else if (a>='W'&&a<='Y')return 9;
    else return 0;
}
int main(){
    int tc,fir=1;
    cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        for (int i=0;i<10000000;i++){
            ar[i]=0;
        }
        int num,mul;
        char rem[500];
        for (int i=0;i<n;i++){
            scanf("%s",rem);
            num=0;
            mul=1;
            for (int i=strlen(rem)-1;i>=0;i--){
                if (rem[i]!='-'){
                    num+=cor(rem[i])*mul;
                    mul*=10;
                }
            }
            ar[num]++;
        }
        int found=0;
        if (fir==0)printf ("\n");
        fir=0;
        for (int i=0;i<10000000;i++){
            if (ar[i]>1){
                found=1;
                printf ("%03d-%04d %d\n",i/10000,i%10000,ar[i]);
            }
        }
        if (found==0){
            printf ("No duplicates.\n");
        }
    }
}
