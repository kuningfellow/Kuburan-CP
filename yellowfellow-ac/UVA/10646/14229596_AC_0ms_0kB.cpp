//UVA 10646 What is the Card?
#include <bits/stdc++.h>
using namespace std;
int main(){
  int tc,kas=1;
  cin>>tc;
  while (tc--){
    string ar[52];
    for (int i=0;i<52;i++){
      cin>>ar[i];
    }
    int y=0;
    int ptr=51-25;
    for (int i=0;i<3;i++){
      int x=10;
      if (ar[ptr][0]>='2'&&ar[ptr][0]<='9')x=ar[ptr][0]-'0';
      ptr--;
      y+=x;
      ptr-=(10-x);
    }
    printf ("Case %d: ",kas++);
    y--;
    if (y<=ptr)cout<<ar[y]<<endl;
    else cout<<ar[51-25+y-ptr]<<endl;
  }
}