#include<bits/stdc++.h>
using namespace std;

bool prime[1000005];

vector<int> pr;

void sieve(){
    for(int i = 2 ; i  < 1000000; i ++) if(i%2) prime[i] = true;
    prime[2] = true;
    for(int i = 3 ; i*i < 1000000 ; i += 2){
        if(prime[i]){
            for(int j = i*i ; j < 1000000 ; j += i) prime[j] = false;
        }
    }
    for(int i = 2 ; i < 1000000 ; i ++){
        if(prime[i]) pr.push_back(i);
    }
}

int main(){
    int x;
    scanf("%d",&x);
    sieve();
    int sem ;
    int sz = pr.size();
    int lang = 0 ;
    while(x>=4){
        for(int i = 0 ; i < sz; i ++){
            sem = x - pr[i];
            if(prime[sem] && (sem - pr[i])%2==0){
                x=sem-pr[i];
                lang ++ ;
                break;
            }
        }
    }
    printf("%d\n",lang);
    return 0;
}
