#include<bits/stdc++.h>
using namespace std;

int arr[15];

int main(){
	string s;
	cin>>s;
	int total0 = 0;
	long long tot = 1;
	long long dec = 10;
	long long mu = 0;
	for(int i = 0;i < s.size();i++) {
		if(i == 0) {
			if(s[i] >= '0' && s[i] <= '9') continue;
			else {
				if(s[i] == '?') tot = tot * 9;
				else {
					tot = tot * 9;
					dec--;
					arr[s[i] - 'A'] = 1;
				}
			}
		}
		else {
			if(s[i] >= '0' && s[i] <= '9') continue;
			else {
				if(s[i] == '?') total0++;
				else {
					if(arr[s[i] - 'A']== 1) continue;
					tot = tot * dec;
					dec--;
					arr[s[i] - 'A'] = 1;
				}
			}
		}
	}
	cout<<tot;
	for(int i = 0;i < total0;i++) cout<<0;
	cout<<endl;
}