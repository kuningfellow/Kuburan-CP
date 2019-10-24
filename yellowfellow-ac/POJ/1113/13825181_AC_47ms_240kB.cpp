#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct point{
	int x;
	int y;
	bool operator<(point a){
		if (x!=a.x)return x<a.x;
		return y>a.y;
	}
};
int cross(point a, point b, point c){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=c.x-a.x;
	int v2=c.y-a.y;
	int cross=u1*v2-u2*v1;
	if (cross<=0)return 0;
	return 1;
}
double dist(point a, point b){
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
}
point ar[1005];
int main(){
	int n,r;
	cin>>n>>r;
	for (int i=0;i<n;i++){
		cin>>ar[i].x>>ar[i].y;
	}
	sort(ar,ar+n);
	vector<int>take;
	for (int i=0;i<n;i++){
		while (take.size()>1&&cross(ar[take[take.size()-2]],ar[take[take.size()-1]],ar[i])){
			take.pop_back();
		}
		take.push_back(i);
	}
	int b=take.size();
	for (int i=n-1;i>=0;i--){
		while (take.size()-b>1&&cross(ar[take[take.size()-2]],ar[take[take.size()-1]],ar[i])){
			take.pop_back();
		}
		take.push_back(i);
	}
	double tot=acos((double)-1)*2*r;
	for (int i=0;i<take.size();i++){
		tot+=dist(ar[take[i]],ar[take[(i+1)%take.size()]]);
	}
	printf ("%.0f\n",tot);
}