#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
};
int main(){
	int n;
	cin>>n;
	int d,vol;
	cin>>d>>vol;
	double area=(double)vol*1000/d;
	point ar[n];
	int mark[n];
	vector<point>left;
	vector<point>right;
	double maxi=0;
	int pick=-1;
	for (int i=0;i<n;i++){
		mark[i]=0;
		cin>>ar[i].x>>ar[i].y;
		maxi=max(ar[i].y,maxi);
		if (ar[i].y==0){
			if (pick==-1){
				pick=i;
			}
			else if (ar[pick].x<ar[i].x){
				pick=i;
			}
		}
	}
	int flag=0;
	for (int i=0;i<n;i++){
		if (flag==0){
			right.push_back(ar[(i+pick)%n]);
		}
		else{
			left.push_back(ar[(i+pick)%n]);
		}
		if (ar[(i+pick)%n].y==maxi)flag=1;
	}
	double l=0;
	double r=maxi;
	double mid;
	double ans;
	vector<point>calc;
	for (int i=0;i<1000;i++){
		mid=(l+r)/2;
		int rs;
		int ls;
		for (int j=0;j<right.size();j++){
			if (right[j].y<=mid)rs=j;
		}
		for (int j=left.size()-1;j>=0;j--){
			if (left[j].y<=mid)ls=j;
		}
		calc.clear();
		for (int j=0;j<=rs;j++){
			calc.push_back(right[j]);
		}
		if (right[rs].y<mid){
			double u1=0;
			double u2=1;
			point p1=right[rs];
			point p2=right[rs+1];
			double v1=p2.x-p1.x;
			double v2=p2.y-p1.y;
			double deg=(v1*u2-v2*u1)/sqrt(v1*v1+v2*v2);
			double delta=mid-right[rs].y;
			point add;
			add.y=mid;
			add.x=right[rs].x+delta*tan(asin(deg));
			calc.push_back(add);
		}
		if (left[ls].y<mid){
			double u1=0;
			double u2=1;
			point p1=left[ls];
			point p2=left[ls-1];
			double v1=p2.x-p1.x;
			double v2=p2.y-p1.y;
			double deg=(v1*u2-v2*u1)/sqrt(v1*v1+v2*v2);
			double delta=mid-left[ls].y;
			point add;
			add.y=mid;
			add.x=left[ls].x+delta*tan(asin(deg));
			calc.push_back(add);
		}
		for (int j=ls;j<left.size();j++){
			calc.push_back(left[j]);
		}
		double suma=0;
		double sumb=0;
		int s=calc.size();
		for (int j=0;j<s;j++){
			suma+=calc[j].x*calc[(j+1)%s].y;
			sumb+=calc[j].y*calc[(j+1)%s].x;
		}
		suma-=sumb;
		suma=max(suma,-suma)/2;
		if (suma>=area){
			ans=mid;
			r=mid;
		}
		else{
			l=mid;
		}
	}
	printf ("%.2f\n",ans);
}