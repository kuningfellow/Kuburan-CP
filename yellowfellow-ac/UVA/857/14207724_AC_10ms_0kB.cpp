//UVA 857 Quantiser
#include <bits/stdc++.h>
using namespace std;
struct data{
    int me;
    int bit;
    int tick;
    int flag;
    int code;
};
bool delta(data a, data b){
    if (a.flag==0)return 1;
    // if (a.flag==b.flag)return 1;
    if (a.code!=b.code)return 1;
    int ret=0;
    ret=480*4*(b.me-a.me)+480*(b.bit-a.bit)+(b.tick-a.tick);
    if (ret==0)return 0;
    else return 1;
}
int main(){
    while (1<2){
        int n;
        cin>>n;
        if (n==-1)break;
        vector<data>scoreraw;
        vector<data>score;
        data dum;
        for (int i=0;i<n;i++){
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            d--;
            dum.me=c;
            dum.bit=d;
            dum.tick=e;
            dum.flag=a;
            dum.code=b;
            scoreraw.push_back(dum);
        }
        for (int i=0;i<scoreraw.size();i++){
            int tick=scoreraw[i].tick;
            int a=tick;
            int b=tick;
            int thru=0;
            while (a%60!=0&&b%60!=0){
                a--;
                b++;
                if (b==480){
                    b=0;
                    thru=1;
                }
            }
            if (b%60==0){
                scoreraw[i].tick=b;
                scoreraw[i].bit=scoreraw[i].bit+thru;
                if (scoreraw[i].bit==4){
                    scoreraw[i].bit=0;
                    scoreraw[i].me=scoreraw[i].me+1;
                }
            }
            else scoreraw[i].tick=a;
        }
        for (int i=0;i<scoreraw.size()-1;i++){
            for (int j=i+1;j<scoreraw.size();j++){
                if (delta(scoreraw[i],scoreraw[j])==0){
                    scoreraw[i].flag=-1;
                    scoreraw[j].flag=-1;
                }
            }
        }
        for (int i=0;i<scoreraw.size();i++){
            if (scoreraw[i].flag==-1)continue;
            score.push_back(scoreraw[i]);
        }
        printf ("%d\n",score.size());
        for (int i=0;i<score.size();i++){
            printf ("%d %d %d %d %d\n",score[i].flag,score[i].code,score[i].me,score[i].bit+1,score[i].tick);
        }
    }
    printf ("-1\n");
}