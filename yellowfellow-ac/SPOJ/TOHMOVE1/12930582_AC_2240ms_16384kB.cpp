#include <bits/stdc++.h>
using namespace std;
vector<int>mov[3];
void hanoi(int n,int f, int t){
    if (n==1){
        mov[0].push_back(1);
        mov[1].push_back(f);
        mov[2].push_back(t);
        return;
    }
    hanoi(n-1,f,3^t^f);
    mov[0].push_back(n);
    mov[1].push_back(f);
    mov[2].push_back(t);
    hanoi(n-1,3^f^t,t);
    return;
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        int n,k;
        cin>>n>>k;
        for (int i=0;i<3;i++){
            mov[i].clear();
        }
        hanoi(n,0,2);
        printf ("%d : %c => %c\n",mov[0][k-1],mov[1][k-1]+'A',mov[2][k-1]+'A');
    }
}
