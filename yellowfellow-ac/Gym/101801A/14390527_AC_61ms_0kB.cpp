#include <bits/stdc++.h>
#define i_want_to_die true
#define live false
using namespace std;
bool leo(int depression, int happiness){
	if (depression>=happiness)return i_want_to_die;
	else return live;
}
int main(){
	int fj;
	cin>>fj;
	while(fj--){
		int quit,jollybee;
		cin>>quit>>jollybee;
		if (leo(quit,jollybee)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}