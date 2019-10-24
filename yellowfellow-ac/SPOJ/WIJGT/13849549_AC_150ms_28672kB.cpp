#include <bits/stdc++.h>
using namespace std;
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct point{
	int x;
	int y;
};
double abso(double a){
	if (a<0)return -a;
	return a;
}
double cross(point a, point b, point c){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=c.x-a.x;
	int v2=c.y-a.y;
	return (double)u1*v2-(double)u2*v1;
}
double dot(point a, point b, point c){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=c.x-a.x;
	int v2=c.y-a.y;
	return (double)u1*v1+(double)u2*v2;
}
double mag(point a, point b){
	int u1=a.x-b.x;
	int u2=a.y-b.y;
	return sqrt((double)u1*u1+u2*u2);
}
double dist(line a, line b){
	double ret=(1<<28);
	point a1,a2,b1,b2;
	a1.x=a.x1;
	a1.y=a.y1;
	a2.x=a.x2;
	a2.y=a.y2;
	b1.x=b.x1;
	b1.y=b.y1;
	b2.x=b.x2;
	b2.y=b.y2;
	double cros;
	double dote;
	double mage;
	cros=cross(a1,a2,b1);
	dote=dot(a1,a2,b1);
	mage=mag(a1,a2);
	if (!(mage>-1e-9&&mage<1e-9)){
		if (dote>0&&dote/mage<mage){
			ret=min(ret,abso(cros/mage));
		}
	}
	cros=cross(a1,a2,b2);
	dote=dot(a1,a2,b2);
	mage=mag(a1,a2);
	if (!(mage>-1e-9&&mage<1e-9)){
		if (dote>0&&dote/mage<mage){
			ret=min(ret,abso(cros/mage));
		}
	}
	cros=cross(b1,b2,a1);
	dote=dot(b1,b2,a1);
	mage=mag(b1,b2);
	if (!(mage>-1e-9&&mage<1e-9)){
		if (dote>0&&dote/mage<mage){
			ret=min(ret,abso(cros/mage));
		}
	}
	cros=cross(b1,b2,a2);
	dote=dot(b1,b2,a2);
	mage=mag(b1,b2);
	if (!(mage>-1e-9&&mage<1e-9)){
		if (dote>0&&dote/mage<mage){
			ret=min(ret,abso(cros/mage));
		}
	}
	ret=min(ret,mag(a1,b1));
	ret=min(ret,mag(a1,b2));
	ret=min(ret,mag(a2,b1));
	ret=min(ret,mag(a2,b2));
	int check1=0;
	int check2=0;
	double c1=cross(a1,a2,b1),c2=cross(a1,a2,b2);
	if ((c1<0&&c2>0)||(c1>0&&c2<0)){
		check1=1;
	}
	c1=cross(b1,b2,a1);
	c2=cross(b1,b2,a2);
	if ((c1<0&&c2>0)||(c1>0&&c2<0)){
		check2=1;
	}
	if (check1&&check2){
		ret=0;
	}
	return ret;
}
double cost[1005][1005];
int vis[1005];
double tot[1005];
int main(){
	while (1<2){
		int n;
		cin>>n;
		if (n==0)break;
		for (int i=0;i<n;i++){
			vis[i]=0;
			tot[i]=(1<<28);
			for (int j=0;j<n;j++){
				cost[i][j]=(1<<28);
			}
		}
		int a,b,c;
		vector<line>lines;
		line inpt;
		for (int i=0;i<n;i++){
			cin>>a>>b>>c;
			inpt.x1=a;
			inpt.y1=b;
			if (c>=0){
				inpt.x2=a+c;
				inpt.y2=b;
			}
			else{
				inpt.x2=a;
				inpt.y2=b-c;
			}
			lines.push_back(inpt);
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cost[i][j]=dist(lines[i],lines[j])+1e-9;
			}
		}
		priority_queue<pair<double,int> >pq;
		pq.push(pair<double,int>(0,0));
		int v;
		double temp;
		while (!pq.empty()){
			v=pq.top().second;
			temp=-pq.top().first;
			pq.pop();
			if (vis[v]==1){
				continue;
			}
			vis[v]=1;
			tot[v]=temp;
			for (int i=0;i<n;i++){
				if (vis[i]==0){
					pq.push(pair<double,int>(-max(temp,cost[v][i]),i));
				}
			}
		}
		printf ("%.2f\n",tot[1]);
	}
}