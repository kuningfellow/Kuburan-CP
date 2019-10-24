//UVA 10168 Summation of Four Primes
#include <bits/stdc++.h>
using namespace std;
bool isprime[10000005];
int lis[700000];
int siz;
void sieve(){
    for (int i=2;i<10000005;i++){
        if (isprime[i]==0){
            lis[siz++]=i;
            for (int j=i*2;j<10000005;j+=i){
                isprime[j]=1;
            }
        }
    }
}
int main(){
    sieve();
    int n;
    while (scanf("%d",&n)!=EOF){
        int mode=0;
        if (n%2==0){
            mode=1;
            n-=4;
        }
        else{
            mode=2;
            n-=5;
        }
        if (n>3){
            for (int i=0;i<siz;i++){
                if (isprime[n-lis[i]]==0){
                    if (mode==1)
                        printf ("2 2 %d %d\n",lis[i],n-lis[i]);
                    else
                        printf ("2 3 %d %d\n",lis[i],n-lis[i]);
                    break;
                }
            }
        }
        else printf ("Impossible.\n");
    }
}
