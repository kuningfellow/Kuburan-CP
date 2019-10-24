//UVA 362 18,000 Seconds Remaining
#include <bits/stdc++.h>
using namespace std;
int main(){
    int kas=1;
    while (1<2){
        int n;
        cin>>n;
        if (n==0)break;
        int i=0;
        int rate=0;
        printf ("Output for data set %d, %d bytes:\n",kas++,n);
        while (n>0){
            int a;
            cin>>a;
            rate+=a;
            n-=a;
            i++;
            if (i%5==0){
                printf ("   Time remaining: ");
                if (rate==0){
                    printf ("stalled\n");
                }
                else{
                    int t=n*5/rate+((n*5)%rate!=0);
                    printf ("%d seconds\n",t);
                }
                rate=0;
            }
        }
        printf ("Total time: %d seconds\n\n",i);
    }
}