#include<stdio.h>
#include<string.h>

int dp[105][105][105];
int bt[105][105][105];
int kmp[105];
char str1[105];
char str2[105];
char virus[105];

int serc(int x, int y, int z) {
	if (virus[z] == '\0') return -1000000;
	if (str1[x] == '\0' || str2[y] == '\0') return 0;
	if (dp[x][y][z] != -1) return dp[x][y][z];
	dp[x][y][z] = -1000000;
	if (str1[x] == str2[y]) {
		int k = z;
		while (k && virus[k] != str1[x]) {
			k = kmp[k - 1];
		}
		if (virus[k] == str1[x]) k++;
		int rec = serc(x + 1, y + 1, k) + 1;
		if (rec > dp[x][y][z]) {
			dp[x][y][z] = rec;
			bt[x][y][z] = k;
		}
	}
	int rec = serc(x + 1, y, z);
	if (rec > dp[x][y][z]) {
		dp[x][y][z] = rec;
		bt[x][y][z] = -1;
	}
	rec = serc(x, y + 1, z);
	if (rec > dp[x][y][z]) {
		dp[x][y][z] = rec;
		bt[x][y][z] = -2;
	}
	return dp[x][y][z];
}

int main() {
	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", virus);
	int l = strlen(virus);
	for (int i = 0; str1[i] != '\0'; i++) {
		for (int j = 0; str2[j] != '\0'; j++) {
			for (int k = 0; k < virus[k] != '\0'; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	int k = 0;
	kmp[0] = 0;
	for (int i = 1; i < l; i++) {
		while (k && virus[k] != virus[i]) k = kmp[k - 1];
		if (virus[k] == virus[i]) k++;
		kmp[i] = k;
	}
	serc(0, 0, 0);
	int x = 0;
	int y = 0;
	k = 0;
	int foun = 0;
	while (str1[x] != '\0' && str2[y] != '\0') {
		if (bt[x][y][k] >= 0) {
			foun++;
			printf("%c", str1[x]);
			k = bt[x][y][k];
			x++;
			y++;
		}
		else if (bt[x][y][k] == -1) x++;
		else y++;
	}
	if (foun == 0) printf("0");
	printf("\n");
	return 0;
}