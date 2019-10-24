//UVA 10098 Generating Fast
#include <bits/stdc++.h>
using namespace std;
char coun[62];
char str[11];
int l;
void serc(int x){
    if (x==l){
        for (int i=0;i<l;i++){
            printf ("%c",str[i]);
        }
        printf ("\n");
    }
    for (int i=0;i<62;i++){
        if (coun[i]==0)continue;
        if (i<10)str[x]=i+'0';
        else if (i<36)str[x]=i-10+'A';
        else str[x]=i-36+'a';
        coun[i]--;
        serc(x+1);
        coun[i]++;
    }
}
int main(){
    int tc;
    cin>>tc;
    while (tc--){
        scanf("%s",str);
        for (int i=0;i<62;i++)
            coun[i]=0;
        l=strlen(str);
        for (int i=0;i<l;i++){
            if (str[i]>='a'&&str[i]<='z')
                coun[str[i]-'a'+36]++;
            else if (str[i]>='A'&&str[i]<='Z')
                coun[str[i]-'A'+10]++;
            else coun[str[i]-'0']++;
        }
        serc(0);
        printf ("\n");
    }
}