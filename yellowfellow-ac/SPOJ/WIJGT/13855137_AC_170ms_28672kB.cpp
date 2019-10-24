#include <bits/stdc++.h>
using namespace std;
struct line{
	int x2;
	int x1;
	int y2;
	int y1;
};
double abso(double a){
	if (a<0)return -a;
	return a;
}
double dist(line a, line b){
	double ret=(1<<28);
	int u1,u2,v1,v2;
	double cross,dot,mag;
	u1=a.x2-b.x1;
	u2=a.y2-b.y1;
	v1=b.x2-b.x1;
	v2=b.y2-b.y1;
	cross=(double)u1*v2-(double)u2*v1;
	dot=(double)u1*v1+(double)u2*v2;
	mag=sqrt((double)v1*v1+(double)v2*v2);
	if (mag!=0&&dot>=0&&dot<=mag*mag){
		ret=min(ret,abso(cross/mag));
	}
	u1=a.x1-b.x2;
	u2=a.y1-b.y2;
	v1=b.x1-b.x2;
	v2=b.y1-b.y2;
	cross=(double)u1*v2-(double)u2*v1;
	dot=(double)u1*v1+(double)u2*v2;
	mag=sqrt((double)v1*v1+(double)v2*v2);
	if (mag!=0&&dot>=0&&dot<=mag*mag){
		ret=min(ret,abso(cross/mag));
	}
	u1=b.x2-a.x1;
	u2=b.y2-a.y1;
	v1=a.x2-a.x1;
	v2=a.y2-a.y1;
	cross=(double)u1*v2-(double)u2*v1;
	dot=(double)u1*v1+(double)u2*v2;
	mag=sqrt((double)v1*v1+(double)v2*v2);
	if (mag!=0&&dot>=0&&dot<=mag*mag){
		ret=min(ret,abso(cross/mag));
	}
	u1=b.x1-a.x2;
	u2=b.y1-a.y2;
	v1=a.x1-a.x2;
	v2=a.y1-a.y2;
	cross=(double)u1*v2-(double)u2*v1;
	dot=(double)u1*v1+(double)u2*v2;
	mag=sqrt((double)v1*v1+(double)v2*v2);
	if (mag!=0&&dot>=0&&dot<=mag*mag){
		ret=min(ret,abso(cross/mag));
	}
	u1=b.x2-a.x2;
	u2=b.y2-a.y2;
	ret=min(ret,sqrt(u1*u1+u2*u2));
	u1=b.x1-a.x2;
	u2=b.y1-a.y2;
	ret=min(ret,sqrt(u1*u1+u2*u2));
	u1=b.x2-a.x1;
	u2=b.y2-a.y1;
	ret=min(ret,sqrt(u1*u1+u2*u2));
	u1=b.x1-a.x1;
	u2=b.y1-a.y1;
	ret=min(ret,sqrt(u1*u1+u2*u2));
	
	int check1=0,check2=0;
	u1=b.x2-a.x1;
	u2=b.y2-a.y1;
	v1=b.x1-a.x1;
	v2=b.y1-a.y1;
	int w1=a.x2-a.x1;
	int w2=a.y2-a.y1;
	cross=(double)u1*w2-(double)u2*w1;
	double cross2=(double)v1*w2-(double)v2*w1;
	if ((cross<0&&cross2>0)||(cross>0&&cross2<0)){
		check1=1;
	}
	u1=a.x2-b.x1;
	u2=a.y2-b.y1;
	v1=a.x1-b.x1;
	v2=a.y1-b.y1;
	w1=b.x2-b.x1;
	w2=b.y2-b.y1;
	cross=(double)u1*w2-(double)u2*w1;
	cross2=(double)v1*w2-(double)v2*w1;
	if ((cross<0&&cross2>0)||(cross>0&&cross2<0)){
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
			if (c<0){
				inpt.x2=a;
				inpt.y2=b-c;
			}
			else{
				inpt.x2=a+c;
				inpt.y2=b;
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