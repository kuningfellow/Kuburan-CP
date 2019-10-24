#include <bits/stdc++.h>
using namespace std;
void adde(stack<int> &a, int b){
    int ta=a.top();
    a.pop();
    a.push(ta+b);
}
int main(){
    char rem[500];
    scanf("%s",rem);
    int l=strlen(rem);
    stack<int>sta;
    sta.push(0);
    stack<int>nums;
    nums.push(1);
    int sum=0;
    int tem=0;
    int flag=0;
    for (int i=l-1;i>=0;i--){
        if (rem[i]>='0'&&rem[i]<='9'){
            nums.push(rem[i]-'0');
            flag=1;
        }
        else if (rem[i]==')'){
            sta.push(0);
            if (sta.size()>nums.size()){
                nums.push(1);
            }
            flag=0;
        }
        else if (rem[i]=='('){
            int ta=sta.top();
            sta.pop();
            int tb=sta.top();
            sta.pop();
            ta*=nums.top();
            nums.pop();
            sta.push(ta+tb);
        }
        else{
            int te;
            if (rem[i]=='C')te=12;
            else if (rem[i]=='H')te=1;
            else if (rem[i]=='O')te=16;
            int ta=sta.top();
            sta.pop();
            if (flag==1){
                te*=nums.top();
                nums.pop();
            }
            sta.push(ta+te);
            flag=0;
        }
    }
    printf ("%d\n",sta.top());
}
