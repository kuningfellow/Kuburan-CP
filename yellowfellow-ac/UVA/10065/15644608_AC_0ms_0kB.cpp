//UVA 10065 Useless Tile Packers
#include<bits/stdc++.h>
using namespace std;
struct point{
	int x, y;
	void read(){
		scanf("%d%d",&x,&y);
	}
	point(){
		x=0;
		y=0;
	}
	point (int a, int b){
		x=a;
		y=b;
	}
	bool operator<(const point& a){
		if (x!=a.x)return x<a.x;
		return y>a.y;
	}
};
struct vektor{
	double x,y;
	vektor(point a, point b){
		x=b.x-a.x;
		y=b.y-a.y;
	}
	double L(){
		return sqrt(x*x+y*y);
	}
	double operator*(const vektor& a){
		return x*a.y-y*a.x;
	}
	double perp(const vektor& a){
		return (*this*a)/this->L();
	}
	double operator|(const vektor& a){
		return x*a.x+y*a.y;
	}
	double proj(const vektor& a){
		return (*this|a)/this->L();
	}
};
point parr[101];
vector<point>hull;
int main(){
	int kas=1;
	while(1<2){
		int n;
		cin>>n;
		if (n==0)break;
		double area=0,area2=0;
		for (int i=0;i<n;i++){
			parr[i].read();
		}
		hull.clear();
		for (int i=0;i<n;i++){
			area+=(parr[i].x*parr[(i+1)%n].y)-(parr[i].y*parr[(i+1)%n].x);
		}
		area=fabs(area)/2;
		sort(parr,parr+n);
		for (int i=0;i<n;i++){
			while (hull.size()>1){
				vektor v(hull[hull.size()-2],hull[hull.size()-1]);
				vektor u(hull[hull.size()-1],parr[i]);
				if (v*u>=0){
					hull.pop_back();
				}
				else{
					break;
				}
			}
			hull.push_back(parr[i]);
		}
		int sz=hull.size();
		for (int i=n-1;i>=0;i--){
			while (hull.size()-sz>1){
				vektor v(hull[hull.size()-2],hull[hull.size()-1]);
				vektor u(hull[hull.size()-1],parr[i]);
				if (v*u>=0){
					hull.pop_back();
				}
				else{
					break;
				}
			}
			hull.push_back(parr[i]);
		}
		sz=hull.size();
		for (int i=0;i<sz;i++){
			area2+=(hull[i].x*hull[(i+1)%sz].y)-(hull[i].y*hull[(i+1)%sz].x); 
		}
		area2=fabs(area2)/2;
		printf ("Tile #%d\nWasted Space = %0.2f %\n\n",kas++,(area2-area)/area2*100);
	}
}