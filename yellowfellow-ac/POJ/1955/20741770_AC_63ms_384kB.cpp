#include<stdio.h>

// 0=left, 1=front, 2=right, 3=back, 4=top, 5=bottom
// rotating the i-th face clockwise
int fx[6][4]= {
  {4, 1, 5, 3},
  {4, 2, 5, 0},
  {4, 3, 5, 1},
  {4, 0, 5, 2},
  {3, 2, 1, 0},
  {1, 2, 3, 0}
};

class cube {
 private:
  char side[6][6][3], core[6];
  void change(int f, int a, int q, char p) {
    side[f][a][q] = p;
    for (int i = 0; i < 4; i++) {
      if (fx[f][i] == a) {
        if (q == 0) side[f][fx[f][(i - 1 + 4) % 4]][2] = p;
        else if (q == 2) side[f][fx[f][(i + 1) % 4]][0] = p;
        return;
      }
    }
  }
  char assign(char p, int r, int c, int f, int mode) {
    if (r % 2 == 0 && c % 2 == 0) {
      if (mode) return side[f][fx[f][(3 + c) % 4]][r > 0 ? c : 2-c];
      side[f][fx[f][(3 + c) % 4]][r > 0 ? c : 2-c] = p;
    }
    if (r == 0) {
      if (mode) return side[f][fx[f][0]][c];
      side[f][fx[f][0]][c] = p;
    } else if (r == 1) {
      if (c == 0) {
        if (mode) return side[f][fx[f][3]][1];
        side[f][fx[f][3]][1] = p;
      } else if (c == 1) {
        if (mode) return core[f];
        core[f] = p;
      } else {
        if (mode) return side[f][fx[f][1]][1];
        side[f][fx[f][1]][1] = p;
      }
    } else {
      if (mode) return side[f][fx[f][2]][2 - c];
      side[f][fx[f][2]][2 - c] = p;
    }
    return 'k';
  }
  int getregion(int x, int y) {
    if (x < 3) return 4;
    else if (x > 5) return 5;
    else if (y < 3) return 0;
    else if (y < 6) return 1;
    else if (y < 9) return 2;
    else return 3;
  }
  char fill(char p, int x, int y) {
    assign(p, x%3, y%3, getregion(x, y), 0);
  }
  char getback(int x, int y) {
    return assign('k', x%3, y%3, getregion(x, y), 1);
  }
 public:
  void rotate(int f, int dir) {   // dir: 0=clockwise
    char tmp[3], tmp2[3];
    if (dir == 0) {
      for (int i = 0; i < 3; i++) {
        tmp[i] = side[f][fx[f][3]][i];
        tmp2[i] = side[fx[f][3]][f][i];
      }
      for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
          side[f][fx[f][i]][j] = side[f][fx[f][i - 1]][j];
          change(fx[f][i], f, j, side[fx[f][i - 1]][f][j]);
        }
      }
      for (int i = 0; i < 3; i++) {
        side[f][fx[f][0]][i] = tmp[i];
        change(fx[f][0], f, i, tmp2[i]);
      }
    } else {
      for (int i = 0; i < 3; i++) {
        tmp[i] = side[f][fx[f][0]][i];
        tmp2[i] = side[fx[f][0]][f][i];
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          side[f][fx[f][i]][j] = side[f][fx[f][i + 1]][j];
          change(fx[f][i], f, j, side[fx[f][i + 1]][f][j]);
        }
      }
      for (int i = 0; i < 3; i++) {
        side[f][fx[f][3]][i] = tmp[i];
        change(fx[f][3], f, i, tmp2[i]);
      }
    }
  }
  void scan(int mode) {
    char str[50][55][4];
    for (int i = 0; i < 9; i++) {
      int m = 3;
      if (i > 2 && i < 6) {
        m = 12;
      } else if (mode) {
        for (int j = 0; j < 3; j++) {
          printf("  ");
        }
      }
      for (int j = 0; j < m; j++) {
        if (mode == 0) {
          scanf("%s", str[i][j]);
          fill(str[i][j][0], i, j);
        } else {
          if (j) printf(" ");
          printf("%c", getback(i, j));
        }
      }
      if (mode) {
        printf("\n");
      }
    }
  }
};

int main() {
  int tc, kas = 0;
  scanf("%d", &tc);
  while (tc--) {
    cube v3;
    v3.scan(0);
    int n, x, d;
    scanf("%d", &n);
    while (n--) {
      scanf("%d %d", &x, &d);
      v3.rotate(x, d < 0);
    }
    printf("Scenario #%d:\n", ++kas);
    v3.scan(1);
    printf("\n");
  }
  return 0;
}