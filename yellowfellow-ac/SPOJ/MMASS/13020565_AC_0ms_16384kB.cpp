#include <bits/stdc++.h>
#define Ooo 0
#define OOo 1
#define oOo '0'
#define o0o '1'
#define oO0 '9'
#define o00 ')'
#define o0O '('
#define ooOo 12
#define oooO 16
#define oOoo 'C'
#define oOOo 'H'
#define oOOO 'O'
using namespace std;typedef char oooo;typedef int ooo0;int main(){oooo ooo[500];scanf("%s",ooo);stack<ooo0>oO;oO.push(0);stack<ooo0>o0;o0.push(1);ooo0 O=0,Oo,OO;for(ooo0 o=strlen(ooo)-OOo;o>=Ooo;o--){if (ooo[o]>=oOo&&ooo[o]<=oO0){o0.push(ooo[o]-oOo);O=OOo;}else if (ooo[o]==o00){oO.push(Ooo);if (oO.size()>o0.size())o0.push(OOo);O=Ooo;}else if (ooo[o]==o0O){OO=oO.top();oO.pop();Oo=oO.top();oO.pop();OO*=o0.top();o0.pop();oO.push(OO+Oo);}else{if (ooo[o]==oOoo)Oo=ooOo;else if (ooo[o]==oOOo)Oo=OOo;else if (ooo[o]==oOOO)Oo=oooO;OO=oO.top();oO.pop();if (O==OOo){Oo*=o0.top();o0.pop();}oO.push(OO+Oo);O=Ooo;}}printf ("%d\n",oO.top());}
