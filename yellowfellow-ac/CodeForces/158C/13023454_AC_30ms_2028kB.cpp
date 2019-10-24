#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string rem;
	char ram[5000];
	stack<string>pat;
	while (n--){
		scanf("%s",ram);
		if (!strcmp(ram,"pwd")){
			int siz=pat.size();
			printf ("/");
			stack<string>tmp;
			while (siz--){
				tmp.push(pat.top());
				pat.pop();
			}
			while (!tmp.empty()){
				cout<<tmp.top()<<'/';
				pat.push(tmp.top());
				tmp.pop();
			}
			printf ("\n");
		}
		else{
			scanf("%s",ram);
			int i=0;
			if (ram[0]=='/'){
				while (!pat.empty()){
					pat.pop();
				}
				i=1;
			}
			int l=strlen(ram);
			rem="";
			for (;i<l;i++){
				if (ram[i]!='/'){
					rem+=ram[i];
				}
				else{
					if (rem==".."){
						pat.pop();
					}
					else{
						pat.push(rem);
					}
					rem="";
				}
			}
			if (rem!=""){
				if (rem==".."){
					pat.pop();
				}
				else{
					pat.push(rem);
				}
			}
		}
	}
}