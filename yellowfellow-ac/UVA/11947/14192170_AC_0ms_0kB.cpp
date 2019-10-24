//UVA 11947 Cancer or Scorpio
#include <bits/stdc++.h>
using namespace std;
bool leap(int x){
    if (x%400==0||(x%4==0&&x%100!=0))
        return 1;
    return 0;
}
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int tc,kas=1;
    cin>>tc;
    while (tc--){
        char rem[9];
        scanf("%s",rem);
        int m=(rem[0]-'0')*10+rem[1]-'0';
        int d=(rem[2]-'0')*10+rem[3]-'0';
        int y=(rem[4]-'0')*1000+(rem[5]-'0')*100+(rem[6]-'0')*10+rem[7]-'0';
        int prog=40*7;
        m--;
        d--;
        while (prog--){
            d++;
            if (leap(y)&&m==1){
                if (d==29){
                    d=0;
                    m++;
                }
            }
            else{
                if (d==month[m]){
                    d=0;
                    m++;
                }
            }
            if (m==12){
                m=0;
                y++;
            }
        }
        m++;
        d++;
        printf ("%d %02d/%02d/%04d ",kas++,m,d,y);
        if (m==1&&d>=21)printf ("aquarius\n");
        else if (m==2&&d<=19)printf ("aquarius\n");
        else if (m==2&&d>=20)printf ("pisces\n");
        else if (m==3&&d<=20)printf ("pisces\n");
        else if (m==3&&d>=21)printf ("aries\n");
        else if (m==4&&d<=20)printf ("aries\n");
        else if (m==4&&d>=21)printf ("taurus\n");
        else if (m==5&&d<=21)printf ("taurus\n");
        else if (m==5&&d>=22)printf ("gemini\n");
        else if (m==6&&d<=21)printf ("gemini\n");
        else if (m==6&&d>=22)printf ("cancer\n");
        else if (m==7&&d<=22)printf ("cancer\n");
        else if (m==7&&d>=23)printf ("leo\n");
        else if (m==8&&d<=21)printf ("leo\n");
        else if (m==8&&d>=22)printf ("virgo\n");
        else if (m==9&&d<=23)printf ("virgo\n");
        else if (m==9&&d>=24)printf ("libra\n");
        else if (m==10&&d<=23)printf ("libra\n");
        else if (m==10&&d>=24)printf ("scorpio\n");
        else if (m==11&&d<=22)printf ("scorpio\n");
        else if (m==11&&d>=23)printf ("sagittarius\n");
        else if (m==12&&d<=22)printf ("sagittarius\n");
        else if (m==12&&d>=23)printf ("capricorn\n");
        else if (m==1&&d<=20)printf ("capricorn\n");
    }
}