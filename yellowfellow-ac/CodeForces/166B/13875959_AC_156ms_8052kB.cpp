#include <bits/stdc++.h>
using namespace std;
struct point{
	long long int x;
	long long int y;
	int code;
	bool operator<(point a){
		if (x!=a.x)return x<a.x;
		return y>a.y;
	}
};
int cros(point a, point b, point c){
	long long int u1=b.x-a.x;
	long long int u2=b.y-a.y;
	long long int v1=c.x-a.x;
	long long int v2=c.y-a.y;
	long long int cros=u1*v2-u2*v1;
	if (cros>0)return 1;
	return 0;
}
int main(){
	int n;
scanf("%d",&n);
	point inpt;
	vector<point>ps;
	inpt.code=0;
	for (int i=0;i<n;i++){
scanf("%lld%lld",&inpt.x,&inpt.y);
		ps.push_back(inpt);
	}
	cin>>n;
	inpt.code=1;
	for (int i=0;i<n;i++){
scanf("%lld%lld",&inpt.x,&inpt.y);
		ps.push_back(inpt);
	}
	sort(ps.begin(),ps.end());
	vector<int>takes;
	for (int i=0;i<ps.size();i++){
		while (takes.size()>1&&cros(ps[takes[takes.size()-2]],ps[takes[takes.size()-1]],ps[i])){
			takes.pop_back();
		}
		takes.push_back(i);
	}
	int ns=takes.size();
	for (int i=ps.size()-1;i>=0;i--){
		while (takes.size()-ns>1&&cros(ps[takes[takes.size()-2]],ps[takes[takes.size()-1]],ps[i])){
			takes.pop_back();
		}
		takes.push_back(i);
	}
	int yes=1;
	for (int i=0;i<takes.size();i++){
		if (ps[takes[i]].code==1){
			yes=0;
			break;
		}
	}
	if (yes==1)printf ("YES\n");
	else printf ("NO\n");
}