//UVA 10554 Calories from Fat
#include <bits/stdc++.h>
using namespace std;
int main(){
    int done=0;
    while (1<2){
        char rem[5000];
        double coun[5]={};
        while (1<2){
            double temp[5]={};
            for (int i=0;i<5;i++){
                scanf("%s",rem);
                if (!strcmp(rem,"-")){
                    if (done==1)done=2;
                    else done=1;
                    break;
                }
                else{
                    done=0;
                }
                if (rem[strlen(rem)-1]=='g'){
                    temp[i]=0;
                    for (int j=0;j<strlen(rem)-1;j++){
                        temp[i]=temp[i]*10+rem[j]-'0';
                    }
                    if (i==0)temp[i]*=9;
                    else if (i==4)temp[i]*=7;
                    else temp[i]*=4;
                }
                else if (rem[strlen(rem)-1]=='C'){
                    temp[i]=0;
                    for (int j=0;j<strlen(rem)-1;j++){
                        temp[i]=temp[i]*10+rem[j]-'0';
                    }
                }
                else{
                    temp[i]=0;
                    for (int j=0;j<strlen(rem)-1;j++){
                        temp[i]=temp[i]*10+rem[j]-'0';
                    }
                    temp[i]=-temp[i];
                }
            }
            if (done!=0)break;
            double psum=0;
            double sum=0;
            for (int i=0;i<5;i++){
                if (temp[i]>0){
                    sum+=temp[i];
                }
                else{
                    psum-=temp[i];
                }
            }
            sum=sum*100/(100-psum);
            for (int i=0;i<5;i++){
                if (temp[i]<0){
                    temp[i]=-temp[i];
                    temp[i]=sum*temp[i]/100;
                }
            }
            for (int i=0;i<5;i++){
                coun[i]+=temp[i];
            }
        }
        if (done==2)break;
        double sum=0;
        for (int i=0;i<5;i++){
            sum+=coun[i];
        }
        printf ("%.0f%\n",coun[0]/sum*100);
    }
}