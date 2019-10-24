//versi local pake epsilon
#include <bits/stdc++.h>
using namespace std;
struct point{
	double x;
	double y;
	bool operator<(point a){
		if (x-1e-9<a.x&&x+1e-9>a.x)return y>a.y;
		return x<a.x;
	}
};
struct line{
	double grad;
	double shiftx;
	double shifty;
	double len;
};
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==-1)break;
		vector<point>pt;
		point dum;
		line dummy;
		vector<line>lines;
		int ar[1005][3];
		for (int i=0;i<n;i++){
			cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
			dum.x=(double)ar[i][0];
			dum.y=0;
			pt.push_back(dum);
			dum.x=(double)ar[i][1];
			pt.push_back(dum);
			dum.x=((double)ar[i][0]+ar[i][1])/2;
			dum.y=(double)ar[i][2];
			pt.push_back(dum);
			dummy.len=((double)ar[i][1]-ar[i][0])/2;
			dummy.grad=(double)ar[i][2]*2/(ar[i][1]-ar[i][0]);
			dummy.shifty=0;
			dummy.shiftx=(double)ar[i][0];
			lines.push_back(dummy);
			dummy.shifty=(double)ar[i][2];
			dummy.shiftx=((double)ar[i][0]+ar[i][1])/2;
			dummy.grad=-(double)ar[i][2]*2/(ar[i][1]-ar[i][0]);
			lines.push_back(dummy);
		}
		double x,y;
		for (int i=0;i<lines.size();i++){
			for (int j=0;j<lines.size();j++){
				if (i==j)continue;
				x=(lines[i].shiftx*lines[i].grad-lines[j].shiftx*lines[j].grad-lines[i].shifty+lines[j].shifty)/(lines[i].grad-lines[j].grad);
				if (x>lines[i].shiftx&&x<lines[i].shiftx+lines[i].len&&
					x>lines[j].shiftx&&x<lines[j].shiftx+lines[j].len){
					dum.x=x;
					dum.y=lines[i].grad*(x-lines[i].shiftx)+lines[i].shifty;
					pt.push_back(dum);	
				}
			}
		}
		sort(pt.begin(),pt.end());
		vector<pair<double,double> >pol;
		x=-5;
		for (int i=0;i<pt.size();i++){
			if (pt[i].x>x+1e-9){
				x=pt[i].x;
				y=pt[i].y;
				int val=1;
				for (int j=0;j<lines.size();j++){
					if (x>lines[j].shiftx&&x<lines[j].shiftx+lines[j].len){
						double cale=lines[j].grad*(x-lines[j].shiftx)+lines[j].shifty;
						if (y+1e-9<cale){
							val=0;
							break;
						}
					}
				}
				if (val==0)continue;
				pol.push_back(pair<double,double>(x,y));
			}
		}
		double suma=0,sumb=0;
		for (int i=0;i<pol.size();i++){
			suma+=pol[i].first*pol[(i+1)%pol.size()].second;
			sumb+=pol[i].second*pol[(i+1)%pol.size()].first;
		}
		suma-=sumb;
		printf ("%.2f\n",max(suma,-suma)/2);
	}
}