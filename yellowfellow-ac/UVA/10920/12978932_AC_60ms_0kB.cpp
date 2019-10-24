#include <bits/stdc++.h>
using namespace std;
int main(){
    while (1<2){
        long long int a,b;
        cin>>a>>b;
        if (a==0&&b==0)break;
        long long int dia=1;
        long long int p=0;
        long long int x=p-1,y=p-1;
        for (;dia<100000;dia+=2){
            if (dia*dia>=b){
                b=dia*dia-b;
                x=dia/2;
                y=dia/2;
                break;
            }
            p+=2;
        }
        if (b>0){
            for (int i=1;i<=4;i++){
                if (b<=i*p){
                    b=i*p-b;
                    if (i==1){
                        y-=p;
                        y+=b;
                    }
                    else if (i==2){
                        x-=p;
                        y-=p;
                        x+=b;
                    }
                    else if (i==3){
                        x-=p;
                        y-=b;
                    }
                    else if (i==4){
                        x-=b;
                    }
                    break;
                }
            }
        }
        printf ("Line = %lld, column = %lld.\n",y+a/2+1,x+a/2+1);
    }
}
