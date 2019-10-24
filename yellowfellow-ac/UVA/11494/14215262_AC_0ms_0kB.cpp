//UVA 11494 Queen
#include <bits/stdc++.h>
using namespace std;
int abs(int x){
    if (x<0)return -x;
    return x;
}
int main(){
    while (1<2){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if (a+b+c+d==0)break;
        if (a==c&&b==d)printf ("0\n");
        else if (a-c==0||b-d==0||abs(a-c)==abs(b-d))printf ("1\n");
        else printf ("2\n");
    }
}