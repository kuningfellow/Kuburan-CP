//UVA 11678 Card's Exchange
#include <bits/stdc++.h>
using namespace std;
int ar[100001],br[100001];
int main(){
  int c;
  while (1<2){
    c++;
    int a,b,ca=0,cb=0,x;
    scanf("%d%d",&a,&b);
    if (a==0&&b==0)break;
    for (int i=0;i<a;i++){
      scanf("%d",&x);
      if (ar[x]!=c&&br[x]!=c)ca++;
      else if (ar[x]!=c&&br[x]==c)cb--;
      ar[x]=c;
    }
    for (int i=0;i<b;i++){
      scanf("%d",&x);
      if (ar[x]!=c&&br[x]!=c)cb++;
      else if (br[x]!=c&&ar[x]==c)ca--;
      br[x]=c;
    }
    printf ("%d\n",min(ca,cb));
  }
}