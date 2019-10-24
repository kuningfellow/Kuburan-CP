#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int>l;
    priority_queue<int>r;
    int n,a;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        if (i==0){
            l.push(a);
            printf ("%d.0\n",l.top());
        }
        else if (i%2==1){
            if (a<=l.top()){
                r.push(-l.top());
                l.pop();
                l.push(a);
            }
            else{
                r.push(-a);
            }
            printf ("%.1f\n",((double)l.top()-r.top())/2);
        }
        else if (i%2==0){
            if (a>-r.top()){
                l.push(-r.top());
                r.pop();
                r.push(-a);
            }
            else{
                l.push(a);
            }
            printf ("%d.0\n",l.top());
        }
    }
}
