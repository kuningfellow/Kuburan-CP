#include <bits/stdc++.h>
using namespace std;
int main(){
    char rem[500];
    while (scanf("%[^\n]",rem)!=EOF){
        getchar();
        int ar[35];
        int siz=0,temp=0;
        for (int i=0;i<strlen(rem);i++){
            if (rem[i]>='0'&&rem[i]<='9'){
                temp*=10;
                temp+=rem[i]-'0';
            }
            else{
                ar[siz++]=temp;
                temp=0;
            }
        }
        if (temp>0){
            ar[siz++]=temp;
        }
        int x=siz-1;
        int y;
        int k;
        for (int i=0;i<siz;i++){
            printf ("%d",ar[i]);
            if (i<siz-1)printf (" ");
        }
        printf ("\n");
        while (1<2){
            int br=1;
            for (int i=1;i<siz;i++){
                if (ar[i]<ar[i-1]){
                    br=0;
                    break;
                }
            }
            if (br==1)break;
            int pick=ar[x];
            y=x;
            for (int i=x;i>=0;i--){
                if (ar[i]>pick){
                    pick=ar[i];
                    y=i;
                }
            }
            if (y!=0){
                printf ("%d ",siz-y);
                k=0;
                while (k<y){
                    int swa=ar[y];
                    ar[y]=ar[k];
                    ar[k]=swa;
                    k++;
                    y--;
                }
            }
            y=x;
            k=0;
            printf ("%d ",siz-y);
            while (k<y){
                int swa=ar[y];
                ar[y]=ar[k];
                ar[k]=swa;
                k++;
                y--;
            }
            x--;
        }
        printf ("0\n");
    }
}
