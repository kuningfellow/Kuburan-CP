#include <bits/stdc++.h>
using namespace std;
struct point{
	int x;
	int y;
};
point pta[15];
point ptb[15];
bool aline(point a, point b, point c, point d){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=d.x-c.x;
	int v2=d.y-c.y;
	if (u1*v2==u2*v1)return 1;
	return 0;
}
bool alin(point a, point b, point c){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=c.x-a.x;
	int v2=c.y-a.y;
	if (u1*v2==u2*v1)return 1;
	return 0;
}
double dista(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int lie(point a, point b, point c){
	int u1=b.x-a.x;
	int u2=b.y-a.y;
	int v1=c.x-a.x;
	int v2=c.y-a.y;
	return (v1*u2-v2*u1);
}
bool cross(point a, point b, point c, point d){
	if (aline(a,b,c,d)){
		if (alin(a,b,c)){
			if (dista(a,c)+dista(b,c)==dista(a,b))return 1;
			else if (dista(a,d)+dista(b,d)==dista(a,b))return 1;
			else return 0;
		}
		else{
			return 0;
		}
	}
	else{
		int cros1=0;
		int cros2=0;
		int t1=lie(a,b,c);
		int t2=lie(a,b,d);
		if (t1==0||t2==0)cros1=1;
		else if (t2>0&&t1<0)cros1=1;
		else if (t2<0&&t1>0)cros1=1;
		t1=lie(c,d,a);
		t2=lie(c,d,b);
		if (t1==0||t2==0)cros2=1;
		else if (t2>0&&t1<0)cros2=1;
		else if (t2<0&&t1>0)cros2=1;
		if (cros1+cros2==2)return 1;
		return 0;
	}
}
int pick[15];
int con[15];
int n;
int okay;
void rec(int x){
	if (x==n){
		int cros=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==j)continue;
				cros=cross(pta[con[i]],ptb[i],pta[con[j]],ptb[j]);
				if (cros)break;
			}
			if (cros)break;
		}
		if (cros==0){
			okay=1;
		}
		return;
	}
	for (int i=0;i<n;i++){
		if (pick[i]==0){
			pick[i]=1;
			con[i]=x;
			rec(x+1);
			pick[i]=0;
		}
	}
}
int main(){
	int m;
	cin>>n>>m;
	if (n!=m){
		printf ("No\n");
		return 0;
	}
	else{
		okay=0;
		for (int i=0;i<n;i++){
			scanf("%d%d",&pta[i].x,&pta[i].y);
		}
		for (int i=0;i<n;i++){
			scanf("%d%d",&ptb[i].x,&ptb[i].y);
		}
		rec(0);
		if (okay==1){
			printf ("Yes\n");
		}
		else printf ("No\n");
	}
}