//UVA 11356 Dates
#include <bits/stdc++.h>
using namespace std;
bool leap(int x){
    if (x%400==0||(x%4==0&&x%100!=0))
        return 1;
    return 0;
}
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char strmonth[12][50]={"January","February","March","April","May","June",
"July","August","September","October","November","December"};
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        char rem[500];
        scanf("%s",rem);
        int y=(rem[0]-'0')*1000+(rem[1]-'0')*100+(rem[2]-'0')*10+(rem[3]-'0');
        int d=(rem[strlen(rem)-2]-'0')*10+(rem[strlen(rem)-1]-'0');
        char ram[500];
        for (int i=5;i<strlen(rem)-3;i++){
            ram[i-5]=rem[i];
            ram[i-4]='\0';
        }
        int m,q;
        for (int i=0;i<12;i++){
            if (!strcmp(ram,strmonth[i])){
                m=i;
                break;
            }
        }
        d--;
        cin>>q;
        while (q--){
            d++;
            if (m==1&&leap(y)){
                if (d==29){
                    d=0;
                    m++;
                }
            }
            else if (d==month[m]){
                d=0;
                m++;
            }
            if (m==12){
                m=0;
                y++;
            }
        }
        printf ("Case %d: %04d-%s-%02d\n",kas++,y,strmonth[m],d+1);
    }
}