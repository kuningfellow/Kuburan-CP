#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,string>mark;
    char em[5000];
    string rem,ram;
    while (1<2){
        em[0]='\0';
        scanf("%[^\n]",em);
        getchar();
        int flag=0;
        int l=strlen(em);
        if (l==0)break;
        rem="";
        ram="";
        for (int i=0;i<l;i++){
            if (em[i]==' '){
                flag=1;
            }
            else if (flag==0){
                rem+=em[i];
            }
            else if (flag==1){
                ram+=em[i];
            }
        }
        mark[ram]=rem;
    }
    while (1<2){
        em[0]='\0';
        scanf("%[^\n]",em);
        getchar();
        int l=strlen(em);
        if (l==0)break;
        rem="";
        for (int i=0;i<l;i++){
            rem+=em[i];
        }
        if (mark[rem]=="")printf ("eh\n");
        else cout<<mark[rem]<<endl;
    }
}
