#include <iostream>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while (tc--){
		string rem,ram;
		cin>>rem>>ram;
		ram[0]=ram[0]-'a'+'A';
		cout<<ram<<rem<<endl;
	}
	return 0;
}