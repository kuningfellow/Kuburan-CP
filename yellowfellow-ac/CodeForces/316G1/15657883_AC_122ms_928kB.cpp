#include<bits/stdc++.h>
using namespace std;

const int N = 5000;
int P[N + 5];
string tar[15];
int l[15];
int r[15];
string s;

int li = 0, lj = -1;

int compare(int n,int shift, int id) {
	int i = 0, j = 0;
	int occ = 0;
	while(i < tar[id].size()) {
		while(j >= 0 && tar[id][i] != s[j + shift]) j = P[j];
		i++;
		j++;
		if(j == n){
			occ++;
			j = P[j];
		}
	}
	return occ;
}

int add(int x,int shift) {
	while(lj >= 0 && s[shift + lj] != s[shift + li]) lj = P[lj];
	lj++;
	li++;
	P[li] = lj;
}



set<pair<long long,pair<long long,int> > > st;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	cin>>s;
	int n;
	cin>>n;
	for(int i = 0;i < n;i++) {
		cin>>tar[i]>>l[i]>>r[i];
	}
	int total = 0;
	for(int i = 0;i < s.size();i++) {
		li = 0, lj = -1;
		long long v1 = 0, v2  =0;
		for(int j = i; j < s.size();j++) {
			if(i == j) P[li] = lj;
			add(j,i);
			bool ada = true;
			v1 = v1 * 31 + s[j] - 'a';
			v2 = v2 * 27 + s[j] - 'a';
			for(int k = 0;k < n;k++) {
				int occ = compare(j - i + 1,i, k);
				if(l[k] > occ || r[k] < occ) ada = false;
			}
			if(ada == true) {
				st.insert(make_pair(v1,make_pair(v2,j - i + 1)));
			}
		}
	}
	cout<<st.size()<<endl;
}