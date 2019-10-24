//UVA 10205 Stack 'em Up
#include <bits/stdc++.h>
using namespace std;
int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int n;
    cin>>n;
    int ar[n][52];
    for (int i=0;i<n;i++){
      for (int j=0;j<52;j++){
        int a;
        cin>>a;
        ar[i][j]=a-1;
      }
    }
    int br[52];
    for (int i=0;i<52;i++)br[i]=i;
    int cr[52];
    getchar();
    char rem[50];
    int fir=1;
    while (fir||strlen(rem)!=0){
      rem[0]='\0';
      scanf("%[^\n]",rem);
      getchar();
      if (strlen(rem)!=0){
        fir=0;
        int num=0;
        for (int i=0;i<strlen(rem);i++){
          num=num*10+rem[i]-'0';
        }
        num--;
        for (int i=0;i<52;i++){
          cr[i]=br[ar[num][i]];
        }
        for (int i=0;i<52;i++){
          br[i]=cr[i];
        }
      }
    }
    for (int i=0;i<52;i++){
      int val=br[i]%13;
      int typ=br[i]/13;
      if (val<9)printf("%d",val+2);
      else if (val==9)printf ("Jack");
      else if (val==10)printf ("Queen");
      else if (val==11)printf ("King");
      else if (val==12)printf ("Ace");
      printf (" of ");
      if (typ==0)printf ("Clubs\n");
      else if (typ==1)printf ("Diamonds\n");
      else if (typ==2)printf ("Hearts\n");
      else if (typ==3)printf ("Spades\n");
    }
    if (tc!=0)printf("\n");  
  }
}