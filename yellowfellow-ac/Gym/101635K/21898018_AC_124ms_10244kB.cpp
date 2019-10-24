// dari nyamuk stile
#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

struct point{
	LL x,y;
	bool operator<(const point& a){
		if (x != a.x)return x < a.x;
		return y > a.y;
	}
};
struct vektor{
	double x,y;
	vektor(LL a, LL b){
		x = a;
		y = b;
	}
	double operator*(const vektor& a){
		return x * a.y - y * a.x;
	}
	double mag(){
		return sqrt(x * x + y * y);
	}
};

typedef struct point point;
typedef struct vektor vektor;

double cross(point a, point b, point c){	//vektor titik a->b cross dengan b->c
	vektor v(b.x - a.x , b.y - a.y);
	vektor u(c.x - b.x , c.y - b.y);
	return v*u;
}
double dist(point a, point b, point c){		//jarak titik c ke vektor a->b
	vektor v(b.x - a.x , b.y - a.y);
	vektor u(c.x - b.x , c.y - b.y);
	return fabs( (u*v)/v.mag() );
}

vector<point>input;
vector<point>cHull;

int main(){
	int n;
	LL r;
	scanf("%d%lld", &n, &r);
	point dum;
	for (int i=0; i<n; i++){
		scanf("%lld%lld", &dum.x, &dum.y);
		input.push_back(dum);
	}
	sort(input.begin(),input.end());
	
	for (int i=0;i<n;i++){
		while (cHull.size() > 1 && cross(cHull[cHull.size()-2], cHull[cHull.size()-1], input[i]) > 0){
			cHull.pop_back();
		}
		cHull.push_back(input[i]);
	}
  int sz = cHull.size();
	for (int i=n-2;i>=0;i--){
		while (cHull.size() > sz && cross(cHull[cHull.size()-2], cHull[cHull.size()-1], input[i]) > 0){
			cHull.pop_back();
		}
    if (i == 0) break;
		cHull.push_back(input[i]);
	}
	
	sz=cHull.size();
	double ans=r*2;
	int pos=0;
	for (int i=0;i<sz;i++){
		double tmp=-1;
		int upd = pos;
		for (int j=0;j<sz;j++){
			double distance = dist(cHull[i], cHull[ (i+1) % sz ], cHull[ upd % sz ]);
			if (distance >= tmp){
				tmp = distance;
				upd = (upd + 1) % sz;
			}
			else{
				break;
			}
		}
		pos = (upd - 1 + sz) % sz;
		ans = min(ans, tmp);
	}
	printf ("%.10f\n",ans);
}