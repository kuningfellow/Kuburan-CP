#include <bits/stdc++.h>
using namespace std;
int main(){
	char rem[85];
	scanf("%s",rem);
	map<string,int>cor;
	string ram;
	for (int i=0;i<10;i++){
		cin>>ram;
		cor[ram]=i;
	}
	ram="";
	for (int i=0;i<80;i++){
		ram+=rem[i];
		if ((i+1)%10==0){
			cout<<cor[ram];
			ram="";
		}
	}
	printf ("\n");
}