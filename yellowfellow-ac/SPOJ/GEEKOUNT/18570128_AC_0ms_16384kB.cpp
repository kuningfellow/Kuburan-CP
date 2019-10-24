#include<stdio.h>
#define TC int TC=-1;while((TC!=-1||scanf("%d",&TC))&&TC--)

int eval[15];

int serc(int x, int mul, int stat) {
	if (x == -1) return 1;
	int ret = 0;
	for (int i = 1; i < 10; i += 2) {
		if (!stat || i < eval[x]) ret += mul;
		else if (i == eval[x]) ret += serc(x - 1, mul / 5, stat);
	}
	return ret;
}

int getcost(int x) {
	int ret = 0, ptr = 0, mul = 0;
	while (x > 0) {
		eval[ptr++] = x % 10;
		x /= 10;
	}
	for (int i = 0, mul = 1; i < ptr; i++, mul *= 5) {
		ret += serc(i, mul, i+1 == ptr);
	}
	return ret;
}

int main() {
	TC {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", r - l+1 + getcost(l-1) - getcost(r));
	}
	return 0;
}