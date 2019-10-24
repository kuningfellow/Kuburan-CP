#include<stdio.h>
#include<queue>

using namespace std;

int main() {
  long long int a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  if (c > b) printf("Stay with this envelope\n");
  else printf("Take another envelope\n");
  return 0;
}