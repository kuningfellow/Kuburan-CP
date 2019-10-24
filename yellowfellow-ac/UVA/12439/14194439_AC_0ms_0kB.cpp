//UVA 12439 February 29
#include <bits/stdc++.h>
using namespace std;
char strmonth[12][500]={"January","February","March","April","May","June",
"July","August","September","October","November","December"};
bool leap(int x){
    if (x%400==0||(x%4==0&&x%100!=0))
        return 1;
    return 0;
}
int fin(int x){
    int ret=x/4;
    ret-=x/100;
    ret+=x/400;
    return ret;
}
int main(){
    int tc,kas=1;
    char rem[500];
    cin>>tc;
    while (tc--){
        int m1,d1,y1;
        scanf("%s",rem);
        for (int i=0;i<12;i++){
            if (!strcmp(rem,strmonth[i])){
                m1=i;
                break;
            }
        }
        scanf("%s",rem);
        d1=(rem[0]-'0')*10+(rem[1]-'0');
        scanf("%d",&y1);
        int m2,d2,y2;
        scanf("%s",rem);
        for (int i=0;i<12;i++){
            if (!strcmp(rem,strmonth[i])){
                m2=i;
                break;
            }
        }
        scanf("%s",rem);
        d2=(rem[0]-'0')*10+(rem[1]-'0');
        scanf("%d",&y2);
        int c2=fin(y2-1);
        int c1=fin(y1-1);
        int tot=c2-c1;
        if (leap(y2)&&(m2>1||(m2==1&&d2==29)))
            tot++;
        if (leap(y1)&&m1>1)
            tot--;
        printf ("Case %d: %d\n",kas++,tot);
    }
}