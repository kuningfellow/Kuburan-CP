#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,match[3];
    while (scanf("%d",&n)!=EOF){
        match[0]=match[1]=match[2]=1;
        stack<int>s;
        queue<int>q;
        priority_queue<int>pq;
        while (n--){
            scanf("%d%d",&a,&b);
            if (a==1){
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            if (a==2){
                if (!s.empty()){
                    a=s.top();
                    s.pop();
                    if (a!=b){
                        match[0]=0;
                    }
                    a=q.front();
                    q.pop();
                    if (a!=b){
                        match[1]=0;
                    }
                    a=pq.top();
                    pq.pop();
                    if (a!=b){
                        match[2]=0;
                    }
                }
                else{
                    match[0]=match[1]=match[2]=0;
                }
            }
        }
        int cor=-1;
        int sum=0;
        for (int i=0;i<3;i++){
            sum+=match[i];
            if (match[i]==1)cor=i;
        }
        if (sum==1){
            if (cor==0)printf ("stack\n");
            else if (cor==1)printf ("queue\n");
            else printf ("priority queue\n");
        }
        else if (sum==0){
            printf ("impossible\n");
        }
        else printf ("not sure\n");
    }
}
