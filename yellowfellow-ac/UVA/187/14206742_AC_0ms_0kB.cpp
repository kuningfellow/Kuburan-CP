//UVA 187 Transaction Processing
#include <bits/stdc++.h>
using namespace std;
int main(){
    char names[1000][35];
    char rem[500];
    vector<pair<int,double> >rec;
    while (1<2){
        scanf("%[^\n]",rem);
        getchar();
        int num=(rem[0]-'0')*100+(rem[1]-'0')*10+rem[2]-'0';
        if (num==0)break;
        int l=strlen(rem);
        for (int i=3;i<l;i++){
            names[num][i-3]=rem[i];
            names[num][i-2]='\0';
        }
    }
    double bal=0;
    double temp;
    int num;
    int prev=-1;
    while (1<2){
        int cor;
        while (1<2){
            scanf("%s",rem);
            scanf("%lf",&temp);
            num=(rem[0]-'0')*100+(rem[1]-'0')*10+rem[2]-'0';
            cor=(rem[3]-'0')*100+(rem[4]-'0')*10+rem[5]-'0';
            if (num==0)break;
            if (prev!=-1&&num!=prev)break;
            prev=num;
            bal+=temp;
            rec.push_back(pair<int,double>(cor,temp));
        }
        if (bal!=0){
            printf ("*** Transaction %03d is out of balance ***\n",prev);
            for (int i=0;i<rec.size();i++){
                printf ("%03d %-30s%11.2f\n",rec[i].first,names[rec[i].first],rec[i].second/100);
            }
            printf ("%03d %-30s%11.2f\n\n",999,"Out of Balance",-bal/100);
        }
        rec.clear();
        bal=0;
        rec.clear();
        prev=num;
        bal+=temp;
        rec.push_back(pair<int,double>(cor,temp));
        if (num==0)break;
    }
}