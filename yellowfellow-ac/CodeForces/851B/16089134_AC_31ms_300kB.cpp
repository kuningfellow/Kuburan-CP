#include<bits/stdc++.h>
using namespace std;
int main(){
	double ax, ay, bx, by, cx, cy;
	scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
	
	double v1 = bx-ax;
	double v2 = by-ay;
	double u1 = cx-bx;
	double u2 = cy-by;
	double dist = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
	double dist2 = sqrt((bx-cx)*(bx-cx) + (by-cy)*(by-cy));
	
	double cross = v1*u2 - v2*u1;
	
	if ( cross != 0 && dist == dist2 ){
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}