//UVA 10849 Move the bishop
#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    while (tc--){
        int n;
        int s;
        scanf("%d%d",&n,&s);
        while (n--){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if ((a+b)%2!=(c+d)%2){
                printf ("no move\n");
            }
            else{
                int x=max(a-c,c-a);
                int y=max(b-d,d-b);
                if (x==0&&y==0)printf ("0\n");
                else if (x==y)printf ("1\n");
                else printf ("2\n");
            }
        }
    }
}