#include<stdio.h>
#include<math.h>

#define S(x) ((x)*(x))

const double PI = acos(-1);

int main() {
	double l, w, r;
	while (scanf("%lf %lf %lf", &l, &w, &r) != EOF) {
		double area = PI*r*r*3/4;
		if (r > w + l) {
			double diag = sqrt(S(w) + S(l));
			double A = PI / 2 - (acos((S(r-w) + S(diag) - S(r-l)) / (2 * (r-w) * diag)) - atan(w / l));
			double B = PI / 2 - (acos((S(r-l) + S(diag) - S(r-w)) / (2 * diag * (r-l))) - atan(l / w));
			area += S(r-w)*A/2 + S(r-l)*B/2;
			double h = (diag + 2*r - l - w) / 2;
			area += sqrt(h * (h - diag) * (h - (r-l)) * (h - (r-w)));
			area -= l * w / 2;
		}
		else {
			if (r > w) area += PI*(r-w)*(r-w)/4;
			if (r > l) area += PI*(r-l)*(r-l)/4;
		}
		printf("%.10f\n", area);
	}
	return 0;
}